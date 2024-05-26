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
    _functionsMap["tna"] = &_parseCommandTNA;
    _functionsMap["pnw"] = &_parseCommandPNW;
    _functionsMap["ppo"] = &_parseCommandPPO;
    _functionsMap["plv"] = &_parseCommandPLV;
    _functionsMap["pin"] = &_parseCommandPIN;
    _functionsMap["pex"] = &_parseCommandPEX;
    // TODO : pbc, pic, pie
    _functionsMap["pfk"] = &_parseCommandPFK;
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

std::vector<std::string> Gui::ServerParser::_parseCommandTNA(const std::string& command)
{
    std::vector<std::string> arguments;
    std::istringstream stream(command);
    std::string none;
    std::string team;

    stream >> none;
    stream >> team;

    if (stream.fail())
        throw Errors::ServerParser("Wrong parameters for 'tna' command.");
    stream >> none;
    if (!stream.fail())
        throw Errors::ServerParser("Too many parameters for 'tna' command.");
    arguments.push_back(team);

    return arguments;
}

std::vector<std::string> Gui::ServerParser::_parseCommandPNW(const std::string& command)
{
    std::vector<std::string> arguments;
    std::istringstream stream(command);
    std::string none, team;
    char hashtag;
    int player, x, y, orientation, level;

    stream >> none;
    stream >> hashtag;
    stream >> player;
    stream >> x;
    stream >> y;
    stream >> orientation;
    stream >> level;
    stream >> team;

    if (hashtag != '#' || stream.fail())
        throw Errors::ServerParser("Wrong parameters for 'pnw' command.");
    stream >> none;
    if (!stream.fail())
        throw Errors::ServerParser("Too many parameters for 'pnw' command.");
    arguments.push_back(std::to_string(player));
    arguments.push_back(std::to_string(x));
    arguments.push_back(std::to_string(y));
    arguments.push_back(std::to_string(orientation));
    arguments.push_back(std::to_string(level));
    arguments.push_back(team);

    return arguments;
}

std::vector<std::string> Gui::ServerParser::_parseCommandPPO(const std::string& command)
{
    std::vector<std::string> arguments;
    std::istringstream stream(command);
    std::string none;
    char hashtag;
    int player, x, y, orientation;

    stream >> none;
    stream >> hashtag;
    stream >> player;
    stream >> x;
    stream >> y;
    stream >> orientation;

    if (hashtag != '#' || stream.fail())
        throw Errors::ServerParser("Wrong parameters for 'ppo' command.");
    stream >> none;
    if (!stream.fail())
        throw Errors::ServerParser("Too many parameters for 'ppo' command.");
    arguments.push_back(std::to_string(player));
    arguments.push_back(std::to_string(x));
    arguments.push_back(std::to_string(y));
    arguments.push_back(std::to_string(orientation));

    return arguments;
}

std::vector<std::string> Gui::ServerParser::_parseCommandPLV(const std::string& command)
{
    std::vector<std::string> arguments;
    std::istringstream stream(command);
    std::string none;
    char hashtag;
    int player, level;

    stream >> none;
    stream >> hashtag;
    stream >> player;
    stream >> level;

    if (hashtag != '#' || stream.fail())
        throw Errors::ServerParser("Wrong parameters for 'plv' command.");
    stream >> none;
    if (!stream.fail())
        throw Errors::ServerParser("Too many parameters for 'plv' command.");
    arguments.push_back(std::to_string(player));
    arguments.push_back(std::to_string(level));

    return arguments;
}

std::vector<std::string> Gui::ServerParser::_parseCommandPIN(const std::string& command)
{
    std::vector<std::string> arguments;
    std::istringstream stream(command);
    std::string none;
    char hashtag;
    int player, x, y, q0, q1, q2, q3, q4, q5, q6;

    stream >> none;
    stream >> hashtag;
    stream >> player;
    stream >> x;
    stream >> y;
    stream >> q0;
    stream >> q1;
    stream >> q2;
    stream >> q3;
    stream >> q4;
    stream >> q5;
    stream >> q6;

    if (hashtag != '#' || stream.fail())
        throw Errors::ServerParser("Wrong parameters for 'pin' command.");
    stream >> none;
    if (!stream.fail())
        throw Errors::ServerParser("Too many parameters for 'pin' command.");
    arguments.push_back(std::to_string(player));
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

std::vector<std::string> Gui::ServerParser::_parseCommandPEX(const std::string& command)
{
    std::vector<std::string> arguments;
    std::istringstream stream(command);
    std::string none;
    char hashtag;
    int player;

    stream >> none;
    stream >> hashtag;
    stream >> player;

    if (hashtag != '#' || stream.fail())
        throw Errors::ServerParser("Wrong parameters for 'pex' command.");
    stream >> none;
    if (!stream.fail())
        throw Errors::ServerParser("Too many parameters for 'pex' command.");
    arguments.push_back(std::to_string(player));

    return arguments;
}

std::vector<std::string> Gui::ServerParser::_parseCommandPFK(const std::string& command)
{
    std::vector<std::string> arguments;
    std::istringstream stream(command);
    std::string none;
    char hashtag;
    int player;

    stream >> none;
    stream >> hashtag;
    stream >> player;

    if (hashtag != '#' || stream.fail())
        throw Errors::ServerParser("Wrong parameters for 'pfk' command.");
    stream >> none;
    if (!stream.fail())
        throw Errors::ServerParser("Too many parameters for 'pfk' command.");
    arguments.push_back(std::to_string(player));

    return arguments;
}
