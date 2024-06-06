/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** map
*/

#pragma once

#include <stdbool.h>

/**
* @brief Enum for the different types of entities.
*/
enum entity_type_e {
    EGG,
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    NONE
};

/**
* @brief Struct for a map's tile.
*/
typedef struct tile_s {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} tile_t;

/**
* @brief Get the map object.
*
* @param width
* @param height
* @return tile_t***
*/
tile_t ***get_map(int width, int height);

/**
* @brief Get the tile object.
*
* @param map
* @param height
* @param width
*/
void free_map(tile_t ***map, int height, int width);

/**
* @brief Display the map object.
*
* @param map
* @param height
* @param width
*/
void display_map(tile_t ***map, int height, int width);
