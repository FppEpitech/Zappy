/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Parse server command
*/

#pragma once

#include "Error/Error.hpp"

#include <string>
#include <functional>
#include <unordered_map>

namespace Gui {

    /**
     * @brief Class to parse the server's commands.
     *
     */
    class ServerParser;
};

class Gui::ServerParser {

    public:

        /**
         * @brief Construct a new Server Parser object.
         *
         */
        ServerParser();

        /**
         * @brief Destroy the Server Parser object.
         *
         */
        ~ServerParser() = default;

        /**
         * @brief Parse the command server.
         *
         * @param command pf the server
         */
        std::vector<std::string> parse(const std::string& command);

    private:

        std::unordered_map<std::string, std::vector<std::string>(*)(const std::string& command)> _functionsMap;

        static std::vector<std::string> _parseCommandMSZ(const std::string& command);
};
