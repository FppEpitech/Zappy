/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Game struct
*/

#pragma once

#include <sys/time.h>

#include "map/map.h"

typedef struct s_game {
    size_t height;
    size_t width;
    tile_t **map;
    struct timeval start;
} game_t;

/**
 * @brief Create a game object.
 *
 * @param height Height of the map.
 * @param width Width of the map.
 * @return game_t* Game initialized.
 */
game_t *create_game(int height, int width);

/**
 * @brief Calcul time elapsed whereas time parameter.
 *
 * @param time Time of depart.
 * @return double Time.
 */
double time_elapsed(struct timeval time);
