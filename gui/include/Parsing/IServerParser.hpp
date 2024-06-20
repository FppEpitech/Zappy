/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** IServerParser
*/

#pragma once

#include <string>
#include <vector>

namespace Gui {

    /**
     * @brief Class interface to parse the server's commands.
     */
    class IServerParser;
}

class Gui::IServerParser {

    public:

        /**
         * @brief Destroy the IServerParser object.
         */
        virtual ~IServerParser() = default;

        /**
         * @brief Parse the command server.
         *
         * @param command Command to parse.
         * @return std::vector<std::string> - arguments parsed.
         */
        virtual std::vector<std::string> parse(const std::string& command) = 0;
};
