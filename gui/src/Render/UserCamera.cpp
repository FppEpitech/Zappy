/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** UserCamera
*/

#include "Render/UserCamera.hpp"

Gui::UserCamera::UserCamera()
{
    _camera = std::make_shared<Camera>();
    _camera->position = (Vector3){ 5.0f, 5.0f, 5.0f };
    _camera->target = (Vector3){ 0.0f, 2.0f, 0.0f };
    _camera->up = (Vector3){ 0.0f, 1.0f, 0.0f };
    _camera->fovy = 70.0f;
    _camera->projection = CAMERA_PERSPECTIVE;
    _type = FREE;
}

void Gui::UserCamera::setPosition(Vector3 position)
{
    _camera->position = position;
}

void Gui::UserCamera::setTarget(Vector3 target)
{
    _camera->target = target;
}

void Gui::UserCamera::setUp(Vector3 up)
{
    _camera->up = up;
}

void Gui::UserCamera::setFovy(float fovy)
{
    _camera->fovy = fovy;
}

void Gui::UserCamera::setType(CameraType type)
{
    _type = type;
}

Vector3 Gui::UserCamera::getPosition(void) const
{
    return _camera->position;
}

Vector3 Gui::UserCamera::getTarget(void) const
{
    return _camera->target;
}

Vector3 Gui::UserCamera::getUp(void) const
{
    return _camera->up;
}

float Gui::UserCamera::getFovy(void) const
{
    return _camera->fovy;
}

std::shared_ptr<Camera> Gui::UserCamera::getCamera()
{
    return _camera;
}

Gui::UserCamera::CameraType Gui::UserCamera::getType() const
{
    return _type;
}

void Gui::UserCamera::setPlayerId(size_t id)
{
    _playerId = id;
}

size_t Gui::UserCamera::getPlayerId() const
{
    return _playerId;
}

void Gui::UserCamera::setTilePos(std::pair<std::size_t, std::size_t> pos)
{
    _tilePos = pos;
}

std::pair<std::size_t, std::size_t> Gui::UserCamera::getTilePos() const
{
    return _tilePos;
}

bool Gui::UserCamera::isPlayerPov() const
{
    return _type == FIRST_PERSON || _type == SECOND_PERSON || _type == THIRD_PERSON;
}

bool Gui::UserCamera::isPlayerVision() const
{
    return _isPlayerVision;
}

void Gui::UserCamera::setPlayerVision(bool isPlayerVision)
{
    _isPlayerVision = isPlayerVision;
}
