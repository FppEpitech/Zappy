/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AGUIUpdater
*/

#pragma once

#include "GameDatas/GameData.hpp"
#include "Network/Network.hpp"
#include "GUIUpdater/IGUIUpdater.hpp"

#include <memory>

namespace Gui {

    /**
     * @brief AGUIUpdater class.
     */
    class AGUIUpdater;
}

class Gui::AGUIUpdater : public Gui::IGUIUpdater {
    public:

        /**
         * @brief Construct a new AGUIUpdater object.
         *
         * @param gameData The GUI GameData to update.
         * @param network The network to send commands to the server.
         */
        AGUIUpdater(std::shared_ptr<GameData> gameData, std::shared_ptr<INetwork> network);

        /**
         * @brief Destroy the AGUIUpdater object.
         */
        ~AGUIUpdater() = default;

        /**
         * @brief Update the GUI GameData.
         *
         */
        void update(const std::string &command, const std::vector<std::string> &data) override = 0;

    protected:

        std::shared_ptr<GameData>       _gameData;      // The GUI GameData to update.
        std::shared_ptr<INetwork>       _network;       // The network to send commands to the server.
};
