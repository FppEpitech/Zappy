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
    // Ray ray;
    // RayCollision collision;
    // collision.distance = FLOAT_MAX;
    // collision.hit = false;

    // BoundingBox towerBBox = GetMeshBoundingBox(_gameData->getTeams()[0].getPlayerModel().meshes[0]);


    // RayCollision boxHitInfo = GetRayCollisionBox(ray, towerBBox);
    // DrawBoundingBox(towerBBox, LIME);

    // if ((boxHitInfo.hit) && (boxHitInfo.distance < collision.distance))
    //     {
    //     std::cout << "hit" << std::endl;
    //         collision = boxHitInfo;

    //         RayCollision meshHitInfo;
    //         for (int m = 0; m < _gameData->getTeam("NAROUT").getPlayerModel().meshCount; m++)
    //         {
    //             // NOTE: We consider the model.transform for the collision check but
    //             // it can be checked against any transform Matrix, used when checking against same
    //             // model drawn multiple times with multiple transforms
    //             meshHitInfo = GetRayCollisionMesh(ray, _gameData->getTeam("NAROUT").getPlayerModel().meshes[m], _gameData->getTeam("NAROUT").getPlayerModel().transform);
    //             if (meshHitInfo.hit)
    //             {
    //                 // Save the closest hit mesh
    //                 if ((!collision.hit) || (collision.distance > meshHitInfo.distance)) collision = meshHitInfo;

    //                 break;  // Stop once one mesh collision is detected, the colliding mesh is m
    //             }
    //         }

    //         if (meshHitInfo.hit)
    //         {
    //             collision = meshHitInfo;
    //         }
    //     }
}
