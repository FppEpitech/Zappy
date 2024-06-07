/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Game
*/

#include "app/app.h"

game_t *create_game(int height, int width)
{
    game_t *new_game = malloc(sizeof(game_t));

    if (new_game == NULL)
        return NULL;
    new_game->height = height;
    new_game->width = width;
    new_game->map = create_map(width, height);
    if (new_game->map == NULL)
        return NULL;
    return new_game;
}
