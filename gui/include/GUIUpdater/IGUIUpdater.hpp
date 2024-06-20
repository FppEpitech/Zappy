/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** IGUIUpdater
*/

#pragma once

#include <string>
#include <vector>

namespace Gui {

    /**
     * @brief IGUIUpdater class.
     *
     */
    class IGUIUpdater;
}

class Gui::IGUIUpdater {
    public:
        /**
         * @brief Destroy the IGUIUpdater object.
         */
        virtual ~IGUIUpdater() = default;

        /**
         * @brief Update the GUI GameData.
         *
         */
        virtual void update(const std::string &command, const std::vector<std::string> &data) = 0;
};
