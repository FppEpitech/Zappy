/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Test on map
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "map/map.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

Test(map, map_create, .timeout = 5)
{
    tile_t **new_map = get_map(10, 15);

    cr_assert_not_null(new_map);
    cr_assert_eq(new_map[0][0].deraumere, 0);
    cr_assert_eq(new_map[0][0].food, 0);
    cr_assert_eq(new_map[0][0].linemate, 0);
    cr_assert_eq(new_map[0][0].mendiane, 0);
    cr_assert_eq(new_map[0][0].phiras, 0);
    cr_assert_eq(new_map[0][0].sibur, 0);
    cr_assert_eq(new_map[0][0].thystame, 0);
    free_map(new_map, 15);
}

Test(map, change_mendiane, .timeout = 5)
{
    tile_t **new_map = get_map(10, 15);

    new_map[0][0].mendiane = 1;

    cr_assert_not_null(new_map);
    cr_assert_eq(new_map[0][0].deraumere, 0);
    cr_assert_eq(new_map[0][0].food, 0);
    cr_assert_eq(new_map[0][0].linemate, 0);
    cr_assert_eq(new_map[0][0].mendiane, 1);
    cr_assert_eq(new_map[0][0].phiras, 0);
    cr_assert_eq(new_map[0][0].sibur, 0);
    cr_assert_eq(new_map[0][0].thystame, 0);
    free_map(new_map, 15);
}

Test(map, display_map, .init = redirect_all_stdout)
{
    int width = 2, height = 2;
    tile_t **new_map = get_map(width, height);

    new_map[0][0].food = 1;
    new_map[0][1].food = 2;
    new_map[1][0].food = 3;
    new_map[1][1].food = 4;

    display_map(new_map, 2, 2);
    free_map(new_map, height);
}

Test(map, free_map, .timeout = 5)
{
    tile_t **new_map = get_map(10, 15);

    cr_assert_not_null(new_map);
    free_map(new_map, 15);
}
