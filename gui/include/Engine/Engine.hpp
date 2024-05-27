/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Engine
*/

#pragma once

#include "Network/Network.hpp"

namespace Gui {

    /**
     * @brief Main GUI class.
     *
     */
    class Engine;
};

class Gui::Engine {

    public:

        Engine(Network network);
        ~Engine() = default;
        void run();

        void setOpen(bool isOpen);
        bool getOpen();

    private:

        Network     _network;
        bool        _isOpen;

        void listenServer();

};