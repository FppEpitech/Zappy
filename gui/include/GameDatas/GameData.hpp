/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GameData
*/

#pragma once

#include "Error/Error.hpp"
#include "GameDatas/Team.hpp"
#include "GameDatas/Tile.hpp"

#define NO_TICK int(-1)

/**
 * @brief Map type.
 *
 * @tparam T Type of the map.
*/
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
         * @brief Add a player to a team.
         *
         * @param teamName Name of the team.
         * @param player Player to add.
         */
        void addPlayerToTeam(const std::string &teamName, const Gui::Player &player);

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
         * @brief Set the Map Size object.
         *
         * @param x X size of the map.
         * @param y Y size of the map.
         * @note This method resizes the map.
         */
        void setMapSize(size_t x, size_t y);

        /**
         * @brief Get the Map Size object.
         *
         * @return std::pair<size_t, size_t> Size of the map.
         */
        std::pair<size_t, size_t> getMapSize() const;

        /**
         * @brief Get a Tile object.
         *
         * @param x X position of the tile.
         * @param y Y position of the tile.
         * @return Gui::Tile& Tile object.
         */
        Gui::Tile &getTile(size_t x, size_t y);

        /**
         * @brief Set the Tile object.
         *
         * @param x X position of the tile.
         * @param y Y position of the tile.
         * @param tile Tile to set.
         */
        void setTile(const Gui::Tile &tile);

        /**
         * @brief Restart the last tick clock.
         *
         */
        void restartLastTick(void);

        /**
         * @brief Set the Server Tick object.
         *
         * @param tick Tick of the server.
         */
        void setServerTick(std::size_t tick);

        /**
         * @brief Get the Last Tick object.
         *
         * @return clock_t - Last Tick.
         */
        clock_t getLastTick() const;

        /**
         * @brief Get the Server Tick object.
         *
         * @return std::size_t - Server Tick.
         */
        std::size_t getServerTick() const;

    private:

        std::vector<Gui::Team>      _teams;         // Teams of the game.
        Map<Gui::Tile>              _map;           // Map of the game.
        std::size_t                 _serverTick;    // Tick value of the server.
        clock_t                     _lastTick;      // Last tick of the GameData (based on the server tick).
};
