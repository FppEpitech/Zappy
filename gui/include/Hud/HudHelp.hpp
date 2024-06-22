/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** HudHelp
*/

#pragma once

#include "Hud/AHud.hpp"

namespace Gui {

    /**
     * @brief Class to display help's HUD.
     *
     */
    class HudHelp;
};

class Gui::HudHelp : public Gui::AHud {

    public:

        /**
         * @brief Construct a new Hud Help object.
         *
         * @param gameData GameData class.
         */
        HudHelp(std::shared_ptr<GameData> gameData);

        /**
         * @brief Destroy the Hud Help object.
         *
         */
        ~HudHelp() = default;

        /**
         * @brief Display Help Hud.
         *
         */
        void display();

    private:

        Texture2D       _texture;           // Texture for Hud Background.
        Texture2D       _textureKeys;       // Texture for Hud keys.
        Font            _font;              // Font for Hud's texts.
        clock_t         _helpMenuClock;     // Clock to display the help menu.

        /**
         * @brief Display Help Menu Controls.
         *
         * @param position Position of the help menu.
         */
        void displayHelpMenuControls();
};
