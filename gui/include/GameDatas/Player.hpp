/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Player
*/

#pragma once

#include "raylib.h"
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

        enum PlayerState {
            IDLE = 2,
            BORN = 8,
            BROADCAST = 12,
            EJECT = 5,
            BEING_EJECTED = 15,
            EJECTED = 7,
            WALK = 6, // or 10
            INCANTATION = 0,
            LAY_EGG = 7,
            DROP = 9,
            COLLECT = 9,
            DEAD = 1,
        };

        /**
         * @brief Construct a new Player object.
         *
         * @param id Id of the player.
         * @param team Team name of the player.
         * @param position Position of the Player.
         */
        Player(std::size_t id, const std::string &team, std::pair<std::size_t, std::size_t> position, std::size_t orientation, std::size_t level = 1);

        /**
         * @brief Destroy the Player object.
         *
         */
        ~Player() = default;

        /**
         * @brief Set the Position object.
         *
         * @param position Position of the player.
         */
        void setPosition(std::pair<std::size_t, std::size_t> position);

        /**
         * @brief Set the Position3D object.
         *
         * @param position3D Position of the player.
         */
        void setPosition3D(Vector3 position3D);

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
         * @brief Set the Orientation object.
         *
         * @param orientation Orientation of the player.
         */
        void setOrientation(std::size_t orientation);

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
         * @brief Get the Position3D object.
         *
         * @return Vector3 - position3D
         */
        Vector3 getPosition3D(void) const;

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
         * @brief Get the Orientation object.
         *
         * @return std::size_t - orientation
         */
        std::size_t getOrientation(void) const;

        /**
         * @brief Get the Team object.
         *
         * @return std::string - team name
         */
        std::string getTeam(void) const;

        /**
         * @brief Set the State object.
         *
         * @param state New player state.
         */
        void setState(PlayerState state);

        /**
         * @brief Get the State object.
         *
         * @return PlayerState - Player state.
         */
        PlayerState getState(void) const;

        /**
         * @brief Set the Broadcast object.
         *
         * @param broadcast New broadcast message.
         */
        void setBroadcast(const std::string &broadcast);

        /**
         * @brief Get the Broadcast object.
         *
         * @return std::string - Broadcast message.
         */
        std::string getBroadcast() const;

        /**
         * @brief Get the Vector From Orientation object.
         *
         * @return Vector3 - Vector3 from orientation.
         */
        float getRotationFromOrientation() const;

        /**
         * @brief Get the Center Position object.
         *
         * @return Vector3 - Center position.
         */
        Vector3 getCenterPosition();

        /**
         * @brief Set the Current Frame object.
         *
         * @param currentFrame Current Frame to set.
         */
        void setCurrentFrame(int currentFrame);

        /**
         * @brief Get the Current Frame object.
         *
         * @return int - Current frame.
         */
        int getCurrentFrame() const;

        /**
         * @brief Restart the timer animation.
         *
         */
        void restartAnimationTimeEllapsed();

        /**
         * @brief Get the Animation Time Ellapsed object.
         *
         * @return clock_t - Animation time ellapsed.
         */
        clock_t getAnimationTimeEllapsed() const;

        /**
         * @brief Inventory of the player.
         *
         */
        Inventory                               inventory;

    private:

        std::size_t                             _id;                    //!< Id of the player.
        std::string                             _team;                  //!< Team name.
        std::pair<std::size_t, std::size_t>     _position;              //!< Position x y relative to tiles.
        Vector3                                 _position3D;            //!< Position in 3D scene.
        std::size_t                             _orientation;           //!< Orientation of the player.
        std::size_t                             _level;                 //!< Level between 1 - 8.
        PlayerState                             _state;                 //!< Player state.
        std::string                             _broadcast;             //!< Broadcast message.
        int                                     _currentFrame;          //!< Current frame animation.
        clock_t                                 _animationTimeEllapsed; //!< Time ellapsed during animation.
};
