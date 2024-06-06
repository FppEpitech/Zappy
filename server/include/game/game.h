/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Game struct
*/

#pragma once

typedef struct s_game {
    int height;
    int width;
} game_t;

/**
 * @brief Create a game object.
 *
 * @param height Height of the map.
 * @param width Width of the map.
 * @return game_t* Game initialized.
 */
game_t *create_game(int height, int width);
