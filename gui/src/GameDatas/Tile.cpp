/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Tile
*/

#include "GameDatas/Tile.hpp"

Gui::Tile::Tile(std::pair<std::size_t, std::size_t> position)
{
    _position = position;
}

void Gui::Tile::setPosition(std::pair<std::size_t, std::size_t> position)
{
    _position = position;
}

std::pair<std::size_t, std::size_t> Gui::Tile::getPosition(void) const
{
    return _position;
}
