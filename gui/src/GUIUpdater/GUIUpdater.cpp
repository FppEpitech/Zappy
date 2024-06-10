/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GUIUpdater
*/

#include "Assets.hpp"
#include "Error/Error.hpp"
#include "GUIUpdater/GUIUpdater.hpp"

Gui::GUIUpdater::GUIUpdater(std::shared_ptr<GameData> gameData, std::shared_ptr<Network> network) : _gameData(gameData), _network(network) {}

void Gui::GUIUpdater::update(const std::string &command, const std::vector<std::string> &data)
{
    try {
        for (auto &iterator : _updateMap)
            if (iterator.first == command)
                iterator.second(data);
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
}

void Gui::GUIUpdater::updateMapSize(const std::vector<std::string> &data)
{
    std::vector<size_t> args;
    size_t tmp = 0;

    try {
        for (size_t i = 0; i < data.size(); i++) {
            int temp = std::stoi(data[i], &tmp);
            if (temp < 0 || tmp != data[i].size())
                throw Gui::Errors::GuiUpdaterException("Invalid map size");
            args.push_back(temp);
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid map size");
    }
    if (args.size() != 2)
        throw Gui::Errors::GuiUpdaterException("Invalid map size");
    _gameData->setMapSize(args[0], args[1]);
}

void Gui::GUIUpdater::updateMapContent(const std::vector<std::string> &data)
{
    std::vector<size_t> args;
    size_t tmp = 0;

    try {
        for (size_t i = 0; i < data.size(); i++) {
            int temp = std::stoi(data[i], &tmp);
            if (temp < 0 || tmp != data[i].size())
                throw Gui::Errors::GuiUpdaterException("Invalid map content");
            args.push_back(temp);
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid map content");
    }
    if (args.size() != 9)
        throw Gui::Errors::GuiUpdaterException("Invalid map content");
    try {
        _gameData.get()->setTile(Gui::Tile(std::make_pair(args[0], args[1]), Gui::Inventory(args[2], args[3], args[4], args[5], args[6], args[7], args[8])));
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid map content");
    }
}

void Gui::GUIUpdater::updateTeamNames(const std::vector<std::string> &data)
{
    try {
        for (size_t i = 0; i < data.size(); i++)
            _gameData->addTeam(data[i], MODEL_PLAYER, MODEL_EGG);
        // TODO: Implement a system that allows to set different models for each team.
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid team names");
    }
    if (_gameData->getTeams().empty())
        throw Gui::Errors::GuiUpdaterException("Invalid team names");
}

void Gui::GUIUpdater::updateTeamMember(const std::vector<std::string> &data)
{
    std::vector<size_t> args;
    size_t tmp = 0;

    try {
        for (size_t i = 1; i < data.size(); i++) {
            int temp = std::stoi(data[i], &tmp);
            if (temp < 0 || tmp != data[i].size())
                throw Gui::Errors::GuiUpdaterException("Invalid team member");
            args.push_back(temp);
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid team member");
    }
    if (args.size() != 5)
        throw Gui::Errors::GuiUpdaterException("Invalid team member");
    if (args[2] < 1 || args[2] > 4)
        throw Gui::Errors::GuiUpdaterException("Invalid player orientation");
    if (args[3] < 1 || args[3] > 8)
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
            int temp = std::stoi(data[i], &tmp);
            args.push_back(temp);
            if (temp < 0 || tmp != data[i].size())
                throw Gui::Errors::GuiUpdaterException("Invalid player position");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid player position");
    }
    if (args.size() != 4)
        throw Gui::Errors::GuiUpdaterException("Invalid player position");
    if (args[3] < 1 || args[3] > 4)
        throw Gui::Errors::GuiUpdaterException("Invalid player orientation");
    for (auto &team : _gameData.get()->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == args[0]) {
                player.setPosition(std::make_pair(args[1], args[2]));
                player.setOrientation(args[3]);
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
            int temp = std::stoi(data[i], &tmp);
            args.push_back(temp);
            if (temp < 0 || tmp != data[i].size())
                throw Gui::Errors::GuiUpdaterException("Invalid player level");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid player level");
    }
    if (args.size() != 2)
        throw Gui::Errors::GuiUpdaterException("Invalid player level");
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
            int temp = std::stoi(data[i], &tmp);
            args.push_back(temp);
            if (temp < 0 || tmp != data[i].size())
                throw Gui::Errors::GuiUpdaterException("Invalid player inventory");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid player inventory");
    }
    if (args.size() != 10)
        throw Gui::Errors::GuiUpdaterException("Invalid player inventory");
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == args[0]) {
                player.inventory = Gui::Inventory(args[3], args[4], args[5], args[6], args[7], args[8], args[9]);
                player.setPosition(std::make_pair(args[1], args[2]));
            }
        }
    }
}

