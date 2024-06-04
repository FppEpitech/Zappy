/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Event
*/

#include "raylib.h"
#include "Event/Event.hpp"

Gui::Event::Event(std::shared_ptr<Render> render) : _render(render)
{
}

void Gui::Event::listen()
{
    if (IsKeyDown(KEY_SPACE))
        spaceEvent();
    if (IsKeyDown(KEY_LEFT_SHIFT))
        shiftEvent();
    if (IsKeyReleased(KEY_THREE) or IsKeyReleased(KEY_F3))
        debugEvent();
}

void Gui::Event::spaceEvent()
{
    _render->getCamera()->position.y += 0.1;
    _render->getCamera()->target.y += 0.1;
}

void Gui::Event::shiftEvent()
{
    _render->getCamera()->position.y -= 0.1;
    _render->getCamera()->target.y -= 0.1;
}

void Gui::Event::debugEvent()
{
    if (_render->getIsDebug())
        _render->setIsDebug(false);
    else
        _render->setIsDebug(true);
}
