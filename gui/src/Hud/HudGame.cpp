/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** HudGame
*/

#include "Assets.hpp"
#include "Hud/HudGame.hpp"

Gui::HudGame::HudGame(std::shared_ptr<GameData> gameData)
{
    _typeScene = GAME;
    _gameData = gameData;
    _texture = LoadTexture(PNG_HUD);
    _font = LoadFont(FONT_HUD);
    _playerTexture = LoadTexture(PNG_PLAYER);
}

void Gui::HudGame::display()
{
    Vector2 hudPos = HUD_GAME_POS;
    DrawTexture(_texture, hudPos.x, hudPos.y, WHITE);
    DrawTextEx(_font, "   Game", HUD_GAME_TEXT_TITLE_POS, 20, 0, (Color){170, 121, 89, 255});

    Vector2 hudTextPos = HUD_GAME_TEXT_POS;
    DrawTextEx(_font, ("Tick: " + std::to_string(_gameData->getServerTick())).c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_GAME_TEXT_MARGING * 0}, 20, 0, WHITE);

    for (std::size_t index = 0; _gameData->getTeams().size() > index && index < 9; index++) {

        std::string teamName = _gameData->getTeams()[index].getName();
        if (teamName.size() > 10) {
            teamName = teamName.substr(0, 8);
            teamName += "..";
        }
        DrawTextEx(_font, teamName.c_str(), (Vector2){hudTextPos.x, hudTextPos.y + HUD_GAME_TEXT_MARGING * (index + 1)}, 20, 0, WHITE);
        DrawTextEx(_font, (std::to_string(_gameData->getTeams()[index].getPlayers().size()) + "/" +
            std::to_string(_gameData->getTeams()[index].getPlayers().size() + _gameData->getTeams()[index].getEggs().size())).c_str(),
            (Vector2){hudTextPos.x + 100, hudTextPos.y + HUD_GAME_TEXT_MARGING * (index + 1)}, 20, 0, WHITE);

        DrawTexture(_playerTexture, hudTextPos.x + 130, hudTextPos.y + HUD_GAME_TEXT_MARGING * (index + 1), _gameData.get()->getTeams()[index].getPlayerColor());
    }
}
