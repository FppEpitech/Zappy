/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** IEvent
*/

#pragma once

#include "Render/Render.hpp"
#include "GameDatas/GameData.hpp"
#include <memory>

namespace Gui {

    /**
     * @brief Interface for Event class.
     *
     */
    class IEvent;
}

class Gui::IEvent {

    public:

        /**
         * @brief Construct a new IEvent object.
         *
         */
        IEvent() = default;

        /**
         * @brief Destroy the IEvent object.
         *
         */
        virtual ~IEvent() = default;

        /**
         * @brief Listen the user's events.
         *
         */
        virtual void listen() = 0;

        /**
         * @brief Set the Render object.
         *
         * @param render Render class.
         */
        virtual void setRender(std::shared_ptr<Render> render) = 0;

        /**
         * @brief Set the GameData object.
         *
         * @param gameData GameData class.
         */
        virtual void setGameData(std::shared_ptr<GameData> gameData) = 0;
};
