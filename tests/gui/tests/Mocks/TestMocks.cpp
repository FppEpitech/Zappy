/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TestMocks
*/

#include "raylib.h"
#include "Assets.hpp"
#include "Hud/HudGame.hpp"
#include "Hud/HudPlayer.hpp"
#include "Hud/HudTile.hpp"
#include "Hud/HudHelp.hpp"
#include "CriterionHeaders.hpp"

ModelAnimation LoadModelAnimation(const char *fileName)
{
    (void)fileName;
    ModelAnimation modelAnimation;
    return modelAnimation;
}

Model LoadModel(const char *fileName)
{
    (void)fileName;
    Model model;
    return model;
}

Texture2D LoadTexture(const char *fileName)
{
    (void)fileName;
    Texture2D texture;
    return texture;
}

Font LoadFont(const char *fileName)
{
    (void)fileName;
    Font font;
    return font;
}

void DrawModel(Model model, Vector3 position, float scale, Color tint)
{
    (void)model;
    (void)position;
    (void)scale;
    (void)tint;
}

void DrawText(const char *text, int posX, int posY, int fontSize, Color color)
{
    (void)text;
    (void)posX;
    (void)posY;
    (void)fontSize;
    (void)color;
}

void DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint)
{
    (void)font;
    (void)text;
    (void)position;
    (void)fontSize;
    (void)spacing;
    (void)tint;
}

void DrawTexture(Texture2D texture, int posX, int posY, Color tint)
{
    (void)texture;
    (void)posX;
    (void)posY;
    (void)tint;
}

Test(HudGame, testHudGame, .timeout = 5)
{
    Gui::GameData gameData;
    Gui::HudGame hudGame(std::make_shared<Gui::GameData>(gameData));

    hudGame.display();
    cr_assert_eq(hudGame.getType(), Gui::IHud::TypeScene::GAME);
}

Test(HudTile, testHudTile, .timeout = 5)
{
    Gui::GameData gameData;
    Gui::HudTile hudTile(std::make_shared<Gui::GameData>(gameData));

    hudTile.display();
    cr_assert_eq(hudTile.getType(), Gui::IHud::TypeScene::TILE);
}

Test(HudHelp, testHudHelp, .timeout = 5)
{
    Gui::GameData gameData;
    Gui::HudHelp hudHelp(std::make_shared<Gui::GameData>(gameData));

    hudHelp.display();
    cr_assert_eq(hudHelp.getType(), Gui::IHud::TypeScene::HELP_MENU);
}
