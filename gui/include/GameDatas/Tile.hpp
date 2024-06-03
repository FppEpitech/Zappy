/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Tile
*/

#pragma once

#include "GameDatas/Inventory.hpp"

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
        std::pair<std::size_t, std::size_t> getPosition(void);

        /**
         * @brief Inventory of the tile.
         *
         */
        Inventory       _inventory;

    private:

        std::pair<std::size_t, std::size_t>     _position;  // Position x y.
};