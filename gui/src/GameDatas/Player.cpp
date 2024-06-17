/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Player
*/

#include "Config.hpp"
#include "GameDatas/Player.hpp"

Gui::Player::Player(std::size_t id, const std::string &team, std::pair<std::size_t, std::size_t> position, std::size_t orientation, std::size_t level) : _id(id), _team(team), _position(position), _orientation(orientation), _level(level), _state(Gui::Player::IDLE)
{
}

void Gui::Player::setPosition(std::pair<std::size_t, std::size_t> position)
{
    _position = position;
}

void Gui::Player::setId(std::size_t id)
{
    _id = id;
}

void Gui::Player::setLevel(std::size_t level)
{
    _level = level;
}

void Gui::Player::setOrientation(std::size_t orientation)
{
    _orientation = orientation;
}

void Gui::Player::setTeam(const std::string &team)
{
    _team = team;
}

void Gui::Player::setState(PlayerState state)
{
    _state = state;
}

std::pair<std::size_t, std::size_t> Gui::Player::getPosition() const
{
    return _position;
}

std::size_t Gui::Player::getId() const
{
    return _id;
}

std::size_t Gui::Player::getLevel() const
{
    return _level;
}

std::size_t Gui::Player::getOrientation() const
{
    return _orientation;
}

std::string Gui::Player::getTeam() const
{
    return _team;
}

Gui::Player::PlayerState Gui::Player::getState() const
{
    return _state;
}

void Gui::Player::setBroadcast(const std::string &broadcast)
{
    _broadcast = broadcast;
}

std::string Gui::Player::getBroadcast() const
{
    return _broadcast;
}

float Gui::Player::getRotationFromOrientation() const
{
    switch (_orientation) {
    case 1:
        return 180;
    case 2:
        return 90;
    case 3:
        return 0;
    case 4:
        return 270;
    default:
        return 180;
    }
}

Vector3 Gui::Player::getCenterPosition()
{
    return {(float)((double)_position.first * SIZE_TILE + SIZE_TILE / 2), 0, (float)((double)_position.second * SIZE_TILE + SIZE_TILE / 2)};
}
