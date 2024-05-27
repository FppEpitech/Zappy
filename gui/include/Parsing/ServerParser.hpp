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
        static std::vector<std::string> _parseCommandBCT(const std::string& command);
        static std::vector<std::string> _parseCommandTNA(const std::string& command);
        static std::vector<std::string> _parseCommandPNW(const std::string& command);
        static std::vector<std::string> _parseCommandPPO(const std::string& command);
        static std::vector<std::string> _parseCommandPLV(const std::string& command);
        static std::vector<std::string> _parseCommandPIN(const std::string& command);
        static std::vector<std::string> _parseCommandPEX(const std::string& command);
        // TODO : PBC, PIC, PIE
        static std::vector<std::string> _parseCommandPFK(const std::string& command);
        static std::vector<std::string> _parseCommandPDR(const std::string& command);
        static std::vector<std::string> _parseCommandPGT(const std::string& command);
        static std::vector<std::string> _parseCommandPDI(const std::string& command);
        static std::vector<std::string> _parseCommandENW(const std::string& command);
        static std::vector<std::string> _parseCommandEBO(const std::string& command);
        static std::vector<std::string> _parseCommandEDI(const std::string& command);
        static std::vector<std::string> _parseCommandSGT(const std::string& command);
        static std::vector<std::string> _parseCommandSST(const std::string& command);
        static std::vector<std::string> _parseCommandSEG(const std::string& command);
};
