/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GameData
*/

#include "GameDatas/GameData.hpp"

Gui::GameData::GameData()
{
    _teams = std::vector<Gui::Team>();
    _map = Map<Gui::Tile>();
    _serverTick = NO_TICK;
    _lastTick = clock();
    _isEndGame = false;
    _serverEggs = std::vector<Gui::Egg>();
    _lastTickMctCommand = clock();
    _nbBCTCommandReceived = 0;
    _timeUnitFromServer = TimeUnitState::NONE;
    _endMessage = "";
}

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
    for (auto &registeredTeam : _teams) {
        if (registeredTeam.getName() == team.getName())
            throw Gui::Errors::GuiGameDataException("Team already exists");
    }
    _teams.push_back(team);
}

void Gui::GameData::addTeam(const std::string &name, const std::string &playerModelPath, const std::string &eggModelPath, Color playerColor)
{
    for (auto &regsiteredTeam : _teams) {
        if (regsiteredTeam.getName() == name)
            throw Gui::Errors::GuiGameDataException("Team already exists");
    }
    _teams.push_back(Gui::Team(name, playerModelPath, eggModelPath, playerColor));
}

void Gui::GameData::addPlayerToTeam(const std::string &teamName, const Gui::Player &player)
{
    for (auto &team : _teams) {
        if (team.getName() == teamName) {
            team.addPlayer(player);
            return;
        }
    }
    throw Gui::Errors::GuiGameDataException("Team not found");
}

Gui::Player &Gui::GameData::getPlayer(size_t id)
{
    for (auto &team : _teams) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == id)
                return player;
        }
    }
    throw Gui::Errors::GuiGameDataException("Player not found");
}

Map<Gui::Tile> &Gui::GameData::getMap()
{
    return _map;
}

void Gui::GameData::setMap(const Map<Gui::Tile> &map)
{
    _map = map;
}

void Gui::GameData::setMapSize(size_t x, size_t y)
{
    Map<Gui::Tile> newMap;

    for (size_t i = 0; i < x; i++) {
        std::vector<Gui::Tile> row;
        for (size_t j = 0; j < y; j++) {
            if (i < _map.size() && j < _map[i].size())
                row.push_back(_map[i][j]);
            else
                row.push_back(Gui::Tile(std::make_pair(i, j)));
        }
        newMap.push_back(row);
    }
    _map = newMap;
}

std::pair<size_t, size_t> Gui::GameData::getMapSize() const
{
    if (_map.empty())
        return std::make_pair(0, 0);
    if (_map[0].empty())
        return std::make_pair(_map.size(), 0);
    return std::make_pair(_map.size(), _map[0].size());
}

Gui::Tile &Gui::GameData::getTile(size_t x, size_t y)
{
    if (x >= _map.size() || y >= _map[x].size())
        throw Gui::Errors::GuiGameDataException("Tile not found");
    return _map[x][y];
}

void Gui::GameData::setTile(const Gui::Tile &tile)
{
    if (tile.getPosition().first >= _map.size() || tile.getPosition().second >= _map[tile.getPosition().first].size())
        throw Gui::Errors::GuiGameDataException("Tile not found");
    _map[tile.getPosition().first][tile.getPosition().second] = tile;
}

void Gui::GameData::restartLastTick()
{
    _lastTick = clock();
}

void Gui::GameData::setServerTick(std::size_t tick)
{
    _serverTick = tick;
}

clock_t Gui::GameData::getLastTick() const
{
    return _lastTick;
}

std::size_t Gui::GameData::getServerTick() const
{
    return _serverTick;
}

void Gui::GameData::setIsEndGame(bool isEndGame)
{
    _isEndGame = isEndGame;
}

bool Gui::GameData::getIsEndGame() const
{
    return _isEndGame;
}

void Gui::GameData::setLastError(const std::string &error)
{
    _lastError = error;
}

std::string Gui::GameData::getLastError() const
{
    return _lastError;
}

Gui::Team &Gui::GameData::getTeamById(size_t id)
{
    for (auto &team : _teams) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == id)
                return team;
        }
    }
    throw Gui::Errors::GuiGameDataException("Team not found");
}

Gui::GameData::TimeUnitState Gui::GameData::getTimeUnitFromServer() const
{
    return _timeUnitFromServer;
}

void Gui::GameData::setTimeUnitFromServer(TimeUnitState timeUnitFromServer)
{
    _timeUnitFromServer = timeUnitFromServer;
}

std::vector<Gui::Egg> &Gui::GameData::getServerEggs()
{
    return _serverEggs;
}

void Gui::GameData::addServerEgg(const Gui::Egg &egg)
{
    for (auto &registeredEgg : _serverEggs) {
        if (registeredEgg.getId() == egg.getId())
            throw Gui::Errors::GuiGameDataException("Egg already exists");
    }
    _serverEggs.push_back(egg);
}

void Gui::GameData::removeServerEgg(size_t id)
{
    for (size_t i = 0; i < _serverEggs.size(); i++) {
        if (_serverEggs[i].getId() == id) {
            _serverEggs.erase(_serverEggs.begin() + i);
            return;
        }
    }
}

std::size_t Gui::GameData::getNbBCTCommandReceived() const
{
    return _nbBCTCommandReceived;
}

void Gui::GameData::setNbBCTCommandReceived(std::size_t nb)
{
    _nbBCTCommandReceived = nb;
}

void Gui::GameData::restartLastTickMctCommand()
{
    _lastTickMctCommand = clock();
}

clock_t Gui::GameData::getLastTickMctCommand() const
{
    return _lastTickMctCommand;
}

void Gui::GameData::setEndMessage(const std::string &message)
{
    _endMessage = message;
}

std::string Gui::GameData::getEndMessage() const
{
    return _endMessage;
}