void Gui::GUIUpdater::updatePlayerExpulsion(const std::vector<std::string> &data)
{
    size_t id = 0;
    size_t tmp = 0;

    try {
        int temp = std::stoi(data[0], &tmp);
        if (temp < 0 || tmp != data[0].size())
            throw Gui::Errors::GuiUpdaterException("Invalid player expulsion");
        id = temp;
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid player expulsion");
    }
    for (auto &team : _gameData->getTeams()) {
        for (size_t i = 0; i < team.getPlayers().size(); i++) {
            if (team.getPlayers()[i].getId() == id) {
                return; // TODO: Implement the player state
            }
        }
    }
}

void Gui::GUIUpdater::updatePlayerBroadcast(const std::vector<std::string> &data)
{
    size_t id = 0;
    size_t tmp = 0;

    try {
        int temp = std::stoi(data[0], &tmp);
        if (temp < 0 || tmp != data[0].size())
            throw Gui::Errors::GuiUpdaterException("Invalid player broadcast");
        id = temp;
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid player broadcast");
    }
    for (auto &team : _gameData->getTeams()) {
        for (size_t i = 0; i < team.getPlayers().size(); i++) {
            if (team.getPlayers()[i].getId() == id) {
                return; // TODO: Implement the player state
            }
        }
    }
}

void Gui::GUIUpdater::updatePlayerStartIncantation(const std::vector<std::string> &data)
{
    std::vector<size_t> args;
    size_t tmp = 0;

    try {
        for (size_t i = 0; i < data.size(); i++) {
            int temp = std::stoi(data[i], &tmp);
            args.push_back(temp);
            if (temp < 0 || tmp != data[i].size())
                throw Gui::Errors::GuiUpdaterException("Invalid player start incantation");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid player start incantation");
    }
    if (args.size() < 4)
        throw Gui::Errors::GuiUpdaterException("Invalid player start incantation");
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == args[0]) {
                return; // TODO: Implement the player state
            }
        }
    }
}

void Gui::GUIUpdater::updatePlayerEndIncantation(const std::vector<std::string> &data)
{
    std::vector<size_t> args;
    size_t tmp = 0;

    try {
        for (size_t i = 0; i < data.size(); i++) {
            int temp = std::stoi(data[i], &tmp);
            args.push_back(temp);
            if (temp < 0 || tmp != data[i].size())
                throw Gui::Errors::GuiUpdaterException("Invalid player end incantation");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid player end incantation");
    }
    if (args.size() != 3)
        throw Gui::Errors::GuiUpdaterException("Invalid player end incantation");
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == args[0]) {
                return; // TODO: Implement the player state
            }
        }
    }
}

void Gui::GUIUpdater::updatePlayerEggLaying(const std::vector<std::string> &data)
{
    size_t id = 0;
    size_t tmp = 0;

    try {
        int temp = std::stoi(data[0], &tmp);
        if (temp < 0 || tmp != data[0].size())
            throw Gui::Errors::GuiUpdaterException("Invalid egg laying");
        id = temp;
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid egg laying");
    }
    for (auto &team : _gameData->getTeams()) {
        for (size_t i = 0; i < team.getPlayers().size(); i++) {
            if (team.getPlayers()[i].getId() == id) {
                return; // TODO: Implement the player state and egg class
            }
        }
    }
}

void Gui::GUIUpdater::updatePlayerRessourceDropping(const std::vector<std::string> &data)
{
    std::vector<size_t> args;
    size_t tmp = 0;

    try {
        for (size_t i = 0; i < data.size(); i++) {
            int temp = std::stoi(data[i], &tmp);
            args.push_back(temp);
            if (temp < 0 || tmp != data[i].size())
                throw Gui::Errors::GuiUpdaterException("Invalid ressource dropping");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid ressource dropping");
    }
    if (args.size() != 2)
        throw Gui::Errors::GuiUpdaterException("Invalid ressource dropping");
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == args[0]) {
                return; // TODO: Implement the player state
            }
        }
    }
}

void Gui::GUIUpdater::updatePlayerRessourceCollecting(const std::vector<std::string> &data)
{
    std::vector<size_t> args;
    size_t tmp = 0;

    try {
        for (size_t i = 0; i < data.size(); i++) {
            int temp = std::stoi(data[i], &tmp);
            args.push_back(temp);
            if (temp < 0 || tmp != data[i].size())
                throw Gui::Errors::GuiUpdaterException("Invalid ressource collecting");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid ressource collecting");
    }
    if (args.size() != 2)
        throw Gui::Errors::GuiUpdaterException("Invalid ressource collecting");
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == args[0]) {
                return; // TODO: Implement the player state
            }
        }
    }
}

