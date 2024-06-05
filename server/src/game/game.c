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
    return new_game;
}
