/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Egg
*/

#pragma once

#include "Error/Error.hpp"

#include <string>

namespace Gui {

    /**
     * @brief Egg class.
    */
    class Egg;
};

class Gui::Egg {

    public:

        enum EggState {
            IDLE,
            DEAD,
            BORN,
            HATCHING,
        };

        /**
         * @brief Construct a new Egg object.
         *
         * @param id Id of the egg.
         * @param team Team name of the egg.
         * @param position Position of the egg.
         *
         * @note The egg is created when a player lays an egg.
         * @note The constructor starts the egg animation if implemented.
         */
        Egg(size_t id, const std::string &team, std::pair<std::size_t, std::size_t> position);

        /**
         * @brief Destroy the Egg object.
         *
         * @note The destructor starts the egg animation if implemented.
         */
        ~Egg();

        /**
         * @brief Get the Id object.
         *
         * @return std::size_t Id of the egg.
         */
        std::size_t getId() const;

        /**
         * @brief Get the Team object.
         *
         * @return std::string Team name of the egg.
         */
        std::string getTeam() const;

        /**
         * @brief Get the Position object.
         *
         * @return std::pair<std::size_t, std::size_t> Position of the egg.
         */
        std::pair<std::size_t, std::size_t> getPosition() const;

        /**
         * @brief Set the id object.
         *
         * @param id Id of the egg.
         */
        void setId(std::size_t id);

        /**
         * @brief Set the team object.
         *
         * @param team Team name of the egg.
         */
        void setTeam(const std::string &team);

        /**
         * @brief Set the position object.
         *
         * @param position Position of the egg.
         */
        void setPosition(std::pair<std::size_t, std::size_t> position);

        /**
         * @brief Set the state object.
         *
         * @param state State of the egg.
         */
        void setState(EggState state);

        /**
         * @brief Get the state object.
         *
         * @return EggState State of the egg.
         */
        EggState getState() const;

    private:

        std::size_t                             _id;        // Id of the egg.
        std::string                             _team;      // Team name of the egg.
        std::pair<std::size_t, std::size_t>     _position;  // Position of the egg.
        EggState                                _state;     // State of the egg.
};