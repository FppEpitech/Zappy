/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** HudPlayer
*/

#pragma once

#include "Hud/AHud.hpp"

#define HUD_PLAYER_POS Vector2{0, 340}
#define HUD_PLAYER_TEXT_POS Vector2{55, 420}
#define HUD_PLAYER_TEXT_TITLE_POS Vector2{80, 380}
#define HUD_PLAYER_TEXT_MARGING 30
#define HUD_PLAYER_ICONS_MARGING -32
#define HUD_PLAYER_TITLE_ICON_MARGING Vector2{45, 35}

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

        Texture2D   _texture;       //!< Texture for Hud Background.
        Font        _font;          //!< Font for Hud's texts.

        Texture2D   _food;          //!< Texture for food png.
        Texture2D   _linemate;      //!< Texture for linemate png.
        Texture2D   _deraumere;     //!< Texture for deraumere png.
        Texture2D   _mendiane;      //!< Texture for mendiane png.
        Texture2D   _phiras;        //!< Texture for phiras png.
        Texture2D   _sibur;         //!< Texture for sibur png.
        Texture2D   _thystame;      //!< Texture for thystame png.
        Texture2D   _playerTexture; //!< Texture for player png.
};
