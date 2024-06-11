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

Gui::AHud::TypeScene Gui::AHud::getType()
{
    return _typeScene;
}
