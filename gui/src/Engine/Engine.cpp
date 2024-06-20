/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Engine
*/

#include "Colors.hpp"
#include "Engine/Engine.hpp"

#include <iostream>
#include <sstream>

Gui::Engine::Engine(std::shared_ptr<INetwork> network) : _network(network)
{
    _gameData = std::make_shared<GameData>();
    _render = std::make_shared<Render>(_gameData);
    _event = std::make_unique<Event>();
    _event->setRender(_render);
    _event->setGameData(_gameData);
    _guiUpdater = std::make_unique<GUIUpdater>(_gameData, _network);
    _parser = std::make_unique<ServerParser>();
}

void Gui::Engine::run()
{
    while (_render->isOpen() && !_gameData->getIsEndGame()) {
        listenServer();
        _render->draw();
        _event->listen();
        sendMessageUpdate();
    }
}

void Gui::Engine::listenServer()
{
    std::string command = _network.get()->listenServer();

    if (command == "")
        return;
    if (command == SERVER_DOWN_MESSAGE) {
        std::cout << STR_RED << SERVER_DOWN_MESSAGE << STR_RESET << std::endl;
        _gameData.get()->setIsEndGame(true);
        return;
    }
    try {
        std::vector<std::string> arguments = _parser->parse(command);
        std::istringstream stream(command);
        std::string keyCommand;

        stream >> keyCommand;
        _guiUpdater->update(keyCommand, arguments);
    }
    catch (const std::exception &error) {
        std::cerr << STR_RED << error.what() << STR_RESET << std::endl;
    }
}

void Gui::Engine::sendMessageUpdate()
{
    updateMap();

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

void Gui::Engine::updateMap()
{
    clock_t currentTick = clock();
    std::pair<std::size_t, std::size_t> mapSize = _gameData.get()->getMapSize();

    if (!(mapSize.first == 0 && mapSize.second == 0) && _gameData.get()->getNbBCTCommandReceived() >= mapSize.first * mapSize.second) {
        if (TIME_UNIT_MAP_UPDATE / _gameData->getServerTick() >= 2 && (float)(currentTick - _gameData->getLastTickMctCommand()) / CLOCKS_PER_SEC > TIME_UNIT_MAP_UPDATE / _gameData->getServerTick()) {
            sendUpdateMapMessage();
        } else if (TIME_UNIT_MAP_UPDATE / _gameData->getServerTick() < 2 && (float)(currentTick - _gameData->getLastTickMctCommand()) / CLOCKS_PER_SEC > 2) {
            sendUpdateMapMessage();
        }
    }
}

void Gui::Engine::sendUpdateMapMessage()
{
    _network.get()->sendMessageServer("mct\n");
    _gameData.get()->setNbBCTCommandReceived(0);
    _gameData.get()->restartLastTickMctCommand();
}
