/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Decoration
*/

#pragma once

#include "raylib.h"
#include "Assets.hpp"

#include <vector>
#include <iostream>

/**
 * @brief Map type.
 *
 * @tparam T Type of the map.
*/
template<typename T>
using Map = std::vector<std::vector<T>>;

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

        Decoration();
        ~Decoration() = default;

        void display(std::pair<std::size_t, std::size_t> mapSize);
        Map<bool> getGenerationItem(std::size_t ratio);

    private:

        Model                                   _treeModel;
        Map<bool>                               _mapTree;
        Model                                   _lanternModel;
        Map<bool>                               _mapLantern;

        std::pair<std::size_t, std::size_t>     _mapSize;

        void displayTree(size_t i, size_t j, Vector3 posTile);
        void displayLantern(size_t i, size_t j, Vector3 posTile);
};
