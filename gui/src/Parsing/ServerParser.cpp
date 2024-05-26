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
    _functionsMap["bct"] = &_parseCommandBCT;
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

std::vector<std::string> Gui::ServerParser::_parseCommandBCT(const std::string& command)
{
    std::vector<std::string> arguments;
    std::istringstream stream(command);
    int x,y,q0,q1,q2,q3,q4,q5,q6;
    std::string none;

    stream >> none;
    stream >> x;
    stream >> y;
    stream >> q0;
    stream >> q1;
    stream >> q2;
    stream >> q3;
    stream >> q4;
    stream >> q5;
    stream >> q6;

    if (stream.fail())
        throw Errors::ServerParser("Wrong parameters for 'bct' command.");
    stream >> none;
    if (!stream.fail())
        throw Errors::ServerParser("Too many parameters for 'bct' command.");
    arguments.push_back(std::to_string(x));
    arguments.push_back(std::to_string(y));
    arguments.push_back(std::to_string(q0));
    arguments.push_back(std::to_string(q1));
    arguments.push_back(std::to_string(q2));
    arguments.push_back(std::to_string(q3));
    arguments.push_back(std::to_string(q4));
    arguments.push_back(std::to_string(q5));
    arguments.push_back(std::to_string(q6));

    return arguments;
}
