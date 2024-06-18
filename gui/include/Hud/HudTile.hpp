/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** HudTile
*/

#pragma once

#include "Hud/AHud.hpp"

#define HUD_TILE_POS Vector2{0, 340}
#define HUD_TILE_TEXT_POS Vector2{25, 420}
#define HUD_TILE_TEXT_TITLE_POS Vector2{50, 380}
#define HUD_TILE_TEXT_MARGING 30

namespace Gui {

    /**
     * @brief Class to display tile's HUD.
     *
     */
    class HudTile;
};

class Gui::HudTile : public Gui::AHud {

    public:

        /**
         * @brief Construct a new Hud Tile object.
         *
         * @param gameData GameData class.
         */
        HudTile(std::shared_ptr<GameData> gameData);

        /**
         * @brief Destroy the Hud Tile object.
         *
         */
        ~HudTile() = default;

        /**
         * @brief Display Tile Hud.
         *
         */
        void display();

    private:

        Texture2D   _texture;       // Texture for Hud Background.
        Font        _font;          // Font for Hud's texts.

        Texture2D   _food;          // Texture for food png.
        Texture2D   _linemate;      // Texture for linemate png.
        Texture2D   _deraumere;     // Texture for deraumere png.
        Texture2D   _mendiane;      // Texture for mendiane png.
        Texture2D   _phiras;        // Texture for phiras png.
        Texture2D   _sibur;         // Texture for sibur png.
        Texture2D   _thystame;      // Texture for thystame png.
};
