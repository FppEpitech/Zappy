/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GUIUpdater
*/

#include "GUIUpdater/GUIUpdater.hpp"
#include "Error/Error.hpp"

Gui::GUIUpdater::GUIUpdater(std::shared_ptr<GameData> gameData) : _gameData(gameData) {}

void Gui::GUIUpdater::update(const std::string &command, const std::vector<std::string> &data)
{
    try {
        for (auto &iterator : _updateMap) {
            if (iterator.first == command) {
                iterator.second(data);
            }
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
}

void Gui::GUIUpdater::updateMapSize(const std::vector<std::string> &data)
{
    std::vector<size_t> args;

    try {
        for (size_t i = 0; i < data.size(); i++) {
            args.push_back(std::stoi(data[i]));
            if (args[i] < 1)
                throw Gui::Errors::GuiUpdaterException("Invalid map size");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid map size");
    }
    _gameData->setMapSize(args[0], args[1]);
}

void Gui::GUIUpdater::updateMapContent(const std::vector<std::string> &data)
{
    std::vector<size_t> args;
    Map<Gui::Tile> newMap;
    size_t tmp = 0;

    for (size_t i = 0; i < data.size(); i++) {
        args.push_back(std::stoi(data[i], &tmp));
        if (tmp != data[i].size())
            throw Gui::Errors::GuiUpdaterException("Invalid map content");
    }
    for (size_t y = 0; y < _gameData->getMapSize().second; y++) {
        for (size_t x = 0; x < _gameData->getMapSize().first; x++) {
            if (args[0] == x && args[1] == y) {
                newMap[y][x] = Gui::Tile(std::make_pair(x, y), Gui::Inventory(args[2], args[3], args[4], args[5], args[6], args[7], args[8]));
            }
        }
    }
    _gameData->setMap(newMap);
}

void Gui::GUIUpdater::updateTeamNames(const std::vector<std::string> &data)
{
    try {
        for (size_t i = 0; i < data.size(); i++)
            _gameData->addTeam(data[i]);
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid team names");
    }
}

void Gui::GUIUpdater::updateTeamMember(const std::vector<std::string> &data)
{
    std::vector<size_t> args;
    size_t tmp = 0;

    try {
        for (size_t i = 0; i < data.size(); i++) {
            args.push_back(std::stoi(data[i], &tmp));
            if (tmp != data[i].size())
                throw Gui::Errors::GuiUpdaterException("Invalid team member");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid team member");
    }
    if (args[3] < 1 || args[3] > 4)
        throw Gui::Errors::GuiUpdaterException("Invalid player orientation");
    if (args[4] < 1 || args[4] > 8)
        throw Gui::Errors::GuiUpdaterException("Invalid player level");
    for (auto &team : _gameData->getTeams()) {
        if (team.getName() == data[0]) {
            team.addPlayer(Gui::Player(args[0], data[0], std::make_pair(args[1], args[2]), args[3], args[4]));
        }
    }
}

void Gui::GUIUpdater::updatePlayerPosition(const std::vector<std::string> &data)
{
    std::vector<size_t> args;
    size_t tmp = 0;

    try {
        for (size_t i = 0; i < data.size(); i++) {
            args.push_back(std::stoi(data[i], &tmp));
            if (tmp != data[i].size())
                throw Gui::Errors::GuiUpdaterException("Invalid player position");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid player position");
    }
    if (args[3] < 1 || args[3] > 4)
        throw Gui::Errors::GuiUpdaterException("Invalid player orientation");
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == args[0]) {
                player.setPosition(std::make_pair(args[1], args[2]));
            }
        }
    }
}

void Gui::GUIUpdater::updatePlayerLevel(const std::vector<std::string> &data)
{
    std::vector<size_t> args;
    size_t tmp = 0;

    try {
        for (size_t i = 0; i < data.size(); i++) {
            args.push_back(std::stoi(data[i], &tmp));
            if (tmp != data[i].size())
                throw Gui::Errors::GuiUpdaterException("Invalid player level");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid player level");
    }
    if (args[1] < 1 || args[1] > 8)
        throw Gui::Errors::GuiUpdaterException("Invalid player level");
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == args[0]) {
                player.setLevel(args[1]);
            }
        }
    }
}

void Gui::GUIUpdater::updatePlayerInventory(const std::vector<std::string> &data)
{
    std::vector<size_t> args;
    size_t tmp = 0;

    try {
        for (size_t i = 0; i < data.size(); i++) {
            args.push_back(std::stoi(data[i], &tmp));
            if (tmp != data[i].size())
                throw Gui::Errors::GuiUpdaterException("Invalid player inventory");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid player inventory");
    }
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == args[0]) {
                player._inventory = Gui::Inventory(args[3], args[4], args[5], args[6], args[7], args[8], args[9]);
            }
        }
    }
}

void Gui::GUIUpdater::updatePlayerExpulsion(const std::vector<std::string> &data)
{
    size_t id = 0;
    size_t tmp = 0;

    try {
        id = std::stoi(data[0], &tmp);
        if (tmp != data[0].size())
            throw Gui::Errors::GuiUpdaterException("Invalid player expulsion");
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid player expulsion");
    }
    for (auto &team : _gameData->getTeams()) {
        for (size_t i = 0; i < team.getPlayers().size(); i++) {
            if (team.getPlayers()[i].getId() == id) {
                return;
            }
        }
    }
}

void Gui::GUIUpdater::updatePlayerBroadcast(const std::vector<std::string> &data)
{
    size_t id = 0;
    size_t tmp = 0;

    try {
        id = std::stoi(data[0], &tmp);
        if (tmp != data[0].size())
            throw Gui::Errors::GuiUpdaterException("Invalid player broadcast");
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid player broadcast");
    }
    for (auto &team : _gameData->getTeams()) {
        for (size_t i = 0; i < team.getPlayers().size(); i++) {
            if (team.getPlayers()[i].getId() == id) {
                return;
            }
        }
    }
}
