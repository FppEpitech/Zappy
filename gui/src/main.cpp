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

int main(int argc, char **argv)
{
    try {
        Gui::ParseCommandLine parseLine(argc, argv);
        Gui::Network net(parseLine.getPort(), parseLine.getHostName());
        net.connectToServer();
        Gui::Engine engine(net);
        engine.run();
    } catch (const std::exception &error) {
        std::cout << error.what() << std::endl;
        return 84;
    }
    return 0;
}
