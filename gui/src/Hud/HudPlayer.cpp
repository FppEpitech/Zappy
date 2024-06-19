/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** HudPlayer
*/

#include "Assets.hpp"
#include "Hud/HudPlayer.hpp"

Gui::HudPlayer::HudPlayer(std::shared_ptr<GameData> gameData)
{
    _typeScene = POV_PLAYER;
    _gameData = gameData;
    _texture = LoadTexture(PNG_HUD);
    _food = LoadTexture(PNG_FOOD);
    _linemate = LoadTexture(PNG_LINEMATE);
    _deraumere = LoadTexture(PNG_DERAUMERE);
    _mendiane = LoadTexture(PNG_MENDIANE);
    _phiras = LoadTexture(PNG_PHIRAS);
    _sibur = LoadTexture(PNG_SIBUR);
    _thystame = LoadTexture(PNG_THYSTAME);
    _font = LoadFont(FONT_HUD);
    _playerTexture = LoadTexture(PNG_PLAYER);
}

void Gui::HudPlayer::display()
{
    Vector2 hudPos = HUD_PLAYER_POS;
    DrawTexture(_texture, hudPos.x, hudPos.y, WHITE);
    DrawTextEx(_font, "Player", HUD_PLAYER_TEXT_TITLE_POS, 20, 0, (Color){170, 121, 89, 255});
    if (_player != nullptr) {
        Vector2 hudTextPos = HUD_PLAYER_TEXT_POS;
        DrawTextEx(_font, ("Food: " + std::to_string(_player->inventory.getFood())).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_PLAYER_TEXT_MARGING * 0}, 20, 0, WHITE);
        DrawTextEx(_font, ("Linemate: " + std::to_string(_player->inventory.getLinemate())).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_PLAYER_TEXT_MARGING * 1}, 20, 0, WHITE);
        DrawTextEx(_font, ("Deraumere: " + std::to_string(_player->inventory.getDeraumere())).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_PLAYER_TEXT_MARGING * 2}, 20, 0, WHITE);
        DrawTextEx(_font, ("Mendiane: " + std::to_string(_player->inventory.getMendiane())).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_PLAYER_TEXT_MARGING * 3}, 20, 0, WHITE);
        DrawTextEx(_font, ("Phiras: " + std::to_string(_player->inventory.getPhiras())).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_PLAYER_TEXT_MARGING * 4}, 20, 0, WHITE);
        DrawTextEx(_font, ("Sibur: " + std::to_string(_player->inventory.getSibur())).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_PLAYER_TEXT_MARGING * 5}, 20, 0, WHITE);
        DrawTextEx(_font, ("Thystame: " + std::to_string(_player->inventory.getThystame())).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_PLAYER_TEXT_MARGING * 6}, 20, 0, WHITE);
        DrawTextEx(_font, ("Level: " + std::to_string(_player->getLevel())).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_PLAYER_TEXT_MARGING * 7}, 20, 0, WHITE);
        DrawTextEx(_font, ("Id: " + std::to_string(_player->getId())).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_PLAYER_TEXT_MARGING * 8}, 20, 0, WHITE);
        DrawTextEx(_font, ("Team: " + _player->getTeam()).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_PLAYER_TEXT_MARGING * 9}, 20, 0, WHITE);

        DrawTexture(_food, hudTextPos.x + HUD_PLAYER_ICONS_MARGING, hudTextPos.y + HUD_PLAYER_TEXT_MARGING * 0, WHITE);
        DrawTexture(_linemate, hudTextPos.x + HUD_PLAYER_ICONS_MARGING, hudTextPos.y + HUD_PLAYER_TEXT_MARGING * 1, WHITE);
        DrawTexture(_deraumere, hudTextPos.x + HUD_PLAYER_ICONS_MARGING, hudTextPos.y + HUD_PLAYER_TEXT_MARGING * 2, WHITE);
        DrawTexture(_mendiane, hudTextPos.x + HUD_PLAYER_ICONS_MARGING, hudTextPos.y + HUD_PLAYER_TEXT_MARGING * 3, WHITE);
        DrawTexture(_phiras, hudTextPos.x + HUD_PLAYER_ICONS_MARGING, hudTextPos.y + HUD_PLAYER_TEXT_MARGING * 4, WHITE);
        DrawTexture(_sibur, hudTextPos.x + HUD_PLAYER_ICONS_MARGING, hudTextPos.y + HUD_PLAYER_TEXT_MARGING * 5, WHITE);
        DrawTexture(_thystame, hudTextPos.x + HUD_PLAYER_ICONS_MARGING, hudTextPos.y + HUD_PLAYER_TEXT_MARGING * 6, WHITE);

        DrawTexture(_playerTexture, hudPos.x + HUD_PLAYER_TITLE_ICON_MARGING.x, hudPos.y + HUD_PLAYER_TITLE_ICON_MARGING.y, WHITE);
    }
}
