/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** main
*/

#include "Engine/Engine.hpp"
#include "Network/Network.hpp"
#include "Parsing/ParseCommandLine.hpp"

#include <iostream>
#include <signal.h>

int main(int argc, char **argv)
{
    signal(SIGPIPE, SIG_IGN);
    try {
        Gui::ParseCommandLine parseLine(argc, argv);
        Gui::Network net(parseLine.getPort(), parseLine.getHostName());
        net.connectToServer();
        Gui::Engine engine(std::make_shared<Gui::Network>(net));
        engine.run();
    } catch (const std::exception &error) {
        std::cerr << error.what() << std::endl;
        return 84;
    }
    return 0;
}
