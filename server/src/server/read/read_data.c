/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Read data
*/

#include <string.h>

#include "app/app.h"
#include "server/client.h"
#include "gui/communication.h"
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
        add_command_to_gui_list(gui, strdup(line));
        return;
    }
    if (ai != NULL) {
        if (ai->list_command->len >= 10)
            return;
        add_command_to_ai_list(ai, strdup(line));
        return;
    }
}

static void client_handler(app_t *app, size_t fd, char *line)
{
    list_node_t *client = NULL;

    if (strcmp(line, "GRAPHIC") == 0) {
        add_gui(app, fd, line);
        return;
    }
    if (add_ia(app, fd, line) == false) {
        client = find_client(app->clients_list, fd);
        free(client->data.client);
        list_delete(app->clients_list, client);
        close(fd);
    }
    free(line);
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
        client_handler(app, fd, line);
    } else {
          if (strcmp("buffer", line) == 0) {

            list_node_t *tmp_message = app->gui_list->first->data.gui->list_messages->first;
            printf("Message GUI:\n");
            while (tmp_message) {
                printf("message: [%s]\n", tmp_message->data.message);
                tmp_message = tmp_message->next;
            }
            printf("\n");
            return true;
        }
        handle_request(app, fd, line);
        free(line);
    }
    return true;
}
