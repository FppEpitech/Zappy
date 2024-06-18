/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI stuck
*/

#include "app/app.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"
#include "gui/communication.h"

void set_time_stuck(ia_t *ai, double total_stuck)
{
    ai->time->stuck = true;
    gettimeofday(&ai->time->start_stuck, NULL);
    ai->time->total_stuck = total_stuck;
}

double time_elapsed(struct timeval *time)
{
    struct timeval end;
    double seconds = 0.0;
    double microseconds = 0.0;

    gettimeofday(&end, NULL);
    seconds = (end.tv_sec - time->tv_sec);
    microseconds = (end.tv_usec - time->tv_usec) / 1000000.0;
    return seconds + microseconds;
}

static void handle_incantation_verification(ia_t *ai, app_t *app)
{
    list_t *list_ai = NULL;
    char *result = NULL;

    if (ai->incantation->status_incantation == false)
        return;
    list_ai = check_incantation(app, ai, END_INCANTATION);
    if (list_ai == NULL) {
        printf("FAILD at end verification\n");
        update_status(app, ai, END_INCANTATION);
        result = format_string("ko\n");
        add_message(ai->list_messages, result);
        return;
    }
    pie_command(app, list_ai);
    printf("SUCCESS at end verification\n");
    level_up(app, ai);
    result = format_string("Current level: %d\n", ai->level);
    add_message(ai->list_messages, result);
    printf("Level up succefully\n");
}

static void handle_fork_verification(ia_t *ai, app_t *app)
{
    list_node_t *egg_node = app->eggs_list->first;

    while (egg_node) {
        if (egg_node->data.egg->id_player_laid == ai->fd) {
            printf("SUCCESS at end verification, player id : %ld\n", ai->fd);
            printf("player_laid : %ld\n", egg_node->data.egg->id_player_laid);
            enw_command(app, egg_node->data.egg, NULL);
            return;
        }
        egg_node = egg_node->next;
    }
}

static void check_statut_stuck(ia_t *ai, app_t *app)
{
    if (ai->time->stuck == false)
        return;
    if (time_elapsed(&ai->time->start_stuck) >= ai->time->total_stuck) {
        ai->time->stuck = false;
        ai->time->total_stuck = 0.0;
        handle_incantation_verification(ai, app);
        handle_fork_verification(ai, app);
    }
}

void treat_stuck(app_t *app)
{
    list_node_t *temp_team = app->teams_list->first;
    team_t *team = NULL;
    list_node_t *ia_temp = NULL;

    while (temp_team) {
        team = temp_team->data.team;
        ia_temp = team->list_ai->first;
        while (ia_temp) {
            check_statut_stuck(ia_temp->data.ai, app);
            ia_temp = ia_temp->next;
        }
        temp_team = temp_team->next;
    }
}
