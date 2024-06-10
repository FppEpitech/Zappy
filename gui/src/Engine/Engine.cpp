/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Engine
*/

#include "Assets.hpp"
#include "Event/Event.hpp"
#include "Engine/Engine.hpp"
#include "GUIUpdater/GUIUpdater.hpp"

#include <iostream>
#include <sstream>

Gui::Engine::Engine(Network network) : _network(network), _gameData(std::make_shared<GameData>()), _guiUpdater(_gameData)
{
    _render = std::make_shared<Render>(_gameData);
    _event.setRender(_render);
    _event.setGameData(_gameData);
}

void Gui::Engine::run(void)
{
    _gameData->addTeam("NAROUT", MODEL_PLAYER, MODEL_EGG);
    _gameData->getTeam("NAROUT").addPlayer(Player(1, "NAROUT", std::make_pair(0,0), 2, 1));

    while (_render->isOpen() && !_gameData->getIsEndGame()) {
        listenServer();
        _event.listen();
        _render->draw();
        sendMessageUpdate();
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

void Gui::Engine::sendMessageUpdate(void)
{
    clock_t currentTick = clock();

    if ((int)(_gameData->getServerTick()) == NO_TICK && (float)(currentTick - _gameData->getLastTick()) / CLOCKS_PER_SEC < (1))
        return;
    if ((int)(_gameData->getServerTick()) != NO_TICK && (float)(currentTick - _gameData->getLastTick()) / CLOCKS_PER_SEC < (_gameData->getServerTick()))
        return;
    _gameData->restartLastTick();

    _network.sendMessageServer("sgt\n");
    _network.sendMessageServer("mct\n");
    _network.sendMessageServer("ppo\n");
}
