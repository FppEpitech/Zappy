/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** ParseCommandLine
*/

#include "Error/Error.hpp"
#include "Parsing/ParseCommandLine.hpp"

#include <string.h>
#include <iostream>

Gui::ParseCommandLine::ParseCommandLine(int argc, char **argv)
{
    bool isPort = false;
    bool isHostname = false;

    if (argc != 5)
        throw Errors::ParseCommandLineException("USAGE:\t./zappy_gui -p port -h machine");

    for (int i = 1; i <= 3; i += 2) {
        if (strcmp("-p", argv[i]) == 0 && i + 1 < argc) {
            _port = atoi(argv[i + 1]);
            isPort = true;
        } else if (strcmp("-h", argv[i]) == 0 && i + 1 < argc) {
            _hostName = argv[i + 1];
            isHostname = true;
        } else
            throw Errors::ParseCommandLineException("USAGE:\t./zappy_gui -p port -h machine");
    }
    if (!isPort || !isHostname) {
        std::cout << isPort << isHostname << std::endl;
        throw Errors::ParseCommandLineException("USAGE:\t./zappy_gui -p port -h machine");
    }
}

int Gui::ParseCommandLine::getPort()
{
    return _port;
}

std::string Gui::ParseCommandLine::getHostName()
{
    return _hostName;
}
