/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Game struct
*/

#pragma once

#include "map/map.h"

#define END_GAME 1
#define ERROR -1
#define GAME_CONTINUE 0

typedef struct s_game {
    size_t height;
    size_t width;
    tile_t **map;
    struct timeval start;
    struct timeval start_food;
    int freq;
    int status_game;
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

/**
 * @brief Spawn ressources.
 *
 * @param app Application with ressources data.
 */
void spawn_ressources(app_t *app);

/**
 * @brief Check if a team have won.
 *
 * @param app Application with list of team.
 */
void check_win(app_t *app);

/**
 * @brief Destroy the game struct.
 *
 * @param game Game struct to destroy.
 */
void destroy_game(game_t *game);
