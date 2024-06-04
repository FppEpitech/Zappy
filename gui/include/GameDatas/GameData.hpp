/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GameData
*/

#pragma once

#include "GameDatas/Team.hpp"
#include "GameDatas/Tile.hpp"

template<typename T>
using Map = std::vector<std::vector<T>>;

namespace Gui {

    /**
     * @brief GameData class.
     *
    */
    class GameData;
};

class Gui::GameData {

    public:

        /**
         * @brief Construct a new GameData object.
         *
         */
        GameData();

        /**
         * @brief Destroy the GameData object.
         *
         */
        ~GameData() = default;

        /**
         * @brief Get the Teams object.
         *
         * @return std::vector<Gui::Team>& Teams of the game.
         */
        std::vector<Gui::Team> &getTeams();

        /**
         * @brief Get a Team object.
         *
         * @param name Name of the team.
         * @return Gui::Team& Team object.
         */
        Gui::Team &getTeam(const std::string &name);

        /**
         * @brief Add a team to the game.
         *
         * @param team Team to add.
         */
        void addTeam(const Gui::Team &team);

        /**
         * @brief Add a team to the game.
         *
         * @param name Name of the team.
         */
        void addTeam(const std::string &name);

        /**
         * @brief Get the Map object.
         *
         * @return Map<Gui::Tile>& Map of the game.
         */
        Map<Gui::Tile> &getMap();

        /**
         * @brief Set the Map object.
         *
         * @param map Map of the game.
         */
        void setMap(const Map<Gui::Tile> &map);

        /**
         * @brief Get a Tile object.
         *
         * @param x X position of the tile.
         * @param y Y position of the tile.
         * @return Gui::Tile& Tile object.
         */
        Gui::Tile &getTile(size_t x, size_t y);

    private:

        std::vector<Gui::Team> _teams;
        Map<Gui::Tile> _map;
};
