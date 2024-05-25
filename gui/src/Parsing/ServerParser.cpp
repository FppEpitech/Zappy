/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Parse server command
*/

#include "Parsing/ServerParser.hpp"

Gui::ServerParser::ServerParser()
{
    _functionsMap["msz"] = &_parseCommandMSZ;
}

void Gui::ServerParser::parse(const std::string& command)
{
    if (_functionsMap[command] == nullptr)
        throw Errors::ServerParser("Server's command didn't exist.");
    return (_functionsMap[command])();
}

void Gui::ServerParser::_parseCommandMSZ()
{
    return;
}