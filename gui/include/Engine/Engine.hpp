/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Engine
*/

#pragma once

#include "Network/Network.hpp"
#include "Parsing/ServerParser.hpp"

namespace Gui {

    /**
     * @brief Main GUI class.
     *
     */
    class Engine;
};

class Gui::Engine {

    public:

        /**
         * @brief Construct a new Engine object.
         *
         * @param network Network class.
         */
        Engine(Network network);

        /**
         * @brief Destroy the Engine object.
         *
         */
        ~Engine() = default;

        /**
         * @brief Run the engine loop.
         *
         */
        void run(void);

    private:

        ServerParser    _parser;    // Parser class for server's command
        Network         _network;   // Network class to connect to the server.

        /**
         * @brief Listen the server and update Engine with its commands.
         *
         */
        void listenServer(void);
};
