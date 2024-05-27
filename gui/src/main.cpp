/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** main
*/

#include "Engine/Engine.hpp"
#include "Network/Network.hpp"

#include <iostream>

static void displayHelp()
{
    std::cout << "USAGE:\t./zappy_gui -p port -h machine" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        displayHelp();
        return 0;
    }
    try {
        Gui::Network net(atoi(argv[1]), argv[2]);
        net.connectToServer();
        Gui::Engine engine(net);
        engine.run();
    } catch (const std::exception &error) {
        std::cout << error.what() << std::endl;
        return 84;
    }
    return 0;
}
