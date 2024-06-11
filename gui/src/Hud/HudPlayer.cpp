/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** HudPlayer
*/

#include "Assets.hpp"
#include "Hud/HudPlayer.hpp"

#include <iostream>

Gui::HudPlayer::HudPlayer(std::shared_ptr<GameData> gameData)
{
    _typeScene = POV_PLAYER;
    _gameData = gameData;
    _texture = LoadTexture(PNG_HUD);
    _font = LoadFont(FONT_HUD);
}

void Gui::HudPlayer::display()
{
    Vector2 hudPos = HUD_PLAYER_POS;
    DrawTexture(_texture, hudPos.x, hudPos.y, WHITE);
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
    }
}
