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
         */
        void display(std::pair<std::size_t, std::size_t> mapSize, size_t renderDistance, std::pair<std::size_t, std::size_t> camPos);

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

        Model                                   _treeModel;         // Tree model asset.
        Map<bool>                               _mapTree;           // Map to display trees.
        Model                                   _lanternModel;      // Lantern model asset.
        Map<bool>                               _mapLantern;        // Map to display lanterns.

        std::pair<std::size_t, std::size_t>     _mapSize;           // Size of the map.

        /**
         * @brief Display Trees.
         *
         * @param i Index width in map.
         * @param j Index height in map.
         * @param posTile Position of a tile.
         */
        void displayTree(size_t i, size_t j, Vector3 posTile);

        /**
         * @brief Display Lanterns.
         *
         * @param i Index width in map.
         * @param j Index height in map.
         * @param posTile Position of a tile.
         */
        void displayLantern(size_t i, size_t j, Vector3 posTile);
};
