/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Egg
*/

#include "GameDatas/Egg.hpp"

Gui::Egg::Egg(size_t id, const std::string &team, std::pair<std::size_t, std::size_t> position)
    : _id{id}, _team{team}, _position{position}
{
    // TODO: Implement egg animation.
}

Gui::Egg::~Egg()
{
    // TODO: Implement egg destruction.
}

std::size_t Gui::Egg::getId() const
{
    return _id;
}

std::string Gui::Egg::getTeam() const
{
    return _team;
}

std::pair<std::size_t, std::size_t> Gui::Egg::getPosition() const
{
    return _position;
}

void Gui::Egg::setPosition(std::pair<std::size_t, std::size_t> position)
{
    _position = position;
}

void Gui::Egg::setTeam(const std::string &team)
{
    _team = team;
}

void Gui::Egg::setId(std::size_t id)
{
    _id = id;
}
