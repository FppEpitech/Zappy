/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** test tile
*/

#include "GameDatas/Tile.hpp"
#include "CriterionHeaders.hpp"

Test(Tile, position, .timeout = 5)
{
    Gui::Tile tile(std::pair<std::size_t, std::size_t>(1, 2));

    cr_assert_eq(tile.getPosition().first, 1);
    cr_assert_eq(tile.getPosition().second, 2);

    tile.setPosition(std::pair<std::size_t, std::size_t>(3, 4));
    cr_assert_eq(tile.getPosition().first, 3);
    cr_assert_eq(tile.getPosition().second, 4);
}

Test(Tile, inventory, .timeout = 5)
{
    Gui::Tile tile(std::pair<std::size_t, std::size_t>(1, 2));

    tile._inventory.setFood(34);
    cr_assert_eq(tile._inventory.getFood(), 34);
}
