/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Game struct
*/

#pragma once

#include "map/map.h"

typedef struct s_game {
    size_t height;
    size_t width;
    tile_t **map;
    struct timeval start;
    int freq;
} game_t;

/**
 * @brief Create a game object.
 *
 * @param height Height of the map.
 * @param width Width of the map.
 * @param freq Frequency of game.
 * @return game_t* Game initialized.
 */
game_t *create_game(int height, int width, int freq);
