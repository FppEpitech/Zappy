/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Engine
*/

#include "Engine/Engine.hpp"

#include <iostream>

Gui::Engine::Engine(Network network) : _network(network) {}

void Gui::Engine::run(void)
{
    while (_render.isOpen()) {
        listenServer();
        // TODO : handleEvents();
        _render.draw();
    }
}

void Gui::Engine::listenServer(void)
{
    std::string command = _network.listenServer();

    if (command == "")
        return;
    try {
        std::vector<std::string> arguments = _parser.parse(command);
        //TODO: #20 (https://github.com/FppEpitech/Zappy/issues/20)
    }
    catch (const std::exception &error) {
        std::cout << error.what() << std::endl;
    }
}
