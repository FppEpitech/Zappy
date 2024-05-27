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

        /**
         * @brief Parse the command msz.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandMSZ(const std::string& command);

        /**
         * @brief Parse the command btc.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandBCT(const std::string& command);

        /**
         * @brief Parse the command tna.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandTNA(const std::string& command);

        /**
         * @brief Parse the command pnw.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandPNW(const std::string& command);

        /**
         * @brief Parse the command ppo.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandPPO(const std::string& command);

        /**
         * @brief Parse the command plv.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandPLV(const std::string& command);

        /**
         * @brief Parse the command pin.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandPIN(const std::string& command);

        /**
         * @brief Parse the command pex.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandPEX(const std::string& command);

        /**
         * @brief Parse the command pfk.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandPFK(const std::string& command);

        /**
         * @brief Parse the command pdr.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandPDR(const std::string& command);

        /**
         * @brief Parse the command pgt.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandPGT(const std::string& command);

        /**
         * @brief Parse the command pdi.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandPDI(const std::string& command);

        /**
         * @brief Parse the command enw.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandENW(const std::string& command);

        /**
         * @brief Parse the command ebo.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandEBO(const std::string& command);

        /**
         * @brief Parse the command edi.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandEDI(const std::string& command);

        /**
         * @brief Parse the command sgt.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandSGT(const std::string& command);

        /**
         * @brief Parse the command sst.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandSST(const std::string& command);

        /**
         * @brief Parse the command seg.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandSEG(const std::string& command);

        /**
         * @brief Parse the command suc.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandSUC(const std::string& command);

        /**
         * @brief Parse the command sbp.
         *
         * @param command of the server
         * @return std::vector<std::string> - arguments parsed
         */
        static std::vector<std::string> _parseCommandSBP(const std::string& command);

        // TODO : PBC, PIC, PIE, SMG
        // #15 (https://github.com/FppEpitech/Zappy/issues/15)
};
