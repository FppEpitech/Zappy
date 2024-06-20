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
        handle_command_gui(gui, app, line);
        return;
    }
    if (ai != NULL) {
        if (ai->list_command->len >= 10)
            return;
        line[strlen(line) - 1] = '\0';
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
    if (its_client(app, fd)) {
        if (strcmp(line, "GRAPHIC") == 0)
            add_gui(app, fd, line);
        else
            add_ia(app, fd, line);
    } else {
        if (strcmp("team\r", line) == 0) {
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
            return true;
        }
 
        if (strcmp("gui\r", line) == 0) {
            list_node_t *temp = app->gui_list->first;
            gui_t *gui = NULL;
 
            while (temp) {
                gui = temp->data.gui;
                printf("FD GUI: [%ld]\n", gui->fd);
                temp = temp->next;
            }
            printf("\n\n");
            return true;
        }
 
        if (strcmp("client\r", line) == 0) {
            list_node_t *temp = app->clients_list->first;
            client_t *client = NULL;
 
            while (temp) {
                client = temp->data.client;
                printf("FD client: [%ld]\n", client->fd);
                temp = temp->next;
            }
            printf("\n\n");
            return true;
        }
 
        if (strcmp("pos\r", line) == 0) {
            ia_t *ai = find_ia(app, fd);
            printf("AI POS X: [%d]\n", ai->position->x);
            printf("AI POS Y: [%d]\n", ai->position->y);
            return true;
        }
 
        if (strcmp("orientation\r", line) == 0) {
            ia_t *ai = find_ia(app, fd);
            if (ai->direction == NORTH)
                printf("AI Direction: [NORTH]\n");
            if (ai->direction == SOUTH)
                printf("AI Direction: [SOUTH]\n");
            if (ai->direction == EAST)
                printf("AI Direction: [EAST]\n");
            if (ai->direction == WEST)
                printf("AI Direction: [WEST]\n");
            return true;
        }
 
        if (strcmp("level_up\r", line) == 0) {
            ia_t *ai = find_ia(app, fd);
            ai->level++;
            return true;
        }
 
        if (strcmp("egg\r", line) == 0) {
            list_node_t *temp = app->teams_list->first;
            team_t *team = NULL;
            list_node_t *egg_temp = NULL;
 
            printf("\nEgg Position:\n");
            while (temp) {
                team = temp->data.team;
                printf("\tTeam name: [%s]\n", team->name);
                egg_temp = team->eggs_list->first;
                while (egg_temp) {
                    printf("\t\tEgg in: [%d] | [%d]\n",
                    egg_temp->data.egg->pos->x, egg_temp->data.egg->pos->y);
                    egg_temp = egg_temp->next;
                }
                printf("\n");
                temp = temp->next;
            }
            return true;
        }
        if (strcmp("map\r", line) == 0) {
            display_map(app->game->map, app->game->height, app->game->width);
            return true;
        }
 
        if (strcmp("level\r", line) == 0) {
            ia_t *ai = find_ia(app, fd);
            printf("\nLevel: [%ld]\n", ai->level);
            return true;
        }
        if (strcmp("stuck\r", line) == 0) {
            ia_t *ai = find_ia(app, fd);
            if (ai->time->stuck)
                printf("\nstuck time: [%f] | [%f] : total to reach\n", time_elapsed(&ai->time->start_stuck), ai->time->total_stuck);
            else
                printf("Not stuck\n");
            return true;
        }
        if (strcmp("time\r", line) == 0) {
            printf("\nTime: [%f]\n", time_elapsed(&app->game->start));
            return true;
        }
        if (strcmp("life\r", line) == 0) {
            ia_t *ai = find_ia(app, fd);
            printf("\nLife during: [%f] | [%f] : life to reach\n", time_elapsed(&ai->time->start_life), ai->time->total_life);
            return true;
        }
        if (strcmp("ressource\r", line) == 0) {
            size_t *resource_still = malloc(sizeof(size_t) * 7);
 
            for (int index = 0; index < 7; index++)
                resource_still[index] = 0;
            for (size_t index_y = 0; index_y < app->game->height; index_y++) {
                for (size_t index_x = 0; index_x < app->game->width; index_x++) {
                    resource_still[0] += app->game->map[index_y][index_x].food;
                    resource_still[1] += app->game->map[index_y][index_x].linemate;
                    resource_still[2] += app->game->map[index_y][index_x].deraumere;
                    resource_still[3] += app->game->map[index_y][index_x].sibur;
                    resource_still[4] += app->game->map[index_y][index_x].mendiane;
                    resource_still[5] += app->game->map[index_y][index_x].phiras;
                    resource_still[6] += app->game->map[index_y][index_x].thystame;
                }
            }
            printf("\nfood: [%ld]\n", resource_still[0]);
            printf("linemate: [%ld]\n", resource_still[1]);
            printf("deraumere: [%ld]\n", resource_still[2]);
            printf("sibur: [%ld]\n", resource_still[3]);
            printf("mendiane: [%ld]\n", resource_still[4]);
            printf("phiras: [%ld]\n", resource_still[5]);
            printf("thystame: [%ld]\n\n", resource_still[6]);
            return true;
        }
        handle_request(app, fd, line);
        free(line);
    }
    return true;
}
