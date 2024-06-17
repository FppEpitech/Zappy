/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Read data
*/

#include <string.h>

#include "app/app.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

void concatenate_strings(char **str1, char *str2)
{
    size_t len1 = strlen(*str1);
    size_t len2 = strlen(str2);
    char *result = realloc(*str1, len1 + len2 + 1);

    if (result == NULL)
        return;
    *str1 = result;
    strcat(*str1, str2);
}

char *append_char(char *line, char current_char)
{
    int len_line = 0;

    len_line = strlen(line);
    line = realloc(line, len_line + 2);
    if (line == NULL)
        return NULL;
    line[len_line] = current_char;
    line[len_line + 1] = '\0';
    return line;
}

char *read_line(int fd)
{
    char buffer[1024];
    ssize_t bytes_received;
    char *line = calloc(1, sizeof(char));

    if (line == NULL)
        return NULL;
    memset(buffer, 0, sizeof(buffer));
    bytes_received = read(fd, buffer, 1);
    if (bytes_received <= 0) {
        free(line);
        return NULL;
    }
    while (bytes_received > 0) {
        if (buffer[0] == '\n')
            break;
        line = append_char(line, buffer[0]);
        memset(buffer, 0, sizeof(buffer));
        bytes_received = read(fd, buffer, 1);
    }
    return line;
}

void handle_request(app_t *app, size_t fd, char *line)
{
    gui_t *gui = find_gui(app, fd);
    ia_t *ai = find_ia(app, fd);

    if (gui != NULL) {
        if (gui->list_messages->len >= 10)
            return;
        (void) line;
        return;
    }
    if (ai != NULL) {
        if (ai->list_messages->len >= 10)
            return;
        add_command_to_list(ai, strdup(line));
        return;
    }
}

bool server_data_handler(app_t *app, size_t fd)
{
    char *line = read_line(fd);

    if (line == NULL) {
        server_quit_handler(app, fd);
        printf("QUIT\n");
        return true;
    }
    line[strlen(line) - 1] = '\0';
    if (its_client(app, fd)) {
        if (strcmp(line, "GRAPHIC") == 0)
            add_gui(app, fd, line);
        else
            add_ia(app, fd, line);
    } else {
        handle_request(app, fd, line);
        free(line);
    }
    return true;
}
