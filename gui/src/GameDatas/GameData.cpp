/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GameData
*/

#include "GameDatas/GameData.hpp"
#include "Error/Error.hpp"

Gui::GameData::GameData() {}

std::vector<Gui::Team> &Gui::GameData::getTeams()
{
    return _teams;
}

Gui::Team &Gui::GameData::getTeam(const std::string &name)
{
    for (auto &team : _teams) {
        if (team.getName() == name)
            return team;
    }
    throw Gui::Errors::GuiGameDataException("Team not found");
}

void Gui::GameData::addTeam(const Gui::Team &team)
{
    for (auto &t : _teams) {
        if (t.getName() == team.getName())
            throw Gui::Errors::GuiGameDataException("Team already exists");
    }
    _teams.push_back(team);
}

void Gui::GameData::addTeam(const std::string &name)
{
    for (auto &team : _teams) {
        if (team.getName() == name)
            throw Gui::Errors::GuiGameDataException("Team already exists");
    }
    _teams.push_back(Gui::Team(name));
}

Map<Gui::Tile> &Gui::GameData::getMap()
{
    return _map;
}

void Gui::GameData::setMap(const Map<Gui::Tile> &map)
{
    _map = map;
}

Gui::Tile &Gui::GameData::getTile(size_t x, size_t y)
{
    if (x >= _map.size() || y >= _map[x].size())
        throw Gui::Errors::GuiGameDataException("Tile not found");
    return _map[x][y];
}
