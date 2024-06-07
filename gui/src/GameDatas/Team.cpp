/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Team
*/

#include "GameDatas/Team.hpp"

Gui::Team::Team(const std::string &name, const std::string &playerModelPath) : _name(name)
{
    _model = LoadModel(playerModelPath.c_str());
}

const std::string &Gui::Team::getName() const
{
    return _name;
}

void Gui::Team::setName(const std::string &name)
{
    _name = name;
}

std::vector<Gui::Player> &Gui::Team::getPlayers()
{
    return _players;
}

void Gui::Team::addPlayer(const Gui::Player &player)
{
    _players.push_back(player);
}

bool Gui::Team::removePlayer(std::size_t id)
{
    for (auto iterator = _players.begin(); iterator != _players.end(); iterator++) {
        if (iterator->getId() == id) {
            _players.erase(iterator);
            return true;
        }
    }
    return false;
}

std::shared_ptr<Gui::Player> Gui::Team::getPlayer(std::size_t id)
{
    for (auto &player : _players) {
        if (player.getId() == id) {
            return std::make_shared<Gui::Player>(player);
        }
    }
    return nullptr;
}

Model Gui::Team::getModel(void) const
{
    return _model;
}
