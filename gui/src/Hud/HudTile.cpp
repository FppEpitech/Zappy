/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** HudTile
*/

#include "Assets.hpp"
#include "Hud/HudTile.hpp"

Gui::HudTile::HudTile(std::shared_ptr<GameData> gameData)
{
    _typeScene = TILE;
    _gameData = gameData;
    _texture = LoadTexture(PNG_HUD);
    _font = LoadFont(FONT_HUD);
    _food = LoadTexture(PNG_FOOD);
    _linemate = LoadTexture(PNG_LINEMATE);
    _deraumere = LoadTexture(PNG_DERAUMERE);
    _mendiane = LoadTexture(PNG_MENDIANE);
    _phiras = LoadTexture(PNG_PHIRAS);
    _sibur = LoadTexture(PNG_SIBUR);
    _thystame = LoadTexture(PNG_THYSTAME);
    _font = LoadFont(FONT_HUD);
    _tileTexture = LoadTexture(PNG_TILE);
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

        DrawTexture(_food, hudTextPos.x - 32, hudTextPos.y + HUD_TILE_TEXT_MARGING * 0, WHITE);
        DrawTexture(_linemate, hudTextPos.x - 32, hudTextPos.y + HUD_TILE_TEXT_MARGING * 1, WHITE);
        DrawTexture(_deraumere, hudTextPos.x - 32, hudTextPos.y + HUD_TILE_TEXT_MARGING * 2, WHITE);
        DrawTexture(_mendiane, hudTextPos.x - 32, hudTextPos.y + HUD_TILE_TEXT_MARGING * 3, WHITE);
        DrawTexture(_phiras, hudTextPos.x - 32, hudTextPos.y + HUD_TILE_TEXT_MARGING * 4, WHITE);
        DrawTexture(_sibur, hudTextPos.x - 32, hudTextPos.y + HUD_TILE_TEXT_MARGING * 5, WHITE);
        DrawTexture(_thystame, hudTextPos.x - 32, hudTextPos.y + HUD_TILE_TEXT_MARGING * 6, WHITE);

        DrawTexture(_tileTexture, hudPos.x + 45, hudPos.y + 40, WHITE);
    }
}
