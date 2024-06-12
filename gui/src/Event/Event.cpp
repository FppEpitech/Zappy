/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Event
*/

#include "raylib.h"
#include "Assets.hpp"
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

void Gui::Event::setFreeCam()
{
    _render->setCameraType(Gui::UserCamera::FREE);
}

void Gui::Event::handleLeftClick()
{
    if (_render->getCameraType() == Gui::UserCamera::CameraType::FREE)
        selectPlayer();
    else
        changePlayer(true);
}

void Gui::Event::handleRightClick()
{
    if (_render->getCameraType() == Gui::UserCamera::CameraType::POV_PLAYER)
        changePlayer(false);
}

void Gui::Event::selectPlayer()
{
    BeginDrawing();
    BeginMode3D(*_render.get()->getCamera().get());
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (_render.get()->getIsDebug()) {
                std::vector<BoundingBox> bboxes = team.getPlayerBoundingBoxes(player.getPosition(), player.getOrientation(), player.getCenterPosition());
                std::vector<RayCollision> hitbox = team.getPlayerModelHitbox(player.getId(), *_render.get()->getCamera().get());

                for (size_t i = 0; i < bboxes.size(); i++) {
                    if (hitbox[i].hit)
                        DrawBoundingBox(bboxes[i], RED);
                }
            }
            if (team.isPlayerHit(player.getId(), *_render.get()->getCamera().get()))
                this->changeCameraToPlayer(player.getId());
        }
    }
    EndMode3D();
    EndDrawing();
}

void Gui::Event::changePlayer(bool turn)
{
    size_t playerId = _render.get()->getCameraPlayerPov();
    std::vector<Team> teams = _gameData.get()->getTeams();
    bool changed = false;

    if (turn) {
        for (int i = 0; i < (int)teams.size(); i++) {
            for (int j = 0; j < (int)teams[i].getPlayers().size() && !changed; j++) {
                if (teams[i].getPlayers()[j].getId() == playerId && (j + 1 < (int)teams[i].getPlayers().size())) {
                    playerId = teams[i].getPlayers()[j + 1].getId();
                    changed = true;
                }
                if (teams[i].getPlayers()[j].getId() == playerId && (j + 1 == (int)teams[i].getPlayers().size()) && (i + 1 < (int)teams.size()) && teams[i + 1].getPlayers().size() > 0) {
                    playerId = teams[i + 1].getPlayers()[0].getId();
                    changed = true;
                }
            }
        }
    } else {
        std::vector<Team> teams = _gameData.get()->getTeams();
        for (int i = (int)teams.size() - 1; i >= 0; i--) {
            for (int j = (int)teams[i].getPlayers().size() - 1; j >= 0 && !changed; j--) {
                if (teams[i].getPlayers()[j].getId() == playerId && (j - 1 >= 0)) {
                    playerId = teams[i].getPlayers()[j - 1].getId();
                    changed = true;
                }
                if (teams[i].getPlayers()[j].getId() == playerId && (j - 1 < 0) && (i - 1 >= 0) && teams[i - 1].getPlayers().size() > 0) {
                    playerId = teams[i - 1].getPlayers()[teams[i - 1].getPlayers().size() - 1].getId();
                    changed = true;
                }
            }
        }
    }
    changeCameraToPlayer(playerId);
}

void Gui::Event::changeCameraToPlayer(size_t playerId)
{
    Gui::Player player = _gameData->getPlayer(playerId);
    Vector3 playerPos;

    try {
        playerPos = _gameData.get()->getTeamById(player.getId()).getPlayerPositionIn3DSpace(playerId, _gameData.get()->getMap());
    } catch (const Gui::Errors::GuiGameDataException &e) {
        return;
    }
    _render.get()->getCamera().get()->position = playerPos;
    _render.get()->getCamera().get()->position.y = playerPos.y + 4.0f;

    if (player.getOrientation() == 1)
        _render.get()->getCamera().get()->position.z = playerPos.z + 5.0f;
    else if (player.getOrientation() == 3)
        _render.get()->getCamera().get()->position.z = playerPos.z - 5.0f;
    else if (player.getOrientation() == 2)
        _render.get()->getCamera().get()->position.x = playerPos.x - 5.0f;
    else if (player.getOrientation() == 4)
        _render.get()->getCamera().get()->position.x = playerPos.x + 5.0f;
    _render.get()->getCamera().get()->target = playerPos;
    _render.get()->getCamera().get()->target.y += PLAYER_HEIGHT;
    _render.get()->setCameraType(Gui::UserCamera::POV_PLAYER);
    _render.get()->setCameraPlayerPov(playerId);
}

