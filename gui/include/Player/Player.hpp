/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Player
*/

#pragma once

#include "Player/Inventory.hpp"

namespace Gui {

    /**
     * @brief Player class.
     *
     */
    class Player;
};

class Gui::Player {

    public:

        Player();
        ~Player() = default;

    private:

        Inventory       _inventory;
};
