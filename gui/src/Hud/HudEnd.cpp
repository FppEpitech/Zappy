/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** HudEnd
*/

#include "Assets.hpp"
#include "Hud/HudEnd.hpp"

Gui::HudEnd::HudEnd(std::shared_ptr<GameData> gameData)
{
    _typeScene = END;
    _gameData = gameData;
    _texture = LoadTexture(PNG_HUD);
    _font = LoadFont(FONT_HUD);
    _playerTexture = LoadTexture(PNG_PLAYER);
}

void Gui::HudEnd::display()
{
}