void Gui::GUIUpdater::updatePlayerDeath(const std::vector<std::string> &data)
{
    size_t id = 0;
    size_t tmp = 0;

    try {
        int temp = std::stoi(data[0], &tmp);
        if (temp < 0 || tmp != data[0].size())
            throw Gui::Errors::GuiUpdaterException("Invalid player death");
        id = temp;
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid player death");
    }
    for (auto &team : _gameData->getTeams()) {
        for (size_t i = 0; i < team.getPlayers().size(); i++) {
            if (team.getPlayers()[i].getId() == id) {
                return; // TODO: Implement the player state
            }
        }
    }
}

void Gui::GUIUpdater::updateEggLaidByPlayer(const std::vector<std::string> &data)
{
    std::vector<size_t> args;
    size_t tmp = 0;
    int serverId = 0;

    try {
        for (size_t i = 0; i < data.size(); i++) {
            int temp = std::stoi(data[i], &tmp);
            if (i == 1 && temp == -1) {
                serverId = temp;
                args.push_back(0);
                continue;
            }
            args.push_back(temp);
            if (temp < 0 || tmp != data[i].size())
                throw Gui::Errors::GuiUpdaterException("Invalid egg laid by player");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid egg laid by player");
    }
    if (args.size() != 4)
        throw Gui::Errors::GuiUpdaterException("Invalid egg laid by player");
    for (auto &team : _gameData->getTeams()) {
        if (serverId != 0) {
            team.addEgg(Gui::Egg(args[0], team.getName(), std::make_pair(args[2], args[3])));
            std::cout << "Egg laid by player" << std::endl;
        }
        for (auto &player : team.getPlayers()) {
            if (player.getId() == args[1]) {
                team.addEgg(Gui::Egg(args[0], team.getName(), std::make_pair(args[2], args[3])));
            }
        }
    }
}

void Gui::GUIUpdater::updatePlayerBorn(const std::vector<std::string> &data)
{
    size_t id = 0;
    size_t tmp = 0;

    try {
        int temp = std::stoi(data[0], &tmp);
        if (temp < 0 || tmp != data[0].size())
            throw Gui::Errors::GuiUpdaterException("Invalid player born");
        id = temp;
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid player born");
    }
    for (auto &team : _gameData->getTeams()) {
        for (size_t i = 0; i < team.getPlayers().size(); i++) {
            if (team.getPlayers()[i].getId() == id) {
                return; // TODO: Implement the player state and egg class
            }
        }
    }
}

void Gui::GUIUpdater::updateEggDeath(const std::vector<std::string> &data)
{
    size_t id = 0;
    size_t tmp = 0;

    try {
        int temp = std::stoi(data[0], &tmp);
        if (temp < 0 || tmp != data[0].size())
            throw Gui::Errors::GuiUpdaterException("Invalid egg death");
        id = temp;
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid egg death");
    }
    for (auto &team : _gameData->getTeams()) {
        for (size_t i = 0; i < team.getPlayers().size(); i++) {
            if (team.getPlayers()[i].getId() == id) {
                return; // TODO: Implement the egg class
            }
        }
    }
}

void Gui::GUIUpdater::updateTimeUnitRequest(const std::vector<std::string> &data)
{
    size_t timeUnit = 0;
    size_t tmp = 0;

    try {
        int temp = std::stoi(data[0], &tmp);
        if (temp < 0 || tmp != data[0].size())
            throw Gui::Errors::GuiUpdaterException("Invalid time unit request");
        timeUnit = temp;
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid time unit request");
    }
    _gameData->setServerTick(timeUnit);
}

void Gui::GUIUpdater::updateTimeUnitModification(const std::vector<std::string> &data)
{
    size_t timeUnit = 0;
    size_t tmp = 0;

    try {
        int temp = std::stoi(data[0], &tmp);
        if (temp < 0 || tmp != data[0].size())
            throw Gui::Errors::GuiUpdaterException("Invalid time unit modification");
        timeUnit = temp;
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException("Invalid time unit modification");
    }
    (void)timeUnit;
    return; // TODO: Implement the time unit modification
}

void Gui::GUIUpdater::updateEndOfGame(const std::vector<std::string> &data)
{
    _gameData->setIsEndGame(true);
    std::cout << "Team \"" + data[0] + "\" win this game !" << std::endl;
}

void Gui::GUIUpdater::updateMessageFromServer(const std::vector<std::string> &data)
{
    (void)data;
    return; // TODO: Implement the message from server
}

void Gui::GUIUpdater::updateUnknownMessage(const std::vector<std::string> &data)
{
    (void)data;
    return; // TODO: Implement the unknown message
}

void Gui::GUIUpdater::updateCommandParameter(const std::vector<std::string> &data)
{
    (void)data;
    return; // TODO: Implement the command parameter
}
