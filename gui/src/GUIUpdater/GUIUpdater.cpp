/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GUIUpdater
*/

#include "Assets.hpp"
#include "Colors.hpp"
#include "Error/Error.hpp"
#include "GUIUpdater/GUIUpdater.hpp"

Gui::GUIUpdater::GUIUpdater(std::shared_ptr<GameData> gameData, std::shared_ptr<INetwork> network) : AGUIUpdater(gameData, network), _colorIndex(0) {}

void Gui::GUIUpdater::update(const std::string &command, const std::vector<std::string> &data)
{
    try {
        for (auto &iterator : _updateMap) {
            if (iterator.first == command) {
                std::cerr << STR_GREEN << "[GUIUpdater] " << STR_BLUE << command << STR_GREEN << " command received with data: " << STR_BLUE;
                for (auto &d : data)
                    std::cerr << d << " ";
                std::cerr << STR_RESET << std::endl;
                iterator.second(data);
            }
        }
    } catch (const std::exception &error) {
        std::cerr << STR_RED << "[GUIUpdater] command " << command << " failed: " << error.what() << " with data: " << STR_YELLOW;
        for (auto &d : data)
            std::cerr << d << " ";
        std::cerr << STR_RESET << std::endl;
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
                throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "msz:" + STR_RED + "Invalid map size");
            args.push_back(temp);
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
    if (args.size() != 2)
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "msz:" + STR_RED + "Invalid argument number");
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
                throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "bct:" + STR_RED + "Invalid map content");
            args.push_back(temp);
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
    if (args.size() != 9)
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "bct:" + STR_RED + "Invalid argument number");
    try {
        _gameData.get()->setTile(Gui::Tile(std::make_pair(args[0], args[1]), Gui::Inventory(args[2], args[3], args[4], args[5], args[6], args[7], args[8])));
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "bct:" + STR_RED + "Invalid tile");
    }
    _gameData.get()->setNbBCTCommandReceived(_gameData.get()->getNbBCTCommandReceived() + 1);
}

void Gui::GUIUpdater::updateTeamNames(const std::vector<std::string> &data)
{
    try {
        for (size_t i = 0; i < data.size(); i++) {
            _gameData->addTeam(data[i], MODEL_PLAYER, MODEL_EGG, playerColors[_colorIndex]);
            increaseColorIndex();
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "tna: " + STR_RED + error.what());
    }
    if (_gameData->getTeams().empty())
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "tna:" + STR_RED + "No team found");
}

