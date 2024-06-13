/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** HudGame
*/

#include "Assets.hpp"
#include "Hud/HudGame.hpp"

#include <iostream>

Gui::HudGame::HudGame(std::shared_ptr<GameData> gameData)
{
    _typeScene = GAME;
    _gameData = gameData;
    _texture = LoadTexture(PNG_HUD);
    _font = LoadFont(FONT_HUD);
}

void Gui::HudGame::display()
{
    Vector2 hudPos = HUD_GAME_POS;
    DrawTexture(_texture, hudPos.x, hudPos.y, WHITE);
    DrawTextEx(_font, "   Game", HUD_GAME_TEXT_TITLE_POS, 20, 0, (Color){170, 121, 89, 255});

    Vector2 hudTextPos = HUD_GAME_TEXT_POS;
    DrawTextEx(_font, ("Tick: " + std::to_string(_gameData->getServerTick())).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_GAME_TEXT_MARGING * 0}, 20, 0, WHITE);

    for (size_t index = 0; _gameData->getTeams().size() > index && index < 9; index++) {
        int maxLevel = -1;
        for (auto &player : _gameData->getTeams()[index].getPlayers()) {
            if (maxLevel < (int)player.getLevel())
                maxLevel = (int)player.getLevel();
        }
        if (maxLevel == -1)
            DrawTextEx(_font, (_gameData->getTeams()[index].getName() + " : 0").c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_GAME_TEXT_MARGING * (index + 1)}, 20, 0, WHITE);
        else
            DrawTextEx(_font, (_gameData->getTeams()[index].getName() + " : " + std::to_string(maxLevel)).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_GAME_TEXT_MARGING * (index + 1)}, 20, 0, WHITE);
    }
}
