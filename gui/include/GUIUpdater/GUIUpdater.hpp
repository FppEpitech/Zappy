/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GUIUpdater
*/

#pragma once

#include "GameDatas/GameData.hpp"
#include "Network/Network.hpp"

#include <string>
#include <functional>
#include <unordered_map>

namespace Gui {

    /**
     * @brief GUIUpdater class.
     *
     * This class is used to update the GUI GameData to ensure the GUI is up to date.
     */
    class GUIUpdater;
}

class Gui::GUIUpdater {

    public:

        /**
         * @brief Construct a new GUIUpdater object.
         *
         * @param gameData The GUI GameData to update.
         * @param network The network to send commands to the server.
        */
        GUIUpdater(std::shared_ptr<GameData> gameData, std::shared_ptr<Network> network);

        /**
         * @brief Destroy the GUIUpdater object.
        */
        ~GUIUpdater() = default;

        /**
         * @brief Update the GUI GameData.
         *
         * @param command The command to update the GUI GameData.
         * @param data The data to update the GUI GameData.
        */
        void update(const std::string &command, const std::vector<std::string> &data);

    private:

        std::shared_ptr<GameData> _gameData; // The GUI GameData to update.
        std::shared_ptr<Network> _network; // The network to send commands to the server.

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
            {"pic", [this](std::vector<std::string> data){updatePlayerStartIncantation(data);}},
            {"pie", [this](std::vector<std::string> data){updatePlayerEndIncantation(data);}},
            {"pfk", [this](std::vector<std::string> data){updatePlayerEggLaying(data);}},
            {"pdr", [this](std::vector<std::string> data){updatePlayerRessourceDropping(data);}},
            {"pgt", [this](std::vector<std::string> data){updatePlayerRessourceCollecting(data);}},
            {"pdi", [this](std::vector<std::string> data){updatePlayerDeath(data);}},
            {"enw", [this](std::vector<std::string> data){updateEggLaidByPlayer(data);}},
            {"ebo", [this](std::vector<std::string> data){updatePlayerBorn(data);}},
            {"edi", [this](std::vector<std::string> data){updateEggDeath(data);}},
            {"sgt", [this](std::vector<std::string> data){updateTimeUnitRequest(data);}},
            {"sst", [this](std::vector<std::string> data){updateTimeUnitModification(data);}},
            {"seg", [this](std::vector<std::string> data){updateEndOfGame(data);}},
            {"smg", [this](std::vector<std::string> data){updateMessageFromServer(data);}},
            {"suc", [this](std::vector<std::string> data){updateUnknownMessage(data);}},
            {"sbp", [this](std::vector<std::string> data){updateCommandParameter(data);}},
        }; // The map of commands to update the GUI GameData.

        /**
         * @brief Update the GUI GameData map size.
         *
         * @param data The data to update the GUI GameData map size.
        */
        void updateMapSize(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData map content.
         *
         * @param data The data to update the GUI GameData map content.
        */
        void updateMapContent(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData team names.
         *
         * @param data The data to update the GUI GameData team names.
        */
        void updateTeamNames(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData team member.
         *
         * @param data The data to update the GUI GameData team member.
        */
        void updateTeamMember(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData player position.
         *
         * @param data The data to update the GUI GameData player position.
        */
        void updatePlayerPosition(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData player level.
         *
         * @param data The data to update the GUI GameData player level.
        */
        void updatePlayerLevel(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData player inventory.
         *
         * @param data The data to update the GUI GameData player inventory.
        */
        void updatePlayerInventory(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData player expulsion.
         *
         * @param data The data to update the GUI GameData player expulsion.
        */
        void updatePlayerExpulsion(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData player broadcast.
         *
         * @param data The data to update the GUI GameData player broadcast.
        */
        void updatePlayerBroadcast(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData player start incantation.
         *
         * @param data The data to update the GUI GameData player start incantation.
        */
        void updatePlayerStartIncantation(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData player end incantation.
         *
         * @param data The data to update the GUI GameData player end incantation.
        */
        void updatePlayerEndIncantation(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData player egg laying.
         *
         * @param data The data to update the GUI GameData player egg laying.
        */
        void updatePlayerEggLaying(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData player ressource dropping.
         *
         * @param data The data to update the GUI GameData player ressource dropping.
        */
        void updatePlayerRessourceDropping(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData player ressource collecting.
         *
         * @param data The data to update the GUI GameData player ressource collecting.
        */
        void updatePlayerRessourceCollecting(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData player death.
         *
         * @param data The data to update the GUI GameData player death.
        */
        void updatePlayerDeath(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData egg laid by player.
         *
         * @param data The data to update the GUI GameData egg laid by player.
        */
        void updateEggLaidByPlayer(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData player born.
         *
         * @param data The data to update the GUI GameData player born.
        */
        void updatePlayerBorn(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData egg death.
         *
         * @param data The data to update the GUI GameData egg death.
        */
        void updateEggDeath(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData time unit request.
         *
         * @param data The data to update the GUI GameData time unit request.
        */
        void updateTimeUnitRequest(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData time unit modification.
         *
         * @param data The data to update the GUI GameData time unit modification.
        */
        void updateTimeUnitModification(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData end of game.
         *
         * @param data The data to update the GUI GameData end of game.
        */
        void updateEndOfGame(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData message from server.
         *
         * @param data The data to update the GUI GameData message from server.
        */
        void updateMessageFromServer(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData unknow message.
         *
         * @param data The data to update the GUI GameData unknow message.
        */
        void updateUnknownMessage(const std::vector<std::string> &data);

        /**
         * @brief Update the GUI GameData command parameter.
         *
         * @param data The data to update the GUI GameData command parameter.
        */
        void updateCommandParameter(const std::vector<std::string> &data);
};
