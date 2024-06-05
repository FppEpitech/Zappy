/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Render
*/

#pragma once

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_TITLE "Zappy GUI"

#include "raylib.h"
#include "Render/UserCamera.hpp"
#include "GameDatas/GameData.hpp"

namespace Gui {

    /**
     * @brief Render class to display Zappy.
     *
     */
    class Render;
};

class Gui::Render {

    public:

        /**
         * @brief Construct a new Render object.
         *
         */
        Render(std::shared_ptr<GameData> gameData);

        /**
         * @brief Destroy the Render object.
         *
         */
        ~Render();

        /**
         * @brief Check if the window is open.
         *
         * @return true - the window is open
         * @return false - the window is closed
         */
        bool isOpen();

        /**
         * @brief Draw the scene.
         *
         */
        void draw();

        /**
         * @brief Get the Camera object.
         *
         * @return std::shared_ptr<Camera> - camera
         */
        std::shared_ptr<Camera> getCamera();

        /**
         * @brief Set the Is Debug object.
         *
         * @param isDebug New Is Debug value to set.
         */
        void setIsDebug(bool isDebug);

        /**
         * @brief Get the Is Debug object.
         *
         * @return true - diplay debug
         * @return false - do not display debug
         */
        bool getIsDebug(void);

    private:

        UserCamera                  _camera;    // Camera of the scene.
        bool                        _isDebug;   // Display or not the debug informations.
        std::shared_ptr<GameData>   _gameData;  // GameData class to store the game's data.

        Model                       _tileModel; // Model to display for tiles.
        Model                       _foodModel; // Model to display for food.

        /**
         * @brief Load the models to draw.
         *
         */
        void LoadModels(void);

        /**
         * @brief Display the debug interface.
         *
         */
        void displayDebug(void);

        /**
         * @brief Display the map.
         *
         */
        void displayMap();

        /**
         * @brief Display the food.
         *
         */
        void displayFood(Tile tile);
};
