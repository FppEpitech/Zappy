/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Test on map
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "map/map.h"

Test(map, map_create, .timeout = 5)
{
    tile_t ***new_map = get_map(10, 10);

    cr_assert_not_null(new_map);
    map_free(new_map);
}

Test(map, map_free, .timeout = 5)
{
    tile_t ***new_map = get_map(10, 10);

    cr_assert_not_null(new_map);
    map_free(new_map);
}
