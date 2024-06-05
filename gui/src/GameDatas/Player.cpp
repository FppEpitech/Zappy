/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Player
*/

#include "GameDatas/Player.hpp"

Gui::Player::Player(std::size_t id, const std::string &team, std::pair<std::size_t, std::size_t> position, std::size_t orientation, std::size_t level) : _id(id), _team(team), _position(position), _orientation(orientation), _level(level)
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

std::pair<std::size_t, std::size_t> Gui::Player::getPosition(void) const
{
    return _position;
}

std::size_t Gui::Player::getId(void) const
{
    return _id;
}

std::size_t Gui::Player::getLevel(void) const
{
    return _level;
}

std::size_t Gui::Player::getOrientation(void) const
{
    return _orientation;
}

std::string Gui::Player::getTeam(void) const
{
    return _team;
}
