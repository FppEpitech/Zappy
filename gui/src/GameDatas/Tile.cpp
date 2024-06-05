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
    _position = position;
    _model = LoadModel(MODEL_TILE);
}

Gui::Tile::~Tile()
{
    UnloadModel(_model);
}

void Gui::Tile::setPosition(std::pair<std::size_t, std::size_t> position)
{
    _position = position;
}

std::pair<std::size_t, std::size_t> Gui::Tile::getPosition(void) const
{
    return _position;
}
