/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Engine
*/

#include "Event/Event.hpp"
#include "Engine/Engine.hpp"

#include <iostream>

Gui::Engine::Engine(Network network, std::shared_ptr<Render> render) : _network(network), _render(render) {}

void Gui::Engine::run(void)
{
    Event event(_render);

    while (_render->isOpen()) {
        listenServer();
        event.listen();
        _render->draw();
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
