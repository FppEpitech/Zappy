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
    for (auto &event : _eventsMousePressed) {
        if (IsMouseButtonPressed(event.first))
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
    if (_render->getCameraType() != Gui::UserCamera::FREE)
        return;
    _render->getCamera()->position.y += HIGH_CAMERA_INCREASE;
    _render->getCamera()->target.y += HIGH_CAMERA_INCREASE;
}

void Gui::Event::moveDownCamera()
{
    if (_render->getCameraType() != Gui::UserCamera::FREE)
        return;
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
    _render->setCameraType(Gui::UserCamera::FREE);
}

void Gui::Event::switchPovRight()
{
    _render->setCameraType(Gui::UserCamera::POV_PLAYER);
    UpdateCamera(_render->getCamera().get(), CAMERA_THIRD_PERSON);
}

void Gui::Event::selectPlayer()
{
    BeginDrawing();
    BeginMode3D(*_render.get()->getCamera().get());
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (_render.get()->getIsDebug()) {
                std::vector<BoundingBox> bboxes = team.getPlayerBoundingBoxes();
                std::vector<RayCollision> hitbox = team.getPlayerModelHitbox(player.getId(), *_render.get()->getCamera().get());

                for (size_t i = 0; i < bboxes.size(); i++) {
                    if (hitbox[i].hit) {
                        DrawBoundingBox(bboxes[i], RED);
                    }
                }
            }
        }
    }
    EndMode3D();
    EndDrawing();
}
