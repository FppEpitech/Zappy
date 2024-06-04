/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Event
*/

#pragma once

#include "Render/Render.hpp"

#include <functional>
#include <unordered_map>

#define HIGH_CAMERA_INCREASE 0.1
#define LOW_CAMERA_INCREASE 0.1

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

        std::shared_ptr<Render>       _render;  // Render class to draw scene.

        /**
         * @brief Map for events by down key.
         *
         */
        std::unordered_map<KeyboardKey, std::function<void()>> _eventsKeyDown =
        {
            {KEY_SPACE, [this](){moveUpCamera();}},
            {KEY_LEFT_SHIFT, [this](){moveDownCamera();}}
        };

        /**
         * @brief Map for events by pressing key.
         *
         */
        std::unordered_map<KeyboardKey, std::function<void()>> _eventsKeyPressed =
        {
            {KEY_THREE, [this](){switchDisplayDebug();}},
            {KEY_F3, [this](){switchDisplayDebug();}}
        };

        /**
         * @brief Move up the camera.
         *
         */
        void moveUpCamera();

        /**
         * @brief Move down the camera.
         *
         */
        void moveDownCamera();

        /**
         * @brief Switch on/off the debug display.
         *
         */
        void switchDisplayDebug();
};
