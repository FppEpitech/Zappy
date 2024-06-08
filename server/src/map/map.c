/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** map
*/

#include "stdio.h"
#include "stdlib.h"
#include "map/map.h"

static void incremente_ressources(size_t index_entity, tile_t **map,
    int x, int y)
{
    if (index_entity == 0)
        map[x][y].food++;
    if (index_entity == 1)
        map[x][y].linemate++;
    if (index_entity == 2)
        map[x][y].deraumere++;
    if (index_entity == 3)
        map[x][y].sibur++;
    if (index_entity == 4)
        map[x][y].mendiane++;
    if (index_entity == 5)
        map[x][y].phiras++;
    if (index_entity == 6)
        map[x][y].thystame++;
}

void distribute_resources(tile_t **map, int width, int height)
{
    size_t total_tiles = width * height;
    size_t total_food = (size_t)(total_tiles * FOOD_DENSITY);
    size_t total_linemate = (size_t)(total_tiles * LINEMATE_DENSITY);
    size_t total_deraumere = (size_t)(total_tiles * DERAUMERE_DENSITY);
    size_t total_sibur = (size_t)(total_tiles * SIBUR_DENSITY);
    size_t total_mendiane = (size_t)(total_tiles * MENDIANE_DENSITY);
    size_t total_phiras = (size_t)(total_tiles * PHIRAS_DENSITY);
    size_t total_thystame = (size_t)(total_tiles * THYSTAME_DENSITY);
    size_t resources[] = {total_food, total_linemate, total_deraumere,
    total_sibur, total_mendiane, total_phiras, total_thystame};

    for (size_t index_entity = 0; index_entity < 7; index_entity++) {
        for (size_t nb = 0; nb < resources[index_entity]; nb++) {
            incremente_ressources(index_entity, map, rand() % height,
            rand() % width);
        }
    }
}

tile_t **create_map(int width, int height)
{
    tile_t **map = malloc(sizeof(tile_t *) * height);

    if (map == NULL)
        return NULL;
    for (int i = 0; i < height; i++) {
        map[i] = malloc(sizeof(tile_t) * width);
        if (map[i] == NULL)
            return NULL;
        for (int j = 0; j < width; j++) {
            map[i][j].food = 0;
            map[i][j].linemate = 0;
            map[i][j].deraumere = 0;
            map[i][j].sibur = 0;
            map[i][j].mendiane = 0;
            map[i][j].phiras = 0;
            map[i][j].thystame = 0;
        }
    }
    distribute_resources(map, width, height);
    return map;
}

void free_map(tile_t **map, int height)
{
    for (int index = 0; index < height; index++) {
        free(map[index]);
    }
    free(map);
}

void display_map(tile_t **map, int height, int width)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("[%d %d]:\n", i, j);
            printf("\tFood: %ld\n", map[j][i].food);
            printf("\tLinemate: %ld\n", map[j][i].linemate);
            printf("\tDeraumere: %ld\n", map[j][i].deraumere);
            printf("\tSibur: %ld\n", map[j][i].sibur);
            printf("\tMendiane: %ld\n", map[j][i].mendiane);
            printf("\tPhiras: %ld\n", map[j][i].phiras);
            printf("\tThystame: %ld\n", map[j][i].thystame);
        }
    }
}
