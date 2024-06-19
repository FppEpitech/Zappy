/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Engine
*/

#include "Event/Event.hpp"
#include "Engine/Engine.hpp"
#include "GUIUpdater/GUIUpdater.hpp"
#include "Colors.hpp"

#include <iostream>
#include <sstream>

Gui::Engine::Engine(std::shared_ptr<Network> network) : _network(network), _gameData(std::make_shared<GameData>()), _guiUpdater(_gameData, _network)
{
    _render = std::make_shared<Render>(_gameData);
    _event.setRender(_render);
    _event.setGameData(_gameData);
}

void Gui::Engine::run()
{
    while (_render->isOpen() && !_gameData->getIsEndGame()) {
        listenServer();
        _render->draw();
        _event.listen();
        sendMessageUpdate();
    }
}

void Gui::Engine::listenServer()
{
    std::string command = _network.get()->listenServer();

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
        std::cerr << STR_RED << error.what() << STR_RESET << std::endl;
    }
}

void Gui::Engine::sendMessageUpdate()
{
    clock_t currentTick = clock();

    if ((int)(_gameData->getServerTick()) == NO_TICK && (float)(currentTick - _gameData->getLastTick()) / CLOCKS_PER_SEC < 1)
        return;
    if ((int)(_gameData->getServerTick()) != NO_TICK && (float)(currentTick - _gameData->getLastTick()) / CLOCKS_PER_SEC < 1 / _gameData->getServerTick())
        return;
    _gameData->restartLastTick();

    _network.get()->sendMessageServer("sgt\n");
    for (auto &team : _gameData.get()->getTeams()) {
        for (auto &player : team.getPlayers()) {
            _network.get()->sendMessageServer("ppo " + std::to_string(player.getId()) + "\n");
        }
    }
    if (_gameData.get()->getTimeUnitFromServer() == GameData::TimeUnitState::INCREASE)
        _network.get()->sendMessageServer("sst " + std::to_string(_gameData.get()->getServerTick() + 1) + "\n");
    else if (_gameData.get()->getTimeUnitFromServer() == GameData::TimeUnitState::DECREASE)
        _network.get()->sendMessageServer("sst " + std::to_string(_gameData.get()->getServerTick() - 1) + "\n");
}
