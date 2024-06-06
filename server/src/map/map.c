/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** map
*/

#include "map/map.h"
#include "stdlib.h"
#include "stdio.h"

tile_t ***get_map(int width, int height)
{
    tile_t ***map = malloc(sizeof(tile_t **) * height);

    for (int i = 0; i < height; i++) {
        map[i] = malloc(sizeof(tile_t *) * width);
        for (int j = 0; j < width; j++) {
            map[i][j] = malloc(sizeof(tile_t));
            map[i][j]->deraumere = 0;
            map[i][j]->food = 0;
            map[i][j]->linemate = 0;
            map[i][j]->mendiane = 0;
            map[i][j]->phiras = 0;
            map[i][j]->sibur = 0;
            map[i][j]->thystame = 0;
        }
    }
    return map;
}

void free_map(tile_t ***map, int height, int width)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            free(map[i][j]);
        }
        free(map[i]);
    }
    free(map);
}

void display_map(tile_t ***map, int height, int width)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("[%d %d]:\n", i, j);
            printf("\tFood: %d\n", map[i][j]->food);
            printf("\tLinemate: %d\n", map[i][j]->linemate);
            printf("\tDeraumere: %d\n", map[i][j]->deraumere);
            printf("\tSibur: %d\n", map[i][j]->sibur);
            printf("\tMendiane: %d\n", map[i][j]->mendiane);
            printf("\tPhiras: %d\n", map[i][j]->phiras);
            printf("\tThystame: %d\n", map[i][j]->thystame);
        }
    }
}
