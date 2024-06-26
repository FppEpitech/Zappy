/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GameData
*/

#pragma once

#include "Types.hpp"
#include "Error/Error.hpp"
#include "GameDatas/Team.hpp"
#include "GameDatas/Tile.hpp"

#define NO_TICK int(-1)

namespace Gui {

    /**
     * @brief GameData class.
     *
    */
    class GameData;
};

class Gui::GameData {

    public:

        enum TimeUnitState {
            INCREASE,
            DECREASE,
            NONE
        };

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
         * @param playerColor Color of the team.
         */
        void addTeam(const std::string &name, Color playerColor);

        /**
         * @brief Add a player to a team.
         *
         * @param teamName Name of the team.
         * @param player Player to add.
         */
        void addPlayerToTeam(const std::string &teamName, const Gui::Player &player);

        /**
         * @brief Get a player object.
         *
         * @param id Id of the player.
        */
        Gui::Player &getPlayer(size_t id);

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

        /**
         * @brief Set the IsEnd Game object.
         *
         * @param isEndGame EndGame state.
         */
        void setIsEndGame(bool isEndGame);

        /**
         * @brief Get the IsEnd Game object.
         *
         * @return true - The game is finished.
         * @return false - The game continue.
         */
        bool getIsEndGame() const;

        /**
         * @brief Set the Last Error object.
         *
         * @param error Error message.
         */
        void setLastError(const std::string &error);

        /**
         * @brief Get the Last Error object.
         *
         * @return std::string - Last error message.
         */
        std::string getLastError() const;

        /**
         * @brief Get the Team From Player object.
         *
         * @param id Id of the player.
         * @return Gui::Team& Team of the player.
        */
        Team &getTeamById(std::size_t id);

        /**
         * @brief Get the Time Unit From Server object.
         *
         * @return true - The time unit has changed.
        */
        TimeUnitState getTimeUnitFromServer() const;

        /**
         * @brief Set the Time Unit From Server object.
         *
         * @param timeUnitFromServer Time unit state.
        */
        void setTimeUnitFromServer(TimeUnitState timeUnitFromServer);

        /**
         * @brief Get the Server Eggs object.
         *
         * @return std::vector<Gui::Egg>& Eggs from the server.
        */
        std::vector<Gui::Egg> &getServerEggs();

        /**
         * @brief Add an egg to the server ones.
         *
         * @param egg Egg to add.
        */
        void addServerEgg(const Gui::Egg &egg);

        /**
         * @brief Remove an egg from the server ones.
         *
         * @param id Id of the egg.
        */
        void removeServerEgg(size_t id);

        /**
         * @brief Set the number of bct command received.
         *
         * @param nb Number of bct command received.
         */
        void setNbBCTCommandReceived(std::size_t nb);

        /**
         * @brief Get the number of bct command received.
         *
         * @return std::size_t - Number of bct command received.
         */
        std::size_t getNbBCTCommandReceived() const;

        /**
         * @brief Restart the last tick mct command clock.
         *
         */
        void restartLastTickMctCommand();

        /**
         * @brief Get the Last Tick mct command object.
         *
         * @return clock_t - Last Tick Mct command.
         */
        clock_t getLastTickMctCommand() const;

        /**
         * @brief Set the End Message object.
         *
         * @param endMessage End message of the game.
         */
        void setEndMessage(const std::string &endMessage);

        /**
         * @brief Get the End Message object.
         *
         * @return std::string - End message of the game.
         */
        std::string getEndMessage() const;

        /**
         * @brief Set the Player Model object.
         *
         * @param playerModel Model asset of the Team.
         */
        void setPlayerModel(const Model &playerModel);

        /**
         * @brief Set the Egg Model object.
         *
         * @param eggModel Model asset of the Team.
         */
        void setEggModel(const Model &eggModel);

        /**
         * @brief Set the Player Model Animation object.
         *
         * @param playerModelAnimation Model to animate players.
         */
        void setPlayerModelAnimation(ModelAnimation *playerModelAnimation);

        /**
         * @brief Get the Player Model Animation object.
         *
         * @return ModelAnimation* - Model to animate players.
         */
        void setAnimsCount(int animsCount);

        /**
         * @brief Get the Anims Count object.
         *
         * @return int - Animation number of players.
         */
        void setServerError(bool isServerError);

        /**
         * @brief Get the Server Error object.
         *
         * @return bool - True if the server is in error.
         */
        bool getServerError() const;

    private:

        std::vector<Gui::Team>      _teams;                 //!< Teams of the game.
        Map<Gui::Tile>              _map;                   //!< Map of the game.
        std::size_t                 _serverTick;            //!< Tick value of the server.
        clock_t                     _lastTick;              //!< Last tick of the GameData (based on the server tick).
        bool                        _isEndGame;             //!< Is true if the game is finished.
        std::size_t                 _nbBCTCommandReceived;  //!< Number of bct command received.
        clock_t                     _lastTickMctCommand;    //!< Last tick when mct command is send.
        std::string                 _lastError;             //!< Last error message.
        TimeUnitState               _timeUnitFromServer;    //!< True if the time unit has changed.
        std::vector<Gui::Egg>       _serverEggs;            //!< Eggs from the server.
        std::string                 _endMessage;            //!< End message of the game.
        Model                       _playerModel;           //!< Model asset of the Team.
        Model                       _eggModel;              //!< Model asset of the Team.
        ModelAnimation*             _playerModelAnimation;        //!< Model to animate players.
        int                         _animsCount;            //!< Animation number of players.
        bool                        _isServerError;         //!< True if the server is in error.
};
