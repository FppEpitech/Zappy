/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Game
*/

#include "app/app.h"

void spawn_ressources(app_t *app)
{
    if (time_elapsed(&app->game->start_food) >= (20.0 / app->game->freq)) {
        distribute_resources(app->game->map,
        app->game->width, app->game->height);
        gettimeofday(&app->game->start_food, NULL);
    }
}

game_t *create_game(int height, int width, int freq)
{
    game_t *new_game = malloc(sizeof(game_t));

    if (new_game == NULL)
        return NULL;
    new_game->height = height;
    new_game->width = width;
    new_game->freq = freq;
    new_game->map = create_map(width, height);
    gettimeofday(&new_game->start, NULL);
    gettimeofday(&new_game->start_food, NULL);
    if (new_game->map == NULL)
        return NULL;
    return new_game;
}

void destroy_game(game_t *game)
{
    for (size_t index_y = 0; index_y < game->height; index_y++)
        free(game->map[index_y]);
    free(game->map);
    free(game);
}
