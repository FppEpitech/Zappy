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
    if (_tile != nullptr) {
        Vector2 hudTextPos = HUD_TILE_TEXT_POS;
        DrawTextEx(_font, ("Food: " + std::to_string(_tile->inventory.getFood())).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_TILE_TEXT_MARGING * 0}, 20, 0, WHITE);
        DrawTextEx(_font, ("Linemate: " + std::to_string(_tile->inventory.getLinemate())).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_TILE_TEXT_MARGING * 1}, 20, 0, WHITE);
        DrawTextEx(_font, ("Deraumere: " + std::to_string(_tile->inventory.getDeraumere())).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_TILE_TEXT_MARGING * 2}, 20, 0, WHITE);
        DrawTextEx(_font, ("Mendiane: " + std::to_string(_tile->inventory.getMendiane())).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_TILE_TEXT_MARGING * 3}, 20, 0, WHITE);
        DrawTextEx(_font, ("Phiras: " + std::to_string(_tile->inventory.getPhiras())).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_TILE_TEXT_MARGING * 4}, 20, 0, WHITE);
        DrawTextEx(_font, ("Sibur: " + std::to_string(_tile->inventory.getSibur())).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_TILE_TEXT_MARGING * 5}, 20, 0, WHITE);
        DrawTextEx(_font, ("Thystame: " + std::to_string(_tile->inventory.getThystame())).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_TILE_TEXT_MARGING * 6}, 20, 0, WHITE);
    }
}
