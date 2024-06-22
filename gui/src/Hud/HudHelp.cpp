/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** HudHelp
*/

#include "Hud/HudHelp.hpp"
#include "Assets.hpp"
#include "Config.hpp"

Gui::HudHelp::HudHelp(std::shared_ptr<GameData> gameData)
{
    _typeScene = TypeScene::HELP_MENU;
    _gameData = gameData;
    _texture = LoadTexture(PNG_HELP);
    _textureKeys = LoadTexture(PNG_HELP_KEYS);
    _font = LoadFont(FONT_HUD);
    _helpMenuClock = clock();
}

void Gui::HudHelp::display()
{
    if (_typeScene == TypeScene::HELP_MENU) {
        std::string help = "Press 'H' to close the help menu.";
        DrawText(help.c_str(), WINDOW_WIDTH / 2 - MeasureText(help.c_str(), 20) / 2, 20, 20, WHITE);
        std::cout << "help background position: " << HELP_BACKGROUND_POSITION.x << " " << HELP_BACKGROUND_POSITION.y << std::endl;
        DrawTextureEx(_texture, HELP_BACKGROUND_POSITION, 0, HELP_BACKGROUND_SCALE, WHITE);
        DrawTexture(_textureKeys, HELP_BACKGROUND_POSITION.x + 17, HELP_BACKGROUND_POSITION.y + 92, WHITE);
        displayHelpMenuControls();
    }
    if (_typeScene == TypeScene::HELP_TEXT) {
        std::string help = "Press 'H' to display the help menu.";
        clock_t time = clock();
        float timeElapsed = float(time - _helpMenuClock) / CLOCKS_PER_SEC * 1000;
        if (timeElapsed > 50 && timeElapsed < 100)
            DrawText(help.c_str(), WINDOW_WIDTH / 2 - MeasureText(help.c_str(), 20) / 2, 20, 20, WHITE);
        if (timeElapsed >= 100)
            _helpMenuClock = clock();
    }
}

void Gui::HudHelp::displayHelpMenuControls()
{
    Vector2 position = HELP_TEXT_POSITION_LEFT;
    std::cout << "position: " << position.x << " " << position.y << std::endl;
    DrawText("Global Controls", position.x, position.y - HELP_TITLE_OFFSET, 40, WHITE);
    for (std::size_t i = 0; i < globalControlsTexts.size(); i++)
        DrawText(globalControlsTexts[i].c_str(), position.x, position.y + HELP_TEXT_SPACING * i, 20, WHITE);
    position = HELP_TEXT_POSITION_RIGHT;
    DrawText("Player Controls", position.x, position.y - HELP_TITLE_OFFSET, 40, WHITE);
    for (std::size_t i = 0; i < playerControlsTexts.size(); i++)
        DrawText(playerControlsTexts[i].c_str(), position.x, position.y + HELP_TEXT_SPACING * i, 20, WHITE);
}
