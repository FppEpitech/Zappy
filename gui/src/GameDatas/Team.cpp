/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Team
*/

#include "GameDatas/Team.hpp"

Gui::Team::Team(const std::string &name, const std::string &playerModelPath) : _name(name)
{
    _playerModel = LoadModel(playerModelPath.c_str());
}
Gui::Team::Team(const std::string &name, const std::string &eggModelPath)
    : _name{name}
{
    _eggModel = LoadModel(eggModelPath.c_str());
}

const std::string &Gui::Team::getName() const
{
    return _name;
}

Gui::Team::~Team()
{
}

void Gui::Team::setName(const std::string &name)
{
    _name = name;
}

std::vector<Gui::Player> &Gui::Team::getPlayers()
{
    return _players;
}

std::vector<Gui::Egg> &Gui::Team::getEggs()
{
    return _eggs;
}

void Gui::Team::addPlayer(const Gui::Player &player)
{
    _players.push_back(player);
}

void Gui::Team::addEgg(const Gui::Egg &egg)
{
    _eggs.push_back(egg);
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

bool Gui::Team::removeEgg(std::size_t id)
{
    for (auto iterator = _eggs.begin(); iterator != _eggs.end(); iterator++) {
        if (iterator->getId() == id) {
            _eggs.erase(iterator);
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

Model Gui::Team::getPlayerModel(void) const
{
    return _playerModel;
}

std::shared_ptr<Gui::Egg> Gui::Team::getEgg(std::size_t id)
{
    for (auto &egg : _eggs) {
        if (egg.getId() == id) {
            return std::make_shared<Gui::Egg>(egg);
        }
    }
    return nullptr;
}

Model Gui::Team::getEggModel() const
{
    return _eggModel;
}

void Gui::Team::setEggModelPath(const std::string &eggModelPath)
{
    _eggModel = LoadModel(eggModelPath.c_str());
}
