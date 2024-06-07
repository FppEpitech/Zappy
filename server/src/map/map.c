/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** map
*/

#include "map/map.h"
#include "stdlib.h"
#include "stdio.h"

tile_t **get_map(int width, int height)
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
            printf("\tFood: %ld\n", map[i][j].food);
            printf("\tLinemate: %ld\n", map[i][j].linemate);
            printf("\tDeraumere: %ld\n", map[i][j].deraumere);
            printf("\tSibur: %ld\n", map[i][j].sibur);
            printf("\tMendiane: %ld\n", map[i][j].mendiane);
            printf("\tPhiras: %ld\n", map[i][j].phiras);
            printf("\tThystame: %ld\n", map[i][j].thystame);
        }
    }
}
