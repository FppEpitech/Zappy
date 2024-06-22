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
    _texture = LoadTexture(PNG_END_HUD);
    _font = LoadFont(FONT_HUD);
}

void Gui::HudEnd::display()
{
    std::string end = "The winner Team is: " + _gameData.get()->getEndMessage();

    DrawTextureEx(_texture, HELP_BACKGROUND_POSITION, 0, HELP_BACKGROUND_SCALE, WHITE);
    DrawText(end.c_str(), WINDOW_WIDTH / 2 - MeasureText(end.c_str(), END_HUD_TEXT_SIZE) / 2, WINDOW_HEIGHT / 2 - 50, END_HUD_TEXT_SIZE, WHITE);
}
