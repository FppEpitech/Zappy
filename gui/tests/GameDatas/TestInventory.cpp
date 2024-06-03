/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** test inventory
*/

#include "GameDatas/Inventory.hpp"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Inventory, Food, .timeout = 5)
{
    Gui::Inventory inventory;

    cr_assert_eq(inventory.getFood(), 0);
    inventory.setFood(54);
    cr_assert_eq(inventory.getFood(), 54);
}

Test(Inventory, Linemate, .timeout = 5)
{
    Gui::Inventory inventory;

    cr_assert_eq(inventory.getLinemate(), 0);
    inventory.setLinemate(54);
    cr_assert_eq(inventory.getLinemate(), 54);
}

Test(Inventory, Deraumere, .timeout = 5)
{
    Gui::Inventory inventory;

    cr_assert_eq(inventory.getDeraumere(), 0);
    inventory.setDeraumere(54);
    cr_assert_eq(inventory.getDeraumere(), 54);
}

Test(Inventory, Sibur, .timeout = 5)
{
    Gui::Inventory inventory;

    cr_assert_eq(inventory.getSibur(), 0);
    inventory.setSibur(54);
    cr_assert_eq(inventory.getSibur(), 54);
}

Test(Inventory, Mendiane, .timeout = 5)
{
    Gui::Inventory inventory;

    cr_assert_eq(inventory.getMendiane(), 0);
    inventory.setMendiane(54);
    cr_assert_eq(inventory.getMendiane(), 54);
}

Test(Inventory, Phiras, .timeout = 5)
{
    Gui::Inventory inventory;

    cr_assert_eq(inventory.getPhiras(), 0);
    inventory.setPhiras(54);
    cr_assert_eq(inventory.getPhiras(), 54);
}

Test(Inventory, Thystame, .timeout = 5)
{
    Gui::Inventory inventory;

    cr_assert_eq(inventory.getThystame(), 0);
    inventory.setThystame(54);
    cr_assert_eq(inventory.getThystame(), 54);
}
