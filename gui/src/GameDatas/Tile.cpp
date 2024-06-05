/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Tile
*/

#include "Assets.hpp"
#include "GameDatas/Tile.hpp"

Gui::Tile::Tile(std::pair<std::size_t, std::size_t> position)
{
    setPosition(position);
}

void Gui::Tile::setPosition(std::pair<std::size_t, std::size_t> position)
{
    _position = position;
    _positionIn3DSpace = (Vector3) {(float)(position.first * SIZE_TILE), 0.0f, (float)(position.second * SIZE_TILE)};
}

std::pair<std::size_t, std::size_t> Gui::Tile::getPosition(void) const
{
    return _position;
}

Vector3 Gui::Tile::getPositionIn3DSpace(void)
{
    return _positionIn3DSpace;
}
