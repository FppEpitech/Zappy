/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Game
*/

#include "app/app.h"

double time_elapsed(struct timeval time)
{
    struct timeval end;
    double seconds = 0.0;
    double microseconds = 0.0;

    gettimeofday(&end, NULL);
    seconds = (end.tv_sec - time.tv_sec);
    microseconds = (end.tv_usec - time.tv_usec) / 1000000.0;
    return seconds + microseconds;
}

game_t *create_game(int height, int width)
{
    game_t *new_game = malloc(sizeof(game_t));

    if (new_game == NULL)
        return NULL;
    new_game->height = height;
    new_game->width = width;
    new_game->map = create_map(width, height);
    gettimeofday(&new_game->start, NULL);
    if (new_game->map == NULL)
        return NULL;
    return new_game;
}
