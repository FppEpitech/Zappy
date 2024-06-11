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

        enum TypeScene {
            GAME,
            POV_PLAYER,
            END_GAME
        };

        virtual ~IHud() = default;
        virtual void display() = 0;
        virtual void setPlayer(std::shared_ptr<Player> player) = 0;
        virtual TypeScene getType() = 0;
};
