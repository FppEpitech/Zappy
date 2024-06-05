/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GUIUpdater
*/

#pragma once

#include "GameDatas/GameData.hpp"

#include <string>
#include <functional>
#include <unordered_map>

namespace Gui {

    /**
     * @brief GUIUpdater class
     *
     * This class is used to update the GUI GameData to ensure the GUI is up to date
     */
    class GUIUpdater;
}

class Gui::GUIUpdater {

    public:

        /**
         * @brief Construct a new GUIUpdater object
         *
         * @param gameData The GUI GameData to update
        */
        GUIUpdater(std::shared_ptr<GameData> gameData);

        /**
         * @brief Destroy the GUIUpdater object
        */
        ~GUIUpdater() = default;

        /**
         * @brief Update the GUI GameData
         *
         * @param command The command to update the GUI GameData
         * @param data The data to update the GUI GameData
        */
        void update(const std::string &command, const std::vector<std::string> &data);

    private:

        std::shared_ptr<GameData> _gameData;

        std::unordered_map<std::string, std::function<void(std::vector<std::string>)>> _updateMap =
        {
            {"msz", [this](std::vector<std::string> data){updateMapSize(data);}},
            {"bct", [this](std::vector<std::string> data){updateMapContent(data);}},
            {"tna", [this](std::vector<std::string> data){updateTeamNames(data);}},
            {"pnw", [this](std::vector<std::string> data){updateTeamMember(data);}},
            {"ppo", [this](std::vector<std::string> data){updatePlayerPosition(data);}},
            {"plv", [this](std::vector<std::string> data){updatePlayerLevel(data);}},
            {"pin", [this](std::vector<std::string> data){updatePlayerInventory(data);}},
            {"pex", [this](std::vector<std::string> data){updatePlayerExpulsion(data);}},
            {"pbc", [this](std::vector<std::string> data){updatePlayerBroadcast(data);}},
        };

        /**
         * @brief Update the GUI GameData map size
         *
         * @param data The data to update the GUI GameData map size
        */
        void updateMapSize(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData map content
         *
         * @param data The data to update the GUI GameData map content
        */
        void updateMapContent(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData team names
         *
         * @param data The data to update the GUI GameData team names
        */
        void updateTeamNames(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData team member
         *
         * @param data The data to update the GUI GameData team member
        */
        void updateTeamMember(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData player position
         *
         * @param data The data to update the GUI GameData player position
        */
        void updatePlayerPosition(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData player level
         *
         * @param data The data to update the GUI GameData player level
        */
        void updatePlayerLevel(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData player inventory
         *
         * @param data The data to update the GUI GameData player inventory
        */
        void updatePlayerInventory(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData player expulsion
         *
         * @param data The data to update the GUI GameData player expulsion
        */
        void updatePlayerExpulsion(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData player broadcast
         *
         * @param data The data to update the GUI GameData player broadcast
        */
        void updatePlayerBroadcast(const std::vector<std::string> &data);
};
