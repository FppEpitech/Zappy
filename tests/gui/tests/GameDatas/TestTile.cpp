/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** test tile
*/

#include "Assets.hpp"
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

    tile.inventory.setFood(34);
    cr_assert_eq(tile.inventory.getFood(), 34);
}

Test(Tile, constructor, .timeout = 5)
{
    Gui::Tile tile(std::pair<std::size_t, std::size_t>(1, 2), Gui::Inventory(34, 23, 12, 0, 0, 0, 0));

    cr_assert_eq(tile.inventory.getFood(), 34);
    cr_assert_eq(tile.inventory.getLinemate(), 23);
    cr_assert_eq(tile.inventory.getDeraumere(), 12);
    cr_assert_eq(tile.inventory.getSibur(), 0);
    cr_assert_eq(tile.inventory.getMendiane(), 0);
    cr_assert_eq(tile.inventory.getPhiras(), 0);
    cr_assert_eq(tile.inventory.getThystame(), 0);
}

Test(Tile, positionIn3DSpace, .timeout = 5)
{
    Gui::Tile tile(std::pair<std::size_t, std::size_t>(1, 2));

    cr_assert_eq((float)tile.getPositionIn3DSpace().x, (float)(1 * SIZE_TILE));
    cr_assert_eq(tile.getPositionIn3DSpace().y, 0.0f);
    cr_assert_eq((float)tile.getPositionIn3DSpace().z, (float)(2 * SIZE_TILE));
}
