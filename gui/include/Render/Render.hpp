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
        Render();

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

    private:

        UserCamera      _camera;    // Camera of the scene.
};
