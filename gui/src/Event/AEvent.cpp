/*
** EPITECH PROJECT, 2024
** *
** File description:
** AEvent
*/

#include "Event/AEvent.hpp"

Gui::AEvent::AEvent() {}

void Gui::AEvent::setRender(std::shared_ptr<Render> render)
{
    _render = render;
}

void Gui::AEvent::setGameData(std::shared_ptr<GameData> gameData)
{
    _gameData = gameData;
}

std::shared_ptr<Gui::Render> Gui::AEvent::getRender()
{
    return _render;
}

std::shared_ptr<Gui::GameData> Gui::AEvent::getGameData()
{
    return _gameData;
}
