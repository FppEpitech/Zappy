/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Team
*/

#pragma once

#include "raylib.h"
#include "Types.hpp"
#include "GameDatas/Egg.hpp"
#include "GameDatas/Tile.hpp"
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
         * @param playerModel Model asset of the team.
         * @param eggSkin Model asset of the eggs.
         * @param playerColor Color of the players.
         */
        Team(const std::string &name, Model playerModel, Model eggModel, ModelAnimation *modelAnimation, Color playerColor);

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
         * @brief Get the Model object.
         *
         * @return Model - Model asset of the Team.
         */
        Model getPlayerModel() const;

        /**
         * @brief Get the Player Model Animation object.
         *
         * @return ModelAnimation* - Players' animations.
         */
        ModelAnimation *getPlayerModelAnimation() const;

        /**
         * @brief Set the Model object.
         *
         * @param playerModelPath Path to the team model asset for players.
         */
        void setPlayerModelPath(const std::string &playerModelPath);

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

        /**
         * @brief Get the Player Boundig Boxes object.
         *
         * @param pos Position of the player.
         * @param orientation Orientation of the player.
         * @return std::vector<BoundingBox> Bounding boxes of the player.
        */
        std::vector<BoundingBox> getPlayerBoundingBoxes(std::pair<size_t, size_t> pos, size_t orientation, Vector3 center);

        /**
         * @brief Get the Player position in 3D space.
         *
         * @param id Id of the player.
         * @param map Map of the game.
        */
        Vector3 getPlayerPositionIn3DSpace(size_t id, Map<Tile> map);

        /**
         * @brief Get the Player Model hitbox.
         *
         * @param id Id of the player.
         * @param camera Camera of the game.
         * @return std::vector<RayCollision> Hitbox of the player.
        */
        std::vector<RayCollision> getPlayerModelHitbox(size_t id, Camera camera);

        /**
         * @brief Check if the player is hit.
         *
         * @param id Id of the player.
         * @param camera Camera of the game.
         * @return true If the player is hit.
        */
        bool isPlayerHit(size_t id, Camera camera);

        /**
         * @brief Get the Player Color object.
         *
        */
        Color getPlayerColor() const;

    private:

        ModelAnimation*             _modelAnimation;    //!< Model to animate players.
        int                         _animsCount;        //!< Animation number of players.
        std::string                 _name;      //!< Name of the team.
        std::vector<Gui::Player>    _players;   //!< Players of the team.
        Model                       _playerModel;     //!< Model player asset of the team.
        std::vector<Gui::Egg>       _eggs;      //!< Eggs of the team.
        Model                       _eggModel;  //!< Eggs Model of the team.
        Color                       _playerColor;   //!< Color of the players.

        /**
         * @brief Rotate a bounding box by orientation.
         *
         * @param bbox Bounding box to rotate.
         * @param orientation Orientation of the player.
         * @param pos Position of the player.
         * @param center Center of the player.
         * @return BoundingBox Rotated bounding box.
        */
        BoundingBox rotateBoundingBoxByOrientation(BoundingBox bbox, size_t orientation, std::pair<size_t, size_t> pos, Vector3 center);
};
