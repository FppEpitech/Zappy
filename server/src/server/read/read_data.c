/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Read data
*/

#include <string.h>

#include "app/app.h"
#include "server/client.h"
#include "ai/command_ai.h"

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
    char *line = malloc(sizeof(char) * 1);

    if (line == NULL)
        return NULL;
    line[0] = '\0';
    memset(buffer, 0, sizeof(buffer));
    bytes_received = read(fd, buffer, 1);
    if (bytes_received <= 0)
        return NULL;
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
        command_ai_handler(app, ai, line);
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
    if (its_client(app, fd)) {
        if (strcmp(line, "GRAPHIC") == 0)
            add_gui(app, fd);
        else
            add_ia(app, fd, line);
    } else {
        handle_request(app, fd, line);
        free(line);
    }
    return true;
}
