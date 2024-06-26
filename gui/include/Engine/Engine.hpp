/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Engine
*/

#pragma once

#include "Event/Event.hpp"
#include "Render/Render.hpp"
#include "Network/INetwork.hpp"
#include "GameDatas/GameData.hpp"
#include "Parsing/ServerParser.hpp"
#include "GUIUpdater/GUIUpdater.hpp"

#include <thread>
#include <time.h>

#define TIME_UNIT_MAP_UPDATE 20

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
        Engine(std::shared_ptr<INetwork> network);

        /**
         * @brief Destroy the Engine object.
         *
         */
        ~Engine() = default;

        /**
         * @brief Run the engine loop.
         *
         * @note This method runs in the main thread.
         */
        void run();

    private:

        std::unique_ptr<IServerParser>      _parser;        //!< Parser class for server's command.
        std::shared_ptr<INetwork>           _network;       //!< Network class to connect to the server.
        std::shared_ptr<Render>             _render;        //!< Render class to draw the scene.
        std::unique_ptr<IEvent>             _event;         //!< Event class to listen the user's inputs.
        std::shared_ptr<GameData>           _gameData;      //!< GameData class to store the game's data.
        std::unique_ptr<IGUIUpdater>        _guiUpdater;    //!< GUIUpdater class to update the GUI.
        std::thread                         _networkThread; //!< Thread to listen the server and update the GameData.

        /**
         * @brief Listen the server and update Engine with its commands.
         *
         */
        void listenServer();

        /**
         * @brief Send Messages to server at each tick.
         * - The content of tiles.
         * - The size of the map.
         * - The names of teams.
         * - The tick.
         */
        void sendMessageUpdate();

        /**
         * @brief Update the map at each 20 / ticks units.
         *
         */
        void updateMap();

        /**
         * @brief Send update map message.
         *
         */
        void sendUpdateMapMessage();

        /**
         * @brief Thread loop for the network thread.
         *
         * @note This method runs in a separate thread.
         */
        void threadLoop();
};
