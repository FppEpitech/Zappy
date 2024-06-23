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
    _networkThread = std::thread(&Gui::Engine::threadLoop, this);
    while (_render->isOpen() && !_gameData->getServerError()) {
        _render->draw();
        _event->listen();
        sendMessageUpdate();
    }
    if (_networkThread.joinable())
        _networkThread.join();
}

void Gui::Engine::listenServer()
{
    Gui::INetwork::BufferState bufferState = _network.get()->listenServer();

    if (bufferState == Gui::INetwork::BufferState::NONE)
        return;
    if (bufferState == Gui::INetwork::BufferState::SERVER_ERROR) {
        if (!_gameData.get()->getIsEndGame())
            _gameData.get()->setServerError(true);
        return;
    }
    try {
        std::string command = _network->getBuffer();
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
    clock_t currentTick = clock();

    if ((int)(_gameData->getServerTick()) == NO_TICK && (float)(currentTick - _gameData->getLastTick()) / CLOCKS_PER_SEC < 1)
        return;
    if ((int)(_gameData->getServerTick()) != NO_TICK && (float)(currentTick - _gameData->getLastTick()) / CLOCKS_PER_SEC < 1 / _gameData->getServerTick())
        return;
    _gameData->restartLastTick();

    if (_gameData.get()->getTimeUnitFromServer() == GameData::TimeUnitState::INCREASE)
        _network.get()->sendMessageServer("sst " + std::to_string(_gameData.get()->getServerTick() + 1) + "\n");
    else if (_gameData.get()->getTimeUnitFromServer() == GameData::TimeUnitState::DECREASE) {
        if (_gameData.get()->getServerTick() - 1 > 0)
            _network.get()->sendMessageServer("sst " + std::to_string(_gameData.get()->getServerTick() - 1) + "\n");
    }
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

void Gui::Engine::threadLoop()
{
    while (_render->isOpen() && (!_gameData->getServerError()) && (!_gameData.get()->getIsEndGame()))
        listenServer();
}
