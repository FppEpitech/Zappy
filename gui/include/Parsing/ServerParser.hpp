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
         * @param command Command to parse.
         * @return std::vector<std::string> - arguments parsed
         */
        std::vector<std::string> parse(const std::string& command);

        /**
         * @brief Enum of types to parse.
         *
         */
        enum ParseType {
            INT,
            STRING,
            HASHTAG
        };

    private:

        /**
         * @brief Map of types to parse related to the command
         *
         */
        std::unordered_map<std::string, std::vector<ParseType>> _typesCommand =
        {
            {"msz", std::vector<ParseType>{INT, INT}},
            {"bct", std::vector<ParseType>{INT, INT, INT, INT, INT, INT, INT, INT, INT}},
            {"tna", std::vector<ParseType>{STRING}},
            {"pnw", std::vector<ParseType>{HASHTAG, INT, INT, INT, INT, STRING}},
            {"ppo", std::vector<ParseType>{HASHTAG, INT, INT, INT}},
            {"plv", std::vector<ParseType>{HASHTAG, INT}},
            {"pin", std::vector<ParseType>{HASHTAG, INT, INT, INT, INT, INT, INT, INT, INT, INT}},
            {"pex", std::vector<ParseType>{HASHTAG}},
            {"pfk", std::vector<ParseType>{HASHTAG}},
            {"pdr", std::vector<ParseType>{HASHTAG, INT}},
            {"pgt", std::vector<ParseType>{HASHTAG, INT}},
            {"pdi", std::vector<ParseType>{HASHTAG}},
            {"enw", std::vector<ParseType>{HASHTAG, HASHTAG, INT, INT}},
            {"ebo", std::vector<ParseType>{HASHTAG}},
            {"edi", std::vector<ParseType>{HASHTAG}},
            {"sgt", std::vector<ParseType>{INT}},
            {"sst", std::vector<ParseType>{INT}},
            {"seg", std::vector<ParseType>{STRING}},
            {"suc", std::vector<ParseType>{}},
            {"sbp", std::vector<ParseType>{}}
            // TODO : pbc, pic, pie, smg
            // #15 (https://github.com/FppEpitech/Zappy/issues/15))
        };

        /**
         * @brief Parse the command with its types.
         *
         * @param command Command to parse.
         * @param types Types within parse the command.
         * @return std::vector<std::string> - arguments parsed
         */
        std::vector<std::string> parseCommand(const std::string& command, std::vector<ParseType> types);
};
