/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Engine
*/

#include "Engine/Engine.hpp"

#include <iostream>

Gui::Engine::Engine(Network network) : _network(network) {}

void Gui::Engine::run()
{
    //while (//TODO : renderer.getIsOpen()) {
        listenServer();
        // TODO :
        // handleEvents();
        // display();
    // }
}

void Gui::Engine::listenServer()
{
    std::string command = _network.listenServer();

    if (command == "")
        return;
    try {
        std::vector<std::string> arguments = _parser.parse(command);
        //TODO: update game with arguments...
    }
    catch (const std::exception &error) {
        std::cout << error.what() << std::endl;
    }
}
