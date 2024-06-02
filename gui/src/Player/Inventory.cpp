/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Inventory
*/

#include "Player/Inventory.hpp"

Gui::Inventory::Inventory()
{
    _food = 0;
    _linemate = 0;
    _deraumere = 0;
    _sibur = 0;
    _mendiane = 0;
    _phiras = 0;
    _thystame = 0;
}

void Gui::Inventory::setFood(std::size_t food)
{
    _food = food;
}

void Gui::Inventory::setLinemate(std::size_t linemate)
{
    _linemate = linemate;
}

void Gui::Inventory::setDeraumere(std::size_t deraumere)
{
    _deraumere = deraumere;
}

void Gui::Inventory::setSibur(std::size_t sibur)
{
    _sibur = sibur;
}

void Gui::Inventory::setMendiane(std::size_t mendiane)
{
    _mendiane = mendiane;
}

void Gui::Inventory::setPhiras(std::size_t phiras)
{
    _phiras = phiras;
}

void Gui::Inventory::setThystame(std::size_t thystame)
{
    _thystame = thystame;
}

std::size_t Gui::Inventory::getFood(void)
{
    return _food;
}

std::size_t Gui::Inventory::getLinemate(void)
{
    return _linemate;
}

std::size_t Gui::Inventory::getDeraumere(void)
{
    return _deraumere;
}

std::size_t Gui::Inventory::getSibur(void)
{
    return _sibur;
}

std::size_t Gui::Inventory::getMendiane(void)
{
    return _mendiane;
}

std::size_t Gui::Inventory::getPhiras(void)
{
    return _phiras;
}

std::size_t Gui::Inventory::getThystame(void)
{
    return _thystame;
}
