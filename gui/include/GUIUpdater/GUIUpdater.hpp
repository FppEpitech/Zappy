/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GUIUpdater
*/

#pragma once

#include "GameDatas/GameData.hpp"

#include <string>
#include <memory>

namespace Gui {

    /**
     * @brief GUIUpdater class
     *
     * This class is used to update the GUI GameData to ensure the GUI is up to date
     */
    class GUIUpdater;
}

class Gui::GUIUpdater {

    public:

        /**
         * @brief Construct a new GUIUpdater object
         *
         * @param gameData The GUI GameData to update
        */
        GUIUpdater(std::shared_ptr<GameData> gameData);

        /**
         * @brief Destroy the GUIUpdater object
        */
        ~GUIUpdater() = default;

        /**
         * @brief Update the GUI GameData
         *
         * @param command The command to update the GUI GameData
         * @param data The data to update the GUI GameData
        */
        void update(const std::string &command, const std::string &data);

    private:

        std::shared_ptr<GameData> _gameData;
};
