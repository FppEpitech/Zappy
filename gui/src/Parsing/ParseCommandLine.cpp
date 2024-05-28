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
    if (argc != 5)
        throw Errors::ParseCommandLineException(GUI_USAGE);

    parseFlags(argc, argv);
}

void Gui::ParseCommandLine::parseFlags(int argc, char **argv)
{
    bool isPort = false;
    bool isHostname = false;

    for (int i = 1; i <= 3; i += 2) {
        if (strcmp("-p", argv[i]) == 0 && i + 1 < argc) {
            _port = std::stoul(argv[i + 1]);
            isPort = true;
        } else if (strcmp("-h", argv[i]) == 0 && i + 1 < argc) {
            _hostName = argv[i + 1];
            isHostname = true;
        } else
            throw Errors::ParseCommandLineException(GUI_USAGE);
    }
    if (!isPort || !isHostname) {
        std::cout << isPort << isHostname << std::endl;
        throw Errors::ParseCommandLineException(GUI_USAGE);
    }
}

int Gui::ParseCommandLine::getPort(void)
{
    return _port;
}

std::string Gui::ParseCommandLine::getHostName(void)
{
    return _hostName;
}
