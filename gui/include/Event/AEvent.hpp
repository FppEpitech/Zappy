/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AEvent
*/

#pragma once

#include "Event/IEvent.hpp"

namespace Gui {

    /**
     * @brief Abstract class for Event class.
     *
     */
    class AEvent;
}

class Gui::AEvent : public Gui::IEvent {

    public:

        /**
         * @brief Construct a new AEvent object.
         *
         */
        AEvent();

        /**
         * @brief Destroy the AEvent object.
         *
         */
        ~AEvent() = default;

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
        void setRender(std::shared_ptr<Render> render);

        /**
         * @brief Set the GameData object.
         *
         * @param gameData GameData class.
         */
        void setGameData(std::shared_ptr<GameData> gameData);

        /**
         * @brief Get the Render object.
         *
         * @return std::shared_ptr<Render> - Render class.
         */
        std::shared_ptr<Render> getRender();

        /**
         * @brief Get the GameData object.
         *
         * @return std::shared_ptr<GameData> - GameData class.
         */
        std::shared_ptr<GameData> getGameData();

    protected:

        std::shared_ptr<Render>         _render;        // Render class to draw scene.
        std::shared_ptr<GameData>       _gameData;      // GameData class to contain scene.
};
