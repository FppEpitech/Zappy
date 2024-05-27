/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Parse server command
*/

#include "Parsing/ServerParser.hpp"

#include <sstream>

Gui::ServerParser::ServerParser() {}

std::vector<std::string> Gui::ServerParser::parse(const std::string& command)
{
    std::istringstream stream(command);
    std::string keyCommand;
    stream >> keyCommand;

    if (_typesCommand.find(keyCommand) == _typesCommand.end())
        throw Errors::ServerParser("Server's command didn't exist.");
    return parseCommand(command, _typesCommand[keyCommand]);
}

std::vector<std::string> Gui::ServerParser::parseCommand(const std::string& command, std::vector<Gui::ServerParser::ParseType> types)
{
    std::vector<std::string> arguments;
    std::istringstream stream(command);
    std::string commandName;

    stream >> commandName;

    for (size_t type = 0; type < types.size(); type++) {
        switch (types[type])
        {
            case Gui::ServerParser::ParseType::INT:
            {
                int value;
                stream >> value;
                arguments.push_back(std::to_string(value));
                break;
            }
            case Gui::ServerParser::ParseType::STRING:
            {
                std::string str;
                stream >> str;
                arguments.push_back(str);
                break;
            }
            case Gui::ServerParser::ParseType::HASHTAG:
            {
                char hashtag;
                stream >> hashtag;
                if (hashtag != '#')
                    throw Errors::ServerParser("Wrong parameters for '" + commandName + "' command.");
                int nb;
                stream >> nb;
                arguments.push_back(std::to_string(nb));
                break;
            }
            default:
                break;
        }
    }
    if (stream.fail())
        throw Errors::ServerParser("Wrong parameters for '" + commandName + "' command.");
    if (stream.peek() != std::istringstream::traits_type::eof())
        throw Errors::ServerParser("Too many parameters for '" + commandName + "' command.");

    return arguments;
}
