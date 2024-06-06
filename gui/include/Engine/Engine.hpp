/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Engine
*/

#pragma once

#include "Event/Event.hpp"
#include "Render/Render.hpp"
#include "Network/Network.hpp"
#include "GameDatas/GameData.hpp"
#include "Parsing/ServerParser.hpp"
#include "GUIUpdater/GUIUpdater.hpp"

#include <time.h>

#define NO_TICK int(-1)

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

        ServerParser                _parser;        // Parser class for server's command.
        Network                     _network;       // Network class to connect to the server.
        std::shared_ptr<Render>     _render;        // Render class to draw the scene.
        Event                       _event;         // Event class to listen the user's inputs.
        std::shared_ptr<GameData>   _gameData;      // GameData class to store the game's data.
        GUIUpdater                  _guiUpdater;    // GUIUpdater class to update the GUI.
        std::size_t                 _tick;          // Tick value of the server.
        clock_t                     _lastTick;      // Last tick of the Engine (based on the server tick).

        /**
         * @brief Listen the server and update Engine with its commands.
         *
         */
        void listenServer(void);

        /**
         * @brief Send Messages to server at each tick.
         * - The content of tiles.
         * - The size of the map.
         * - The names of teams.
         * - The tick.
         */
        void sendMessageUpdate(void);
};
