/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** HudGame
*/

#pragma once

#include "Hud/AHud.hpp"

#define HUD_GAME_POS Vector2{0, 340}
#define HUD_GAME_TEXT_POS Vector2{25, 420}
#define HUD_GAME_TEXT_TITLE_POS Vector2{50, 380}
#define HUD_GAME_TEXT_MARGING 30

namespace Gui {

    /**
     * @brief Class to display game's HUD.
     *
     */
    class HudGame;
};

class Gui::HudGame : public Gui::AHud {

    public:

        /**
         * @brief Construct a new Hud Game object.
         *
         * @param gameData GameData class.
         */
        HudGame(std::shared_ptr<GameData> gameData);

        /**
         * @brief Destroy the Hud Game object.
         *
         */
        ~HudGame() = default;

        /**
         * @brief Display Game Hud.
         *
         */
        void display();

    private:

        Texture2D   _texture;       // Texture for Hud Background.
        Font        _font;          // Font for Hud's texts.
        Texture2D   _playerTexture; // Texture for player png.
};
