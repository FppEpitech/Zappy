/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Parse server command
*/

#include "Parsing/ServerParser.hpp"

#include <sstream>

Gui::ServerParser::ServerParser()
{
    _functionsMap["msz"] = &_parseCommandMSZ;
}

std::vector<std::string> Gui::ServerParser::parse(const std::string& command)
{
    std::istringstream stream(command);
    std::string keyCommand;
    stream >> keyCommand;

    if (_functionsMap[keyCommand] == nullptr)
        throw Errors::ServerParser("Server's command didn't exist.");
    return (_functionsMap[keyCommand])(command);
}

std::vector<std::string> Gui::ServerParser::_parseCommandMSZ(const std::string& command)
{
    std::vector<std::string> arguments;
    std::istringstream stream(command);
    int x,y;
    std::string none;

    stream >> none;
    stream >> x;
    stream >> y;

    if (stream.fail())
        throw Errors::ServerParser("Wrong parameters for 'msz' command.");
    stream >> none;
    if (!stream.fail())
        throw Errors::ServerParser("Too many parameters for 'msz' command.");
    arguments.push_back(std::to_string(x));
    arguments.push_back(std::to_string(y));

    return arguments;
}
