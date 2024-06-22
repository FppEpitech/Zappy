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
         * @brief Set the Tile object.
         *
         * @param tile Tile to display infos.
         */
        void setTile(std::shared_ptr<Tile> tile);

        /**
         * @brief Get the Type object.
         *
         * @return TypeScene - Type of the scene.
         */
        TypeScene getType() const;

        /**
         * @brief Set the Type object.
         *
         * @param type Type of the scene.
         */
        void setType(TypeScene type);

    protected:

        TypeScene                       _typeScene;     //!< Type of the scene.
        std::shared_ptr<GameData>       _gameData;      //!< GameData class.
        std::shared_ptr<Player>         _player;        //!< Player to display hud.
        std::shared_ptr<Tile>           _tile;          //!< Tile to display hud.
};
