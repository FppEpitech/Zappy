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
        ServerParser() = default;

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
            //pbc
            //pic
            {"pie", std::vector<ParseType>{INT, INT, INT}},
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
            //smg
            {"suc", std::vector<ParseType>{}},
            {"sbp", std::vector<ParseType>{}}
        };

        /**
         * @brief Parse the command with its types.
         *
         * @param command Command to parse.
         * @param types Types within parse the command.
         * @return std::vector<std::string> - arguments parsed
         */
        std::vector<std::string> parseCommand(const std::string& command, std::vector<ParseType> types);

        /**
         * @brief Parse an int in the command stream.
         *
         * @param stream Stream to parse.
         * @param arguments List of arguments parsed.
         * @return std::vector<std::string> - arguments parsed
         */
        std::vector<std::string> parseInt(std::istringstream& stream, std::vector<std::string> arguments);

        /**
         * @brief Parse a string in the command stream.
         *
         * @param stream Stream to parse.
         * @param arguments List of arguments parsed.
         * @return std::vector<std::string> - arguments parsed
         */
        std::vector<std::string> parseString(std::istringstream& stream, std::vector<std::string> arguments);

        /**
         * @brief Parse an hashtag in the command stream.
         *
         * @param stream Stream to parse.
         * @param arguments List of arguments parsed.
         * @return std::vector<std::string> - arguments parsed
         */
        std::vector<std::string> parseHashtag(std::istringstream& stream, std::vector<std::string> arguments, std::string commandName);
};
