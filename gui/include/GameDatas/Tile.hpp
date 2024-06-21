/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Tile
*/

#pragma once

#include "raylib.h"
#include "GameDatas/Inventory.hpp"

#include <vector>

namespace Gui {

    /**
     * @brief Tile class to handle the tile of the map.
     *
     */
    class Tile;
};

class Gui::Tile {

    public:

        /**
         * @brief Construct a new Tile object.
         *
         * @param position Set the position of the tile.
         */
        Tile(std::pair<std::size_t, std::size_t> position);

        /**
         * @brief Construct a new Tile object.
         *
         * @param position Set the position of the tile.
         * @param inventory Set the inventory of the tile.
         */
        Tile(std::pair<std::size_t, std::size_t> position, Inventory inventory);

        /**
         * @brief Destroy the Tile object.
         *
         */
        ~Tile() = default;

        /**
         * @brief Set the Position object.
         *
         * @param position New position of the tile.
         */
        void setPosition(std::pair<std::size_t, std::size_t> position);

        /**
         * @brief Get the Position object.
         *
         * @return std::pair<std::size_t, std::size_t> - position x y
         */
        std::pair<std::size_t, std::size_t> getPosition() const;

        /**
         * @brief Get the Position In Space object.
         *
         * @return Vector3 - Position in space.
         */
        Vector3 getPositionIn3DSpace();

        /**
         * @brief Get the Tile Bounding Boxes object.
         *
         * @param tile Tile to get the bounding boxes.
         * @return std::vector<BoundingBox> - Bounding boxes of the tile.
        */
        std::vector<BoundingBox> getTileBoundingBoxes(Tile tile, Model tileModel);

        /**
         * @brief Get the Tile Model Hitbox object.
         *
         * @param tile Tile to get the hitbox.
         * @param camera Camera to get the hitbox.
         * @return std::vector<RayCollision> - Hitbox of the tile.
         */
        std::vector<RayCollision> getTileModelHitbox(Tile tile, Camera camera, Model tileModel);

        /**
         * @brief Check if the tile is hit.
         *
         * @param camera Camera to check if the tile is hit.
         * @param _tileModel Model of the tile.
         * @return true - The tile is hit.
         * @return false - The tile is not hit.
         */
        bool isTileHit(Camera camera, Model _tileModel);

        /**
         * @brief Inventory of the tile.
         *
         */
        Inventory       inventory;

    private:

        std::pair<std::size_t, std::size_t>     _position;              //!< Position x y.
        Vector3                                 _positionIn3DSpace;     //!< Position in 3D space.
};
