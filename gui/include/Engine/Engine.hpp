/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Engine
*/

#pragma once

#include "Render/Render.hpp"
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
        Engine(Network network, std::shared_ptr<Render> render);

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

        ServerParser                _parser;    // Parser class for server's command.
        Network                     _network;   // Network class to connect to the server.
        std::shared_ptr<Render>     _render;    // Render class to draw the scene.

        /**
         * @brief Listen the server and update Engine with its commands.
         *
         */
        void listenServer(void);
};
