/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Team
*/

#pragma once

#include "GameDatas/Player.hpp"

#include <vector>
#include <memory>

namespace Gui {

    /**
     * @brief Team class.
     *
    */
    class Team;
};

class Gui::Team {

    public:

        /**
         * @brief Construct a new Team object.
         *
         * @param name Name of the team.
         */
        Team(const std::string &name);

        // TODO: Add the necessity to set a skin for the team.

        /**
         * @brief Destroy the Team object.
         *
         */
        ~Team() = default;

        /**
         * @brief Get the Name object.
         *
         * @return const std::string& Name of the team.
         */
        const std::string &getName() const;

        /**
         * @brief Get the Players object.
         *
         * @return std::vector<Gui::Player>& Players of the team.
        */
        std::vector<Gui::Player> &getPlayers();

        /**
         * @brief Add a player to the team.
         *
         * @param player Player to add.
        */
        void addPlayer(const Gui::Player &player);

        /**
         * @brief Remove a player from the team.
         *
         * @param id Id of the player to remove.
         * @return true If the player has been removed.
         * @return false If the player has not been removed.
        */
        bool removePlayer(std::size_t id);

        /**
         * @brief Get the Player object.
         *
         * @param id Id of the player.
         * @return std::shared_ptr<Gui::Player> Player.
        */
        std::shared_ptr<Gui::Player> getPlayer(std::size_t id);

        // TODO: Add a setter and a getter for the skin of the team.

    private:

        std::string _name; // Name of the team.
        std::vector<Gui::Player> _players; // Players of the team.
        // TODO: Add a skin for the team using raylib.
};
