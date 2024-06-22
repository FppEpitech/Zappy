/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Event
*/

#include "raylib.h"
#include "Assets.hpp"
#include "Config.hpp"
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
    for (auto &event : _eventsGamepadButtonDown) {
        if (IsGamepadButtonDown(0, event.first))
            event.second();
    }
    for (auto &event : _eventsGamepadButtonPressed) {
        if (IsGamepadButtonPressed(0, event.first))
            event.second();
    }
}

void Gui::Event::moveUpCamera()
{
    if (_render->getCameraType() != Gui::UserCamera::FREE && _render->getCameraType() != Gui::UserCamera::FREE_TILE)
        return;
    _render->getCamera()->position.y += HIGH_CAMERA_INCREASE;
    _render->getCamera()->target.y += HIGH_CAMERA_INCREASE;
}

void Gui::Event::moveDownCamera()
{
    if (_render->getCameraType() != Gui::UserCamera::FREE && _render->getCameraType() != Gui::UserCamera::FREE_TILE)
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

void Gui::Event::setFreeCam()
{
    if (_render->getCameraType() != Gui::UserCamera::FREE && _render->getCameraType() != Gui::UserCamera::FREE_TILE)
        _render->setCameraType(Gui::UserCamera::FREE);
}

void Gui::Event::handleLeftClick()
{
    if (_render->getCameraType() == Gui::UserCamera::CameraType::FREE || _render->getCameraType() == Gui::UserCamera::CameraType::FREE_TILE) {
        selectPlayer();
        selectTile();
    } else
        changePlayer(true);
}

void Gui::Event::handleRightClick()
{
    if (_render.get()->isCameraInPlayerPov())
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
                _render.get()->changePOVToFirstPerson(player.getId());
        }
    }
    EndMode3D();
    EndDrawing();
}

void Gui::Event::selectTile()
{
    BeginDrawing();
    BeginMode3D(*_render.get()->getCamera().get());
    for (auto &line : _gameData.get()->getMap()) {
        for (auto &tile : line) {
            if (_render.get()->getIsDebug()) {
                std::vector<BoundingBox> bboxes = tile.getTileBoundingBoxes(tile, _render.get()->getTileModel());
                std::vector<RayCollision> hitbox = tile.getTileModelHitbox(tile, *_render.get()->getCamera().get(), _render.get()->getTileModel());

                for (size_t i = 0; i < bboxes.size(); i++) {
                    if (hitbox[i].hit)
                        DrawBoundingBox(bboxes[i], RED);
                }
            }
            if (tile.isTileHit(*_render.get()->getCamera().get(), _render.get()->getTileModel())) {
                _render.get()->setCameraType(Gui::UserCamera::FREE_TILE);
                _render.get()->setCameraTile(tile.getPosition());
            }
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
    _render.get()->setPlayerPov(playerId);
}

void Gui::Event::changeActualPlayerPov()
{
    _render.get()->changePlayerPOV(_render.get()->getCameraPlayerPov());
}

void Gui::Event::switchTileHudToGame()
{
    if (_render.get()->getCameraType() == Gui::UserCamera::FREE_TILE)
        _render.get()->setCameraType(Gui::UserCamera::FREE);
}

void Gui::Event::increaseRenderDistance()
{
    _render.get()->setRenderDistance(_render.get()->getRenderDistance() + 1);
}

void Gui::Event::decreaseRenderDistance()
{
    _render.get()->setRenderDistance(_render.get()->getRenderDistance() - 1);
}

void Gui::Event::increaseTimeUnit()
{
    if (_gameData.get()->getTimeUnitFromServer() == GameData::TimeUnitState::NONE)
        _gameData.get()->setTimeUnitFromServer(GameData::TimeUnitState::INCREASE);
}

void Gui::Event::decreaseTimeUnit()
{
    if (_gameData.get()->getTimeUnitFromServer() == GameData::TimeUnitState::NONE)
        _gameData.get()->setTimeUnitFromServer(GameData::TimeUnitState::DECREASE);
}

void Gui::Event::handleSpaceGamepad()
{
    setFreeCam();
    moveUpCamera();
}

void Gui::Event::closeWindowGamepad()
{
    _gameData.get()->setIsEndGame(true);
}

void Gui::Event::setPlayerVision()
{
    _render.get()->setPlayerVision(!_render.get()->getPlayerVision());
}
