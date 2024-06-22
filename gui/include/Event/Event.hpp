/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Event
*/

#pragma once

#include "Config.hpp"
#include "Event/AEvent.hpp"
#include "Render/Render.hpp"

#include <functional>
#include <unordered_map>

namespace Gui {

    /**
     * @brief Event class to handle keyboard and mouses events.
     *
     */
    class Event;
};

class Gui::Event : public Gui::AEvent {

    public:

        /**
         * @brief Construct a new Event object.
         *
         */
        Event();

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

        /**
         * @brief Map for events by down key.
         *
         */
        std::unordered_map<KeyboardKey, std::function<void()>> _eventsKeyDown =
        {
            {KEY_SPACE, [this](){moveUpCamera();}},
            {KEY_LEFT_SHIFT, [this](){moveDownCamera();}},
        };

        std::unordered_map<GamepadButton, std::function<void()>> _eventsGamepadButtonDown =
        {
            {GAMEPAD_BUTTON_RIGHT_TRIGGER_2, [this](){handleSpaceGamepad();}},
            {GAMEPAD_BUTTON_LEFT_TRIGGER_2, [this](){moveDownCamera();}},
        };

        /**
         * @brief Map for events by pressing key.
         *
         */
        std::unordered_map<KeyboardKey, std::function<void()>> _eventsKeyPressed =
        {
            {KEY_THREE, [this](){switchDisplayDebug();}},
            {KEY_F3, [this](){switchDisplayDebug();}},
            {KEY_SPACE, [this](){setFreeCam();}},
            {KEY_R, [this](){switchTileHudToGame();}},
            {KEY_J, [this](){increaseRenderDistance();}},
            {KEY_K, [this](){decreaseRenderDistance();}},
            {KEY_F5, [this](){changeActualPlayerPov();}},
            {KEY_FOUR, [this](){changeActualPlayerPov();}},
            {KEY_V, [this](){setPlayerVision();}},
            {KEY_KP_ADD, [this](){increaseTimeUnit();}},
            {KEY_KP_SUBTRACT, [this](){decreaseTimeUnit();}},
        };

        std::unordered_map<GamepadButton, std::function<void()>> _eventsGamepadButtonPressed =
        {
            {GAMEPAD_BUTTON_RIGHT_FACE_DOWN, [this](){handleLeftClick();}},
            {GAMEPAD_BUTTON_RIGHT_TRIGGER_1, [this](){handleLeftClick();}},
            {GAMEPAD_BUTTON_LEFT_TRIGGER_1, [this](){handleRightClick();}},
            {GAMEPAD_BUTTON_LEFT_FACE_UP, [this](){increaseRenderDistance();}},
            {GAMEPAD_BUTTON_LEFT_FACE_DOWN, [this](){decreaseRenderDistance();}},
            {GAMEPAD_BUTTON_LEFT_FACE_LEFT, [this](){decreaseTimeUnit();}},
            {GAMEPAD_BUTTON_LEFT_FACE_RIGHT, [this](){increaseTimeUnit();}},
            {GAMEPAD_BUTTON_RIGHT_FACE_LEFT, [this](){switchDisplayDebug();}},
            {GAMEPAD_BUTTON_RIGHT_FACE_RIGHT, [this](){switchTileHudToGame();}},
            {GAMEPAD_BUTTON_RIGHT_FACE_UP, [this](){changeActualPlayerPov();}},
            {GAMEPAD_BUTTON_MIDDLE_RIGHT, [this](){closeWindowGamepad();}},
        };

        /**
         * @brief Map for events by pressing mouse.
         *
         */
        std::unordered_map<MouseButton, std::function<void()>> _eventsMousePressed =
        {
            {MOUSE_BUTTON_LEFT, [this](){handleLeftClick();}},
            {MOUSE_BUTTON_RIGHT, [this](){handleRightClick();}}
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

        /**
         * @brief Set the free camera.
        */
        void setFreeCam();

        /**
         * @brief Handle the left click.
         *
        */
        void handleLeftClick();

        /**
         * @brief Handle the right click.
        */
        void handleRightClick();

        /**
         * @brief Select the player pov.
         *
         */
        void selectPlayer();

        /**
         * @brief Select the tile.
        */
        void selectTile();

        /**
         * @brief Change the player.
         *
         * @param turn Turn to select the player.
         */
        void changePlayer(bool turn);

        /**
         * @brief Change the actual player point of view.
         *
        */
        void changeActualPlayerPov();

        /**
         * @brief Change the Hud of Tile to Game.
         *
         */
        void switchTileHudToGame();

        /**
         * @brief Increase the render distance.
         *
         */
        void increaseRenderDistance();

        /**
         * @brief Decrease the render distance.
         *
         */
        void decreaseRenderDistance();

        /**
         * @brief Increase the time unit.
         *
        */
        void increaseTimeUnit();

        /**
         * @brief Decrease the time unit.
         *
         */
        void decreaseTimeUnit();

        /**
         * @brief Handle Space for Gamepad
         */
        void handleSpaceGamepad();

        /**
         * @brief Close the window for Gamepad
         */
        void closeWindowGamepad();

        /**
         * @brief Set the player vision.
         *
         */
        void setPlayerVision();
};
