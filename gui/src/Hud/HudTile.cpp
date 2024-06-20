/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** HudTile
*/

#include "Assets.hpp"
#include "Hud/HudTile.hpp"

#include <list>

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
    _playerTexture = LoadTexture(PNG_PLAYER);
    _eggTexture = LoadTexture(PNG_EGG);
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

        std::list<Texture2D> textureList = {_food, _linemate, _deraumere, _mendiane, _phiras, _sibur, _thystame};

        int count = 0;
        for (Texture2D texture : textureList) {
            DrawTexture(texture, hudTextPos.x + HUD_TILE_ICONS_MARGING, hudTextPos.y + HUD_TILE_TEXT_MARGING * count, WHITE);
            count++;
        }
        DrawTexture(_tileTexture, hudPos.x + HUD_TILE_TITLE_ICON_MARGING.x, hudPos.y + HUD_TILE_TITLE_ICON_MARGING.y, WHITE);
        displayNbPlayers();
        displayNbEggs();
    }
}

void Gui::HudTile::displayNbPlayers()
{
    Vector2 hudTextPos = HUD_TILE_TEXT_POS;
    std::size_t nbPlayerOnTile = 0;

    for (auto &team : _gameData.get()->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getPosition() == _tile.get()->getPosition())
                nbPlayerOnTile++;
        }
    }

    DrawTextEx(_font, ("Players: " + std::to_string(nbPlayerOnTile)).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_TILE_TEXT_MARGING * 7}, 20, 0, WHITE);
    DrawTexture(_playerTexture, hudTextPos.x + HUD_TILE_ICONS_MARGING, hudTextPos.y + HUD_TILE_TEXT_MARGING * 7, WHITE);
}

void Gui::HudTile::displayNbEggs()
{
    Vector2 hudTextPos = HUD_TILE_TEXT_POS;
    std::size_t nbEggOnTile = 0;

    for (auto &egg : _gameData.get()->getServerEggs()) {
        if (egg.getPosition() == _tile.get()->getPosition())
            nbEggOnTile++;
    }
    for (auto &team : _gameData.get()->getTeams()) {
        for (auto &egg : team.getEggs()) {
            if (egg.getPosition() == _tile.get()->getPosition())
                nbEggOnTile++;
        }
    }
    DrawTextEx(_font, ("Eggs: " + std::to_string(nbEggOnTile)).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_TILE_TEXT_MARGING * 8}, 20, 0, WHITE);
    DrawTexture(_eggTexture, hudTextPos.x + HUD_TILE_ICONS_MARGING, hudTextPos.y + HUD_TILE_TEXT_MARGING * 8, WHITE);
}
