/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Inventory
*/

#include "GameDatas/Inventory.hpp"

Gui::Inventory::Inventory()
{
    _food = 0;
    for (size_t i = 0; i < RessourcesNumber; i++)
        _ressources[i] = 0;
}

Gui::Inventory::Inventory(std::size_t food, std::size_t linemate, std::size_t deraumere, std::size_t sibur, std::size_t mendiane, std::size_t phiras, std::size_t thystame) : _food(food), _ressources{linemate, deraumere, sibur, mendiane, phiras, thystame} {}

void Gui::Inventory::setFood(std::size_t food)
{
    _food = food;
}

void Gui::Inventory::setLinemate(std::size_t linemate)
{
    _ressources[0] = linemate;
}

void Gui::Inventory::setDeraumere(std::size_t deraumere)
{
    _ressources[1] = deraumere;
}

void Gui::Inventory::setSibur(std::size_t sibur)
{
    _ressources[2] = sibur;
}

void Gui::Inventory::setMendiane(std::size_t mendiane)
{
    _ressources[3] = mendiane;
}

void Gui::Inventory::setPhiras(std::size_t phiras)
{
    _ressources[4] = phiras;
}

void Gui::Inventory::setThystame(std::size_t thystame)
{
    _ressources[5] = thystame;
}

void Gui::Inventory::setRessources(Ressources ressources)
{
    for (size_t i = 0; i < RessourcesNumber; i++)
        _ressources[i] = ressources[i];
}

std::size_t Gui::Inventory::getFood(void)
{
    return _food;
}

std::size_t Gui::Inventory::getLinemate(void)
{
    return _ressources[0];
}

std::size_t Gui::Inventory::getDeraumere(void)
{
    return _ressources[1];
}

std::size_t Gui::Inventory::getSibur(void)
{
    return _ressources[2];
}

std::size_t Gui::Inventory::getMendiane(void)
{
    return _ressources[3];
}

std::size_t Gui::Inventory::getPhiras(void)
{
    return _ressources[4];
}

std::size_t Gui::Inventory::getThystame(void)
{
    return _ressources[5];
}

Gui::Inventory::Ressources &Gui::Inventory::getRessources(void)
{
    return _ressources;
}
