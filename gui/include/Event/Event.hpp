/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Event
*/

#pragma once

#include "Render/Render.hpp"

namespace Gui {

    /**
     * @brief Event class to handle keyboard and mouses events.
     *
     */
    class Event;
};

class Gui::Event {

    public:

        /**
         * @brief Construct a new Event object.
         *
         */
        Event(std::shared_ptr<Render> render);

        /**
         * @brief Destroy the Event object.
         *
         */
        ~Event() = default;

        /**
         * @brief Listen the user's events.
         *
         */
        void listen();

    private:

        std::shared_ptr<Render>       _render;

        /**
         * @brief Handle space event.
         *
         */
        void spaceEvent();

        /**
         * @brief Handle shift event.
         *
         */
        void shiftEvent();

        /**
         * @brief Handle debug event (F3).
         *
         */
        void debugEvent();
};
