/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Event
*/

#include "raylib.h"
#include "Event/Event.hpp"

Gui::Event::Event()
{
}

void Gui::Event::listen()
{
    for (auto &event : _eventsKeyDown) {
        if (IsKeyDown(event.first))
            event.second();
    }
    for (auto &event : _eventsKeyPressed) {
        if (IsKeyPressed(event.first))
            event.second();
    }
}

void Gui::Event::setRender(std::shared_ptr<Render> render)
{
    _render = render;
}

void Gui::Event::setGameData(std::shared_ptr<GameData> gameData)
{
    _gameData = gameData;
}

void Gui::Event::moveUpCamera()
{
    _render->getCamera()->position.y += HIGH_CAMERA_INCREASE;
    _render->getCamera()->target.y += HIGH_CAMERA_INCREASE;
}

void Gui::Event::moveDownCamera()
{
    _render->getCamera()->position.y -= LOW_CAMERA_INCREASE;
    _render->getCamera()->target.y -= LOW_CAMERA_INCREASE;
}

void Gui::Event::switchDisplayDebug()
{
    if (_render->getIsDebug())
        _render->setIsDebug(false);
    else
        _render->setIsDebug(true);
}

void Gui::Event::switchPovLeft()
{

}

void Gui::Event::switchPovRight()
{

}
