/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** IHud
*/

#pragma once

#include "GameDatas/Player.hpp"

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
            TILE
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
         * @brief Get the Type object.
         *
         * @return TypeScene - Type of the scene.
         */
        virtual TypeScene getType() = 0;
};
