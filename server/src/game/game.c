/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Game
*/

#include "utils.h"
#include "app/app.h"
#include "gui/communication.h"

static void add_ressources(size_t index_entity, tile_t **map,
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

static size_t *check_ressources_still_on_map(tile_t **map,
    size_t height, size_t width)
{
    size_t *resource_still = malloc(sizeof(size_t) * 7);

    for (int index = 0; index < 7; index++)
        resource_still[index] = 0;
    for (size_t index_y = 0; index_y < height; index_y++) {
        for (size_t index_x = 0; index_x < width; index_x++) {
            resource_still[0] += map[index_y][index_x].food;
            resource_still[1] += map[index_y][index_x].linemate;
            resource_still[2] += map[index_y][index_x].deraumere;
            resource_still[3] += map[index_y][index_x].sibur;
            resource_still[4] += map[index_y][index_x].mendiane;
            resource_still[5] += map[index_y][index_x].phiras;
            resource_still[6] += map[index_y][index_x].thystame;
        }
    }
    return resource_still;
}

static void fill_ressources(app_t *app)
{
    size_t total_tiles = app->game->width * app->game->height;
    size_t total_food = (size_t)(total_tiles * FOOD_DENSITY);
    size_t total_linemate = (size_t)(total_tiles * LINEMATE_DENSITY);
    size_t total_deraumere = (size_t)(total_tiles * DERAUMERE_DENSITY);
    size_t total_sibur = (size_t)(total_tiles * SIBUR_DENSITY);
    size_t total_mendiane = (size_t)(total_tiles * MENDIANE_DENSITY);
    size_t total_phiras = (size_t)(total_tiles * PHIRAS_DENSITY);
    size_t total_thystame = (size_t)(total_tiles * THYSTAME_DENSITY);
    size_t resources[] = {total_food, total_linemate, total_deraumere,
    total_sibur, total_mendiane, total_phiras, total_thystame};
    size_t *resource_still = check_ressources_still_on_map(app->game->map,
    app->game->height, app->game->width);

    for (size_t i_e = 0; i_e < 7; i_e++) {
        for (size_t nb = resource_still[i_e]; nb < resources[i_e]; nb++) {
            add_ressources(i_e, app->game->map,
            rand() % app->game->height, rand() % app->game->width);
        }
    }
    free(resource_still);
}

void spawn_ressources(app_t *app)
{
    if (time_elapsed(&app->game->start_food) >= (20.0 / app->game->freq)) {
        fill_ressources(app);
        gettimeofday(&app->game->start_food, NULL);
        send_mct(app);
    }
}

game_t *create_game(int height, int width, int freq)
{
    game_t *new_game = malloc(sizeof(game_t));

    if (new_game == NULL)
        return NULL;
    new_game->height = height;
    new_game->width = width;
    new_game->freq = freq;
    new_game->status_game = GAME_CONTINUE;
    new_game->map = create_map(width, height);
    gettimeofday(&new_game->start, NULL);
    gettimeofday(&new_game->start_food, NULL);
    if (new_game->map == NULL)
        return NULL;
    return new_game;
}

void destroy_game(game_t *game)
{
    for (size_t index_y = 0; index_y < game->height; index_y++)
        free(game->map[index_y]);
    free(game->map);
    free(game);
}
