/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Camera
*/

#pragma once

#include "raylib.h"

#include <memory>

namespace Gui {

    /**
     * @brief UserCamera class to handle the camera.
     *
     */
    class UserCamera;
};

class Gui::UserCamera {

    public:

        /**
         * @brief Construct a new User Camera object.
         *
         */
        UserCamera();

        /**
         * @brief Destroy the User Camera object.
         *
         */
        ~UserCamera() = default;

        /**
         * @brief Set the Position object.
         *
         * @param position New camera position.
         */
        void setPosition(Vector3 position);

        /**
         * @brief Set the Target object.
         *
         * @param target New camera target.
         */
        void setTarget(Vector3 target);

        /**
         * @brief Set the Up object.
         *
         * @param up New camera up vector.
         */
        void setUp(Vector3 up);

        /**
         * @brief Set the Fovy object.
         *
         * @param fovy New camera fovy.
         */
        void setFovy(float fovy);

        /**
         * @brief Get the Position object.
         *
         * @return Vector3 - position
         */
        Vector3 getPosition(void) const;

        /**
         * @brief Get the Target object.
         *
         * @return Vector3 - target
         */
        Vector3 getTarget(void) const;

        /**
         * @brief Get the Up object.
         *
         * @return Vector3 - up
         */
        Vector3 getUp(void) const;

        /**
         * @brief Get the Fovy object.
         *
         * @return float - fovy
         */
        float getFovy(void) const;

        /**
         * @brief Get the Camera object.
         *
         * @return Camera - camera
         */
        std::shared_ptr<Camera> getCamera();

    private:

        std::shared_ptr<Camera>     _camera;
};