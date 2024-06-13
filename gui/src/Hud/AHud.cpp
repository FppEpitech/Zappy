/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** AHud
*/

#include "Hud/AHud.hpp"

void Gui::AHud::setPlayer(std::shared_ptr<Player> player)
{
    _player = player;
}

void Gui::AHud::setTile(std::shared_ptr<Tile> tile)
{
    _tile = tile;
}

Gui::AHud::TypeScene Gui::AHud::getType() const
{
    return _typeScene;
}
