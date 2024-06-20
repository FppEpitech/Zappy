/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AGUIUpdater
*/

#include "GUIUpdater/AGUIUpdater.hpp"

Gui::AGUIUpdater::AGUIUpdater(std::shared_ptr<GameData> gameData, std::shared_ptr<INetwork> network) : _gameData(gameData), _network(network) {}
