/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** AHud
*/

#pragma once

#include "Hud/IHud.hpp"
#include "GameDatas/GameData.hpp"

namespace Gui {

    /**
     * @brief Class to display HUD.
     *
     */
    class AHud;
};

class Gui::AHud : public Gui::IHud {

    public:

        /**
         * @brief Destroy the AHud object.
         *
         */
        ~AHud() = default;

        /**
         * @brief Display Hud.
         *
         */
        virtual void display() = 0;

        /**
         * @brief Set the Player object.
         *
         * @param player Player to display infos.
         */
        void setPlayer(std::shared_ptr<Player> player);

        /**
         * @brief Get the Type object.
         *
         * @return TypeScene - Type of the scene.
         */
        TypeScene getType();

    protected:

        TypeScene                       _typeScene;     // Type of the scene.
        std::shared_ptr<GameData>       _gameData;      // GameData class.
        std::shared_ptr<Player>         _player;        // Player to display hud.
};
