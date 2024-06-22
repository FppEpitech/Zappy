/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Decoration
*/

#pragma once

#include "raylib.h"
#include "Types.hpp"
#include "Assets.hpp"

#include <vector>
#include <iostream>

namespace Gui {

    /**
     * @brief Decoration class.
     *
     * This class is used to display simple decoration on map.
     */
    class Decoration;
}

class Gui::Decoration {

    public:

        /**
         * @brief Construct a new Decoration object.
         *
         */
        Decoration();

        /**
         * @brief Destroy the Decoration object.
         *
         */
        ~Decoration() = default;

        /**
         * @brief Display decorations.
         *
         * @param mapSize Size of the map.
         * @param renderDistance Distance to render.
         * @param camPos Position of the camera.
         * @param displayPos Positions to know what to display.
         */
        void display(std::pair<std::size_t, std::size_t> mapSize, size_t renderDistance, std::pair<std::size_t, std::size_t> camPos, std::vector<Vector2> displayPos);

        /**
         * @brief Generate random emplacement for decorations.
         *
         * @param ratio Ratio fo random emplacement.
         * If ratio = 10 for a tree, there will be one
         * chance at a ten to have a tree on the tile.
         * @return Map<bool> - Boolean list to display item.
         */
        Map<bool> getGenerationItem(std::size_t ratio);

    private:

        Model                                   _treeModel;         //!< Tree model asset.
        Map<bool>                               _mapTree;           //!< Map to display trees.

        std::pair<std::size_t, std::size_t>     _mapSize;           //!< Size of the map.

        /**
         * @brief Display Trees.
         *
         * @param i Index width in map.
         * @param j Index height in map.
         * @param posTile Position of a tile.
         */
        void displayTree(size_t i, size_t j, Vector3 posTile);

        /**
         * @brief Check if a position is in player vision.
         *
         * @param position Position to check.
         * @param _playerVisionPositions Positions of player vision.
         * @return true - Position is in player vision.
         * @return false - Position is not in player vision.
        */
        bool isInArrayPlayerVision(std::pair<size_t, size_t> pos, std::vector<Vector2> _playerVisionPositions);
};
