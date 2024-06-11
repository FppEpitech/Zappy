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

        ~AHud() = default;
        virtual void display() = 0;
        void setPlayer(std::shared_ptr<Player> player);
        TypeScene getType();

    protected:

        TypeScene                       _typeScene;
        std::shared_ptr<GameData>       _gameData;
        std::shared_ptr<Player>         _player;
};
