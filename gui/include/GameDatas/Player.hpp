/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Player
*/

#pragma once

#include "GameDatas/Inventory.hpp"

namespace Gui {

    /**
     * @brief Player class.
     *
     */
    class Player;
};

class Gui::Player {

    public:

        /**
         * @brief Construct a new Player object.
         *
         * @param id Id of the player.
         * @param team Team name of the player.
         * @param position Position of the Player.
         */
        Player(std::size_t id, const std::string &team, std::pair<std::size_t, std::size_t> position);

        /**
         * @brief Destroy the Player object.
         *
         */
        ~Player() = default;

        /**
         * @brief Set the Position object.
         *
         * @param position Position of the player
         */
        void setPosition(std::pair<std::size_t, std::size_t> position);

        /**
         * @brief Set the Id object.
         *
         * @param id Id of the player.
         */
        void setId(std::size_t id);

        /**
         * @brief Set the Level object.
         *
         * @param level Level of the player.
         */
        void setLevel(std::size_t level);

        /**
         * @brief Set the Team object.
         *
         * @param team Team name of the player.
         */
        void setTeam(const std::string &team);

        /**
         * @brief Get the Position object.
         *
         * @return std::pair<std::size_t, std::size_t> - position
         */
        std::pair<std::size_t, std::size_t> getPosition(void) const;

        /**
         * @brief Get the Id object.
         *
         * @return std::size_t - id
         */
        std::size_t getId(void) const;

        /**
         * @brief Get the Level object.
         *
         * @return std::size_t - level
         */
        std::size_t getLevel(void) const;

        /**
         * @brief Get the Team object.
         *
         * @return std::string - team name
         */
        std::string getTeam(void) const;

        /**
         * @brief Inventory of the player.
         *
         */
        Inventory                               _inventory;

    private:

        std::pair<std::size_t, std::size_t>     _position;  // Position x y.
        std::size_t                             _id;        // Id of the player.
        std::size_t                             _level;     // Level between 1 - 8.
        std::string                             _team;      // Team name.
};
