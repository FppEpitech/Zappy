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

void concatenate_strings(char **str1, char *str2) {
    size_t len1 = strlen(*str1);
    size_t len2 = strlen(str2);
    char* result = realloc(*str1, len1 + len2 + 1);

    if (result == NULL) {
        return;
    }
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
    line[strlen(line) - 1] = '\0';
    if (its_client(app, fd)) {
        if (strcmp(line, "GRAPHIC") == 0)
            add_gui(app, fd);
        else
            add_ia(app, fd, line);
    } else {
        if (strcmp("team", line) == 0) {
            list_node_t *temp = app->teams_list->first;
            team_t *team = NULL;
 
            while (temp) {
                team = temp->data.team;
                list_node_t *ia_temp = team->list_ai->first;
                printf("Name of the team: [%s]\n", team->name);
                while (ia_temp) {
                    printf("fd: [%ld]\n", ia_temp->data.ai->fd);
                    ia_temp = ia_temp->next;
                }
                printf("\n\n");
                temp = temp->next;
            }
        }
 
        if (strcmp("gui", line) == 0) {
            list_node_t *temp = app->gui_list->first;
            gui_t *gui = NULL;
 
            while (temp) {
                gui = temp->data.gui;
                printf("FD GUI: [%ld]\n", gui->fd);
                temp = temp->next;
            }
            printf("\n\n");
        }
 
        if (strcmp("client", line) == 0) {
            list_node_t *temp = app->clients_list->first;
            client_t *client = NULL;
 
            while (temp) {
                client = temp->data.client;
                printf("FD client: [%ld]\n", client->fd);
                temp = temp->next;
            }
            printf("\n\n");
        }
 
        if (strcmp("pos", line) == 0) {
            ia_t *ai = find_ia(app, fd);
            printf("AI POS X: [%d]\n", ai->position->x);
            printf("AI POS Y: [%d]\n", ai->position->y);
        }
 
        if (strcmp("orientation", line) == 0) {
            ia_t *ai = find_ia(app, fd);
            if (ai->direction == NORTH)
                printf("AI Direction: [NORTH]\n");
            if (ai->direction == SOUTH)
                printf("AI Direction: [SOUTH]\n");
            if (ai->direction == EAST)
                printf("AI Direction: [EAST]\n");
            if (ai->direction == WEST)
                printf("AI Direction: [WEST]\n");
        }

        if (strcmp("level_up", line) == 0) {
            ia_t *ai = find_ia(app, fd);
            ai->level++;
        }

        if (strcmp("egg", line) == 0) {
            display_egg_position(app);
        }
        handle_request(app, fd, line);
        free(line);
    }
    return true;
}
