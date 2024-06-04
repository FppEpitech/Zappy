/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GUIUpdater
*/

#include "GUIUpdater/GUIUpdater.hpp"

Gui::GUIUpdater::GUIUpdater(std::shared_ptr<GameData> gameData) : _gameData(gameData) {}

void Gui::GUIUpdater::update(const std::string &command, const std::string &data)
{
    (void)command;
    (void)data;
}
