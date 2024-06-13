/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** HudTile
*/

#include "Assets.hpp"
#include "Hud/HudTile.hpp"

#include <iostream>

Gui::HudTile::HudTile(std::shared_ptr<GameData> gameData)
{
    _typeScene = TILE;
    _gameData = gameData;
    _texture = LoadTexture(PNG_HUD);
    _font = LoadFont(FONT_HUD);
}

void Gui::HudTile::display()
{
    Vector2 hudPos = HUD_TILE_POS;
    DrawTexture(_texture, hudPos.x, hudPos.y, WHITE);
    DrawTextEx(_font, "   Tile", HUD_TILE_TEXT_TITLE_POS, 20, 0, (Color){170, 121, 89, 255});
}