void Gui::GUIUpdater::updateTeamMember(const std::vector<std::string> &data)
{
    std::vector<size_t> args;
    size_t tmp = 0;

    try {
        for (size_t i = 0; i < data.size(); i++) {
            if (i == 5)
                continue;
            int temp = std::stoi(data[i], &tmp);
            if (temp < 0 || tmp != data[i].size())
                throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "pnw:" + STR_RED + "Invalid team member parameters");
            args.push_back(temp);
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
    if (args.size() != 5)
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "pnw:" + STR_RED + "Invalid argument number");
    if (args[3] < 1 || args[3] > 4)
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "pnw:" + STR_RED + "Invalid player orientation");
    if (args[4] < 1 || args[4] > 8)
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "pnw:" + STR_RED + "Invalid player level");
    for (auto &team : _gameData->getTeams()) {
        if (team.getName() == data[5]) {
            Player player(args[0], data[5], std::make_pair(args[1], args[2]), args[3], args[4]);
            player.setState(Gui::Player::BORN);
            team.addPlayer(player);
            for (auto &egg : team.getEggs()) {
                if (egg.getPosition() == std::make_pair(args[1], args[2]))
                    team.removeEgg(egg.getId());
            }
            for (auto &egg : _gameData.get()->getServerEggs()) {
                if (egg.getPosition() == std::make_pair(args[1], args[2]))
                    _gameData.get()->removeServerEgg(egg.getId());
            }
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
                throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "ppo:" + STR_RED + "Invalid player position parameters");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
    if (args.size() != 4)
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "ppo:" + STR_RED + "Invalid argument number");
    if (args[3] < 1 || args[3] > 4)
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "ppo:" + STR_RED + "Invalid player orientation");
    for (auto &team : _gameData.get()->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == args[0]) {
                if (player.getPosition() != std::make_pair(args[1], args[2])) {
                    if (player.getState() == Gui::Player::IDLE)
                        player.setState(Gui::Player::WALK);
                    else if (player.getState() == Gui::Player::BEING_EJECTED)
                        player.setState(Gui::Player::EJECTED);
                    else
                        player.setState(Gui::Player::IDLE);
                } else if (player.getState() != Gui::Player::INCANTATION)
                    player.setState(Gui::Player::IDLE);
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
                throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "plv:" + STR_RED + "Invalid player level parameters");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
    if (args.size() != 2)
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "plv:" + STR_RED + "Invalid argument number");
    if (args[1] < 1 || args[1] > 8)
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "plv:" + STR_RED + "Invalid player level");
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == args[0]) {
                player.setLevel(args[1]);
                return;
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
                throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "pin:" + STR_RED + "Invalid player inventory parameters");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
    if (args.size() != 10)
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "pin:" + STR_RED + "Invalid argument number");
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == args[0]) {
                player.inventory = Gui::Inventory(args[3], args[4], args[5], args[6], args[7], args[8], args[9]);
                player.setPosition(std::make_pair(args[1], args[2]));
                return;
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
            throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "pex:" + STR_RED + "Invalid player expulsion parameters");
        id = temp;
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
    try {
        _gameData->getPlayer(id).setState(Gui::Player::EJECT);
        std::pair<std::size_t, std::size_t> posPlayer = _gameData->getPlayer(id).getPosition();
        for (auto &team : _gameData->getTeams()) {
            for (auto &player : team.getPlayers()) {
                if (player.getPosition() == posPlayer && player.getId() != id)
                    player.setState(Gui::Player::BEING_EJECTED);
            }
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
}

void Gui::GUIUpdater::updatePlayerBroadcast(const std::vector<std::string> &data)
{
    size_t id = 0;
    size_t tmp = 0;

    try {
        int temp = std::stoi(data[0], &tmp);
        if (temp < 0 || tmp != data[0].size())
            throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "pbc:" + STR_RED + "Invalid player broadcast parameters");
        id = temp;
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == id) {
                player.setState(Gui::Player::PlayerState::BROADCAST);
                player.setBroadcast(data[1]);
                return;
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
                throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "pic:" + STR_RED + "Invalid player start incantation parameters");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
    if (args.size() < 4)
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "pic:" + STR_RED + "Invalid argument number");
    std::size_t index = 3;
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (index >= args.size())
                return;
            if (player.getId() == args[index]) {
                player.setState(Gui::Player::PlayerState::INCANTATION);
                index++;
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
                throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "pie:" + STR_RED + "Invalid player end incantation parameters");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
    if (args.size() != 3)
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "pie:" + STR_RED + "Invalid argument number");
    std::pair<std::size_t, std::size_t> tilePos(args[0], args[1]);
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getPosition() == tilePos) {
                player.setState(Gui::Player::PlayerState::IDLE);
                for (size_t i = 0; i < team.getPlayers().size(); i++) {
                    if (team.getPlayers()[i].getPosition().first == player.getPosition().first && team.getPlayers()[i].getPosition().second == player.getPosition().second)
                        _network.get()->sendMessageServer("plv " + std::to_string(player.getId()) + "\n");
                }
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
            throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "pfk:" + STR_RED + "Invalid egg laying parameters");
        id = temp;
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == id) {
                player.setState(Gui::Player::PlayerState::LAY_EGG);
                return;
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
                throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "pdr:" + STR_RED + "Invalid ressource dropping parameters");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
    if (args.size() != 2)
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "pdr:" + STR_RED + "Invalid argument number");
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == args[0]) {
                player.setState(Gui::Player::PlayerState::DROP);
                player.inventory.removeResource(args[1], 1);
                _gameData.get()->getTile(player.getPosition().first, player.getPosition().second).inventory.addResource(args[1], 1);
                return;
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
                throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "pgt:" + STR_RED + "Invalid ressource collecting parameters");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
    if (args.size() != 2)
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "pgt:" + STR_RED + "Invalid argument number");
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == args[0]) {
                player.setState(Gui::Player::PlayerState::COLLECT);
                player.inventory.addResource(args[1], 1);
                _gameData.get()->getTile(player.getPosition().first, player.getPosition().second).inventory.removeResource(args[1], 1);
                return;
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
            throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "pdi:" + STR_RED + "Invalid player death parameters");
        id = temp;
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == id) {
                player.setState(Gui::Player::PlayerState::DEAD);
                return;
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
                throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "enw:" + STR_RED + "Invalid egg laid by player parameters");
        }
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
    if (args.size() != 4)
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "enw:" + STR_RED + "Invalid argument number");
    if (serverId != 0)
        _gameData.get()->addServerEgg(Gui::Egg(args[0], "", std::make_pair(args[2], args[3])));
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (player.getId() == args[1]) {
                team.addEgg(Gui::Egg(args[0], team.getName(), std::make_pair(args[2], args[3])));
                return;
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
            throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "ebo:" + STR_RED + "Invalid player born parameters");
        id = temp;
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
    for (auto &team : _gameData->getTeams()) {
        for (size_t i = 0; i < team.getPlayers().size(); i++) {
            if (team.getPlayers()[i].getId() == id) {
                team.getPlayer(id).get()->setState(Gui::Player::PlayerState::BORN);
                return;
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
            throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "edi:" + STR_RED + "Invalid egg death parameters");
        id = temp;
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
    for (auto &team : _gameData->getTeams()) {
        for (auto &egg : team.getEggs()) {
            if (egg.getId() == id) {
                egg.setState(Gui::Egg::EggState::DEAD);
                team.removeEgg(id);
                return;
            }
        }
    }
    for (auto &egg : _gameData.get()->getServerEggs()) {
        if (egg.getId() == id) {
            egg.setState(Gui::Egg::EggState::DEAD);
            _gameData.get()->removeServerEgg(id);
            return;
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
            throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "sgt:" + STR_RED + "Invalid time unit request parameters");
        timeUnit = temp;
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
    if (timeUnit == 0)
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "sgt:" + STR_RED + "Invalid time unit value");
    if (_gameData.get()->getServerTick() != timeUnit) {
        _gameData->setServerTick(timeUnit);
        _gameData.get()->setTimeUnitFromServer(GameData::TimeUnitState::NONE);
    }
}

void Gui::GUIUpdater::updateTimeUnitModification(const std::vector<std::string> &data)
{
    size_t timeUnit = 0;
    size_t tmp = 0;

    try {
        int temp = std::stoi(data[0], &tmp);
        if (temp < 0 || tmp != data[0].size())
            throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "sst:" + STR_RED + "Invalid time unit modification parameters");
        timeUnit = temp;
    } catch (const std::exception &error) {
        throw Gui::Errors::GuiUpdaterException(error.what());
    }
    if (timeUnit == 0)
        throw Gui::Errors::GuiUpdaterException(std::string(STR_YELLOW) + "sst:" + STR_RED + "Invalid time unit value");
    if (_gameData.get()->getServerTick() != timeUnit) {
        _gameData->setServerTick(timeUnit);
        _gameData.get()->setTimeUnitFromServer(GameData::TimeUnitState::NONE);
    }
}

void Gui::GUIUpdater::updateEndOfGame(const std::vector<std::string> &data)
{
    _gameData->setIsEndGame(true);
    std::cout << "Team \"" + data[0] + "\" win this game !" << std::endl;
}

void Gui::GUIUpdater::updateMessageFromServer(const std::vector<std::string> &data)
{
    _gameData.get()->setLastError(data[0]);
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

void Gui::GUIUpdater::increaseColorIndex()
{
    _colorIndex++;
    if (_colorIndex >= playerColors.size())
        _colorIndex = 0;
}
