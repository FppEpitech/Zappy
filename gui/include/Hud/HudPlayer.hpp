/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** HudPlayer
*/

#pragma once

#include "Hud/AHud.hpp"

#define HUD_PLAYER_POS Vector2{0, 340}
#define HUD_PLAYER_TEXT_POS Vector2{25, 420}
#define HUD_PLAYER_TEXT_TITLE_POS Vector2{50, 380}
#define HUD_PLAYER_TEXT_MARGING 30

namespace Gui {

    /**
     * @brief Class to display player's HUD.
     *
     */
    class HudPlayer;
};

class Gui::HudPlayer : public Gui::AHud {

    public:

        /**
         * @brief Construct a new Hud Player object.
         *
         * @param gameData GameData class.
         */
        HudPlayer(std::shared_ptr<GameData> gameData);

        /**
         * @brief Destroy the Hud Player object.
         *
         */
        ~HudPlayer() = default;

        /**
         * @brief Display Player Hud.
         *
         */
        void display();

    private:

        Texture2D   _texture;       // Texture for Hud Background.
        Font        _font;          // Font for Hud's texts.
};
