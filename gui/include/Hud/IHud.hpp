/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** IHud
*/

#pragma once

#include "GameDatas/Player.hpp"
#include "GameDatas/Tile.hpp"

#include <memory>

namespace Gui {

    /**
     * @brief Class to display HUD.
     *
     */
    class IHud;
};

class Gui::IHud {

    public:

        /**
         * @brief Hud enum for the different scenes.
         *
         */
        enum TypeScene {
            GAME,
            POV_PLAYER,
            END_GAME,
            TILE,
            HELP_TEXT,
            HELP_MENU
        };

        /**
         * @brief Destroy the IHud object.
         *
         */
        virtual ~IHud() = default;

        /**
         * @brief Display the Hud.
         *
         */
        virtual void display() = 0;

        /**
         * @brief Set the Player object.
         *
         * @param player Player to display infos.
         */
        virtual void setPlayer(std::shared_ptr<Player> player) = 0;

        /**
         * @brief Set the Tile object.
         *
         * @param tile Tile to display infos.
         */
        virtual void setTile(std::shared_ptr<Tile> tile) = 0;

        /**
         * @brief Get the Type object.
         *
         * @return TypeScene - Type of the scene.
         */
        virtual TypeScene getType() const = 0;

        /**
         * @brief Set the Type object.
         *
         * @param type Type of the scene.
         */
        virtual void setType(TypeScene type) = 0;
};
