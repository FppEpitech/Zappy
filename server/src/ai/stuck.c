/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI stuck
*/

#include "app/app.h"
#include "server/client.h"

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

static void check_statut_stuck(ia_t *ai)
{
    if (ai->time->stuck == false)
        return;
    if (time_elapsed(&ai->time->start_stuck) >= ai->time->total_stuck) {
        ai->time->stuck = false;
        ai->time->total_stuck = 0.0;
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
            check_statut_stuck(ia_temp->data.ai);
            ia_temp = ia_temp->next;
        }
        temp_team = temp_team->next;
    }
}
