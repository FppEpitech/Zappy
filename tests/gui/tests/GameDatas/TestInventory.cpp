/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** test inventory
*/

#include "CriterionHeaders.hpp"
#include "GameDatas/Inventory.hpp"

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

Test(Inventory, setRessources, .timeout = 5)
{
    Gui::Inventory inventory;
    Gui::Inventory::Ressources ressources = {1, 2, 3, 4, 5, 6};

    inventory.setRessources(ressources);
    cr_assert_eq(inventory.getLinemate(), 1);
    cr_assert_eq(inventory.getDeraumere(), 2);
    cr_assert_eq(inventory.getSibur(), 3);
    cr_assert_eq(inventory.getMendiane(), 4);
    cr_assert_eq(inventory.getPhiras(), 5);
    cr_assert_eq(inventory.getThystame(), 6);
}

Test(Inventory, getRessources, .timeout = 5)
{
    Gui::Inventory inventory;
    Gui::Inventory::Ressources ressources = {1, 2, 3, 4, 5, 6};

    inventory.setRessources(ressources);
    Gui::Inventory::Ressources &ressources2 = inventory.getRessources();
    cr_assert_eq(ressources2[0], 1);
    cr_assert_eq(ressources2[1], 2);
    cr_assert_eq(ressources2[2], 3);
    cr_assert_eq(ressources2[3], 4);
    cr_assert_eq(ressources2[4], 5);
    cr_assert_eq(ressources2[5], 6);
}
