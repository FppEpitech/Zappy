/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** HudEnd
*/

#pragma once

#include "Hud/AHud.hpp"

namespace Gui {

    /**
    * @brief Class to display end's HUD.
    *
    */
    class HudEnd;
};

class Gui::HudEnd : public Gui::AHud {

    public:

        /**
         * @brief Construct a new Hud End object.
         *
         * @param gameData GameData class.
         */
        HudEnd(std::shared_ptr<GameData> gameData);

        /**
         * @brief Destroy the Hud End object.
         *
         */
        ~HudEnd() = default;

        /**
         * @brief Display End Hud.
         *
         */
        void display();

    private:

            Texture2D   _texture;       //!< Texture for Hud Background.
            Font        _font;          //!< Font for Hud's texts.
            Texture2D   _playerTexture; //!< Texture for player png.
};
