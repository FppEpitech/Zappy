/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Inventory
*/

#pragma once

#include <iostream>

#define RessourcesNumber 6

using Ressources = size_t [RessourcesNumber];

namespace Gui {

    /**
     * @brief Inventory class of a player.
     *
     */
    class Inventory;
};

class Gui::Inventory {

    public:

        /**
         * @brief Construct a new Inventory object.
         *
         */
        Inventory();

        /**
         * @brief Construct a new Inventory object.
         *
         * @param food Food to set.
         * @param linemate Linemate to set.
         * @param deraumere Deraumere to set.
         * @param sibur Sibur to set.
         * @param mendiane Mendiane to set.
         * @param phiras Phiras to set.
         * @param thystame Thystame to set.
         */
        Inventory(std::size_t food, std::size_t linemate, std::size_t deraumere, std::size_t sibur, std::size_t mendiane, std::size_t phiras, std::size_t thystame);

        /**
         * @brief Destroy the Inventory object.
         *
         */
        ~Inventory() = default;

        /**
         * @brief Set the Food object.
         *
         * @param food Food to set.
         */
        void setFood(std::size_t food);

        /**
         * @brief Set the Linemate object.
         *
         * @param linemate Linemate to set.
         */
        void setLinemate(std::size_t linemate);

        /**
         * @brief Set the Deraumere object.
         *
         * @param deraumere Deraumere to set.
         */
        void setDeraumere(std::size_t deraumere);

        /**
         * @brief Set the Sibur object.
         *
         * @param sibur Sibur to set.
         */
        void setSibur(std::size_t sibur);

        /**
         * @brief Set the Mendiane object.
         *
         * @param mendiane Mendiane to set.
         */
        void setMendiane(std::size_t mendiane);

        /**
         * @brief Set the Phiras object.
         *
         * @param phiras Phiras to set.
         */
        void setPhiras(std::size_t phiras);

        /**
         * @brief Set the Thystame object.
         *
         * @param thystame Thystame to set.
         */
        void setThystame(std::size_t thytsame);

        /**
         * @brief Set the Ressources object.
         *
         * @param ressources Ressources to set.
         */
        void setRessources(Ressources ressources);

        /**
         * @brief Get the Food object.
         *
         * @return std::size_t - food
         */
        std::size_t getFood(void);

        /**
         * @brief Get the Linemate object.
         *
         * @return std::size_t - linemate
         */
        std::size_t getLinemate(void);

        /**
         * @brief Get the Deraumere object.
         *
         * @return std::size_t - deraumere
         */
        std::size_t getDeraumere(void);

        /**
         * @brief Get the Sibur object.
         *
         * @return std::size_t - sibur
         */
        std::size_t getSibur(void);

        /**
         * @brief Get the Mendiane object.
         *
         * @return std::size_t - mendiane
         */
        std::size_t getMendiane(void);

        /**
         * @brief Get the Phiras object.
         *
         * @return std::size_t - phiras
         */
        std::size_t getPhiras(void);

        /**
         * @brief Get the Thystame object.
         *
         * @return std::size_t - thystame
         */
        std::size_t getThystame(void);

        /**
         * @brief Get the Ressources object.
         *
         * @return Ressources - ressources
        */
        Ressources &getRessources(void);

    private:

        std::size_t     _food;    // Food.
        Ressources      _ressources;    // Ressources.
};
