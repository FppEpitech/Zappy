/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** map
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

#define FOOD_DENSITY 0.5
#define LINEMATE_DENSITY 0.3
#define DERAUMERE_DENSITY 0.15
#define SIBUR_DENSITY 0.1
#define MENDIANE_DENSITY 0.1
#define PHIRAS_DENSITY 0.08
#define THYSTAME_DENSITY 0.05

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
    size_t food;
    size_t linemate;
    size_t deraumere;
    size_t sibur;
    size_t mendiane;
    size_t phiras;
    size_t thystame;
} tile_t;

/**
 * @brief Create the map objec.
 *
 * @param width Width of the map.
 * @param height Height of the map.
 * @return tile_t** Map of tile.
 */
tile_t **create_map(int width, int height);

/**
 * @brief Free the map of tiles.
 *
 * @param map Map to free.
 * @param height Number of tab to free.
 */
void free_map(tile_t **map, int height);

/**
 * @brief Display the maps of tile with the content.
 *
 * @param map Map to display.
 * @param height Height of the map.
 * @param width Width of the map.
 */
void display_map(tile_t **map, int height, int width);

/**
 * @brief Distribute resources on the map.
 *
 * @param map Map where distribute resources.
 * @param width Width of the map.
 * @param height Height of the map.
 */
void distribute_resources(tile_t **map, int width, int height);
