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

        ServerParser();
        ~ServerParser() = default;
        void parse(const std::string& command);

    private:

        std::unordered_map<std::string, void(*)()> _functionsMap;

        static void _parseCommandMSZ();
};
