/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Team
*/

#pragma once

#include "raylib.h"
#include "GameDatas/Egg.hpp"
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
         * @param eggSkinPath Path to the skin of the team.
         */
        Team(const std::string &name, const std::string &eggModelPath);

        // TODO: Add the necessity to set a skin for the team.

        /**
         * @brief Destroy the Team object.
         *
         */
        ~Team();

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
         * @brief Get the Eggs object.
         *
         * @return std::vector<Gui::Egg>& Eggs of the team.
        */
        std::vector<Gui::Egg> &getEggs();

        /**
         * @brief Set the Name object.
         *
         * @param name Name of the team.
        */
        void setName(const std::string &name);

        /**
         * @brief Add a player to the team.
         *
         * @param player Player to add.
        */
        void addPlayer(const Gui::Player &player);

        /**
         * @brief Add an egg to the team.
         *
         * @param egg Egg to add.
        */
        void addEgg(const Gui::Egg &egg);

        /**
         * @brief Remove a player from the team.
         *
         * @param id Id of the player to remove.
         * @return true If the player has been removed.
         * @return false If the player has not been removed.
        */
        bool removePlayer(std::size_t id);

        /**
         * @brief Remove an egg from the team.
         *
         * @param id Id of the egg to remove.
         * @return true If the egg has been removed.
         * @return false If the egg has not been removed.
        */
        bool removeEgg(std::size_t id);

        /**
         * @brief Get the Player object.
         *
         * @param id Id of the player.
         * @return std::shared_ptr<Gui::Player> Player.
        */
        std::shared_ptr<Gui::Player> getPlayer(std::size_t id);

        /**
         * @brief Get the Egg object.
         *
         * @param id Id of the egg.
         * @return std::shared_ptr<Gui::Egg> Egg.
        */
        std::shared_ptr<Gui::Egg> getEgg(std::size_t id);

        /**
         * @brief Get the Egg Model Path object.
         *
         * @return const std::string& Path to the eggs Model of the team.
         */
        Model getEggModel() const;

        /**
         * @brief Set the Egg Model Path object.
         *
         * @param eggSkinPath Path to the eggs Model of the team.
         */
        void setEggModelPath(const std::string &eggModelPath);

        // TODO: Add a setter and a getter for the skin of the team.

    private:

        std::string _name; // Name of the team.
        std::vector<Gui::Player> _players; // Players of the team.
        std::vector<Gui::Egg> _eggs; // Eggs of the team.
        Model _eggModel; // Eggs Model of the team.
        // TODO: Add a skin for the team using raylib.
};
