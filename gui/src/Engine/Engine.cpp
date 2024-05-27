/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Engine
*/

#include "Engine/Engine.hpp"

Gui::Engine::Engine(Network network) : _network(network)
{
    _isOpen = true;
}

void Gui::Engine::run()
{
    while (_isOpen) {
        listenServer();
        // handleEvents();
        // display();
    }
}

void Gui::Engine::listenServer()
{
    std::string command = _network.listenServer();

    if (command == "")
        return;
    // TODO: call ServerParser parse method
}

void Gui::Engine::setOpen(bool isOpen)
{
    _isOpen = isOpen;
}

bool Gui::Engine::getOpen()
{
    return _isOpen;
}
