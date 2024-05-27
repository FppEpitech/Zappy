/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Parse server command
*/

#include "Parsing/ServerParser.hpp"

#include <sstream>

std::vector<std::string> Gui::ServerParser::parse(const std::string& command)
{
    std::istringstream stream(command);
    std::string keyCommand;

    stream >> keyCommand;

    if (_typesCommand.find(keyCommand) == _typesCommand.end())
        throw Errors::ServerParserException("Server's command didn't exist.");
    return parseCommand(command, _typesCommand[keyCommand]);
}

std::vector<std::string> Gui::ServerParser::parseCommand(const std::string& command, std::vector<Gui::ServerParser::ParseType> types)
{
    std::vector<std::string> arguments;
    std::istringstream stream(command);
    std::string commandName;

    stream >> commandName;

    for (size_t index = 0; index < types.size(); index++) {
        switch (types[index])
        {
            case Gui::ServerParser::ParseType::INT:
            {
                arguments = parseInt(stream, arguments);
                break;
            }
            case Gui::ServerParser::ParseType::STRING:
            {
                arguments = parseString(stream, arguments);
                break;
            }
            case Gui::ServerParser::ParseType::HASHTAG:
            {
                arguments = parseHashtag(stream, arguments, commandName);
                break;
            }
            default:
                break;
        }
    }
    if (stream.fail())
        throw Errors::ServerParserException("Wrong parameters for '" + commandName + "' command.");
    if (stream.peek() != std::istringstream::traits_type::eof())
        throw Errors::ServerParserException("Too many parameters for '" + commandName + "' command.");

    return arguments;
}

std::vector<std::string> Gui::ServerParser::parseInt(std::istringstream& stream, std::vector<std::string> arguments)
{
    int value;
    stream >> value;
    arguments.push_back(std::to_string(value));
    return arguments;
}

std::vector<std::string> Gui::ServerParser::parseString(std::istringstream& stream, std::vector<std::string> arguments)
{
    std::string str;
    stream >> str;
    arguments.push_back(str);
    return arguments;
}

std::vector<std::string> Gui::ServerParser::parseHashtag(std::istringstream& stream, std::vector<std::string> arguments, std::string commandName)
{
    char hashtag;
    stream >> hashtag;
    if (hashtag != '#')
        throw Errors::ServerParserException("Wrong parameters for '" + commandName + "' command.");
    int nb;
    stream >> nb;
    arguments.push_back(std::to_string(nb));
    return arguments;
}
