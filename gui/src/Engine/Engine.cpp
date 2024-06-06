/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Engine
*/

#include "Event/Event.hpp"
#include "Engine/Engine.hpp"
#include "GUIUpdater/GUIUpdater.hpp"

#include <iostream>
#include <sstream>

Gui::Engine::Engine(Network network) : _network(network), _gameData(std::make_shared<GameData>()), _guiUpdater(_gameData)
{
    _render = std::make_shared<Render>(_gameData);
    _event.setRender(_render);
}

void Gui::Engine::run(void)
{
    while (_render->isOpen()) {
        listenServer();
        _event.listen();
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
        std::istringstream stream(command);
        std::string keyCommand;

        stream >> keyCommand;
        _guiUpdater.update(keyCommand, arguments);
    }
    catch (const std::exception &error) {
        std::cout << error.what() << std::endl;
    }
}
