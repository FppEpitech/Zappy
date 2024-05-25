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

void Gui::ServerParser::parse(const std::string& command)
{
    std::istringstream stream(command);
    std::string keyCommand;
    stream>>keyCommand;

    if (_functionsMap[keyCommand] == nullptr)
        throw Errors::ServerParser("Server's command didn't exist.");
    return (_functionsMap[keyCommand])();
}

void Gui::ServerParser::_parseCommandMSZ()
{
    return;
}
