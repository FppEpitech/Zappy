/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Event
*/

#pragma once

#include "Config.hpp"
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

class Gui::Event {

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

    private:

        std::shared_ptr<Render>         _render;    // Render class to draw scene.
        std::shared_ptr<GameData>       _gameData;  // GameData class to contain scene.

        /**
         * @brief Map for events by down key.
         *
         */
        std::unordered_map<KeyboardKey, std::function<void()>> _eventsKeyDown =
        {
            {KEY_SPACE, [this](){moveUpCamera();}},
            {KEY_LEFT_SHIFT, [this](){moveDownCamera();}},
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
            {KEY_APOSTROPHE, [this](){changeActualPlayerPov();}},
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
         * @brief Change the player point of view.
         *
         * @param playerId Player id to select.
         * @note The player point of view is the first person, second person and third person.
        */
        void changePlayerPOV(size_t playerId);

        /**
         * @brief Sets the Pov of the player.
         *
         * @param playerId Player id to select.
        */
        void setPlayerPov(size_t playerId);

        /**
         * @brief Change the actual player point of view.
         *
        */
        void changeActualPlayerPov();

        /**
         * @brief Change the camera to the player.
         *
         * @param player Player to select.
        */
        void changePOVToFirstPerson(size_t id);

        /**
         * @brief Change the camera to the player.
         *
         * @param player Player to select.
        */
        void changePOVToSecondPerson(size_t id);

        /**
         * @brief Change the camera to the player.
         *
         * @param player Player to select.
         */
        void changePOVToThirdPerson(size_t id);

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
};
