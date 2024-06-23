/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TestGUIUpdater
*/

#include "CriterionHeaders.hpp"
#include "GUIUpdater/GUIUpdater.hpp"

Test(GUIUpdater, constructor, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, update, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    guiUpdater.update("test", {"test"});
    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, updateMapSize, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    guiUpdater.update("msz", {"10", "10"});
    cr_assert_eq(gameData->getMapSize().first, 10);
    cr_assert_eq(gameData->getMapSize().second, 10);
}

Test(GUIUpdater, updateMapSizeError, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("msz", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateMapSizeErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("msz", {"-5"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateMapSizeInvalidNumberOfArguments, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    cr_assert_throw(guiUpdater.update("msz", {}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateMapContent, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    gameData.get()->setMapSize(10, 10);
    guiUpdater.update("bct", {"1", "1", "2", "3", "4", "5", "6", "7", "8"});
    cr_assert_eq(gameData.get()->getMap()[1][1].inventory.getFood(), 2);
    cr_assert_eq(gameData.get()->getMap()[1][1].inventory.getLinemate(), 3);
    cr_assert_eq(gameData.get()->getMap()[1][1].inventory.getDeraumere(), 4);
    cr_assert_eq(gameData.get()->getMap()[1][1].inventory.getSibur(), 5);
    cr_assert_eq(gameData.get()->getMap()[1][1].inventory.getMendiane(), 6);
    cr_assert_eq(gameData.get()->getMap()[1][1].inventory.getPhiras(), 7);
    cr_assert_eq(gameData.get()->getMap()[1][1].inventory.getThystame(), 8);
}

Test(GUIUpdater, updateMapContentError, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("bct", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateMapContentErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData.get()->setMapSize(10, 10);
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("bct", {"-5"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateMapContentInvalidNumberOfArguments, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData.get()->setMapSize(10, 10);
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("bct", {}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateMapContentErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData.get()->setMapSize(2, 2);
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("bct", {"5", "5", "2", "3", "4", "5", "6", "7", "8"}),Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTeamNames, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    guiUpdater.update("tna", {"TEAM1"});
    cr_assert_eq(gameData->getTeams()[0].getName(), "TEAM1");
}

Test(GUIUpdater, updateTeamNamesError, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    guiUpdater.update("tna", {"test"});
    cr_assert_throw(guiUpdater.update("tna", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTeamNamesInvalidNumberOfArguments, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    cr_assert_throw(guiUpdater.update("tna", {}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTeamMember, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});

    gameData.get()->getTeam("TEAM1").addEgg(Gui::Egg(1, "TEAM1", std::pair<std::size_t, std::size_t>(1, 1)));
    guiUpdater.update("pnw", {"1", "1", "1", "1", "1", "TEAM1"});
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getTeam(), "TEAM1");
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getId(), 1);
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getLevel(), 1);
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getPosition().first, 1);
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getPosition().second, 1);
}

Test(GUIUpdater, updateTeamMemberErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("pnw", {"1", "-1", "1", "1", "1", "TEAM1"}), Gui::Errors::GuiUpdaterException);
    cr_assert_throw(guiUpdater.update("pnw", {"1", "1", "1", "50", "1", "TEAM1"}), Gui::Errors::GuiUpdaterException);
    cr_assert_throw(guiUpdater.update("pnw", {"1", "1", "1", "1", "50", "TEAM1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTeamMemberError, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("pnw", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTeamMemberInvalidNumberOfArguments, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    cr_assert_throw(guiUpdater.update("pnw", {"1", "1", "1", "1", "1", "TEAM", "1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTeamMemberErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData.get()->setMapSize(10, 10);
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("pnw", {"1", "1", "1", "0", "1", "1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTeamMemberErrorValue3, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData.get()->setMapSize(10, 10);
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("pnw", {"1", "1", "1", "2", "0", "1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerPosition, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});
    Gui::Player player(1, "TEAM1", std::pair<std::size_t, std::size_t>(1, 1), 1, 1);
    player.setState(Gui::Player::PlayerState::IDLE);
    gameData->addTeam(team);
    gameData->addPlayerToTeam("TEAM1", player);

    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("ppo", {"1", "1", "1", "1"});
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getPosition().first, 1);
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getPosition().second, 1);
}

Test(GUIUpdater, updatePlayerPositionErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("ppo", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerPositionErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("ppo", {"-5"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerPositionInvalidNumberOfArguments, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData.get()->setMapSize(10, 10);
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("ppo", {}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerPositionOrientationErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("ppo", {"1", "1", "0", "50"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerPositionOrientationInvalidNumberOfArguments, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("ppo", {"1", "1", "1"}), Gui::Errors::GuiUpdaterException);

}

Test(GUIUpdater, updatePlayerLevel, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("plv", {"1", "2"});
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getLevel(), 2);
}

Test(GUIUpdater, updatePlayerLevelErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("plv", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerLevelErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("plv", {"-5"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerLevelErrorValue3, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("plv", {"0", "50"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerLevelInvalidNumberOfArguments, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData.get()->setMapSize(10, 10);
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("plv", {}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerInventory, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("pin", {"1", "1", "1", "1", "1", "1", "1", "1", "1", "1"});
    cr_assert_eq(gameData.get()->getTeam("TEAM1").getPlayer(1).get()->inventory.getFood(), 1);
    cr_assert_eq(gameData.get()->getTeam("TEAM1").getPlayer(1).get()->inventory.getLinemate(), 1);
    cr_assert_eq(gameData.get()->getTeam("TEAM1").getPlayer(1).get()->inventory.getDeraumere(), 1);
    cr_assert_eq(gameData.get()->getTeam("TEAM1").getPlayer(1).get()->inventory.getSibur(), 1);
    cr_assert_eq(gameData.get()->getTeam("TEAM1").getPlayer(1).get()->inventory.getMendiane(), 1);
    cr_assert_eq(gameData.get()->getTeam("TEAM1").getPlayer(1).get()->inventory.getPhiras(), 1);
    cr_assert_eq(gameData.get()->getTeam("TEAM1").getPlayer(1).get()->inventory.getThystame(), 1);
}

Test(GUIUpdater, updatePlayerInventoryError, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("pin", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerInventoryErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("pin", {"-5"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerInventoryInvalidNumberOfArguments, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("pin", {"1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerExpulsion, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("pex", {"1"});
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getPosition().first, 1);
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getPosition().second, 1);
}

Test(GUIUpdater, updatePlayerExpulsionError, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("pex", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerExpulsionErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("pex", {"-5"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerBroadcast, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("pbc", {"1", "test"});
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getPosition().first, 1);
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getPosition().second, 1);
}

Test(GUIUpdater, updatePlayerBroadcastError, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("pbc", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerBroadcastErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("pbc", {"-5"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerStartIncantation, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("pic", {"1", "1", "1", "1"});
    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, updatePlayerStartIncantationErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    cr_assert_throw(guiUpdater.update("pic", {"test", "1", "1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerStartIncantationErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    cr_assert_throw(guiUpdater.update("pic", {"-1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerEndIncantationInvalidNumberOfArguments, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("pie", {}), Gui::Errors::GuiUpdaterException);

}

Test(GUIUpdater, updatePlayerEndIncantation, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("pie", {"1", "1", "1"});
    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, updatePlayerEndIncantationErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    cr_assert_throw(guiUpdater.update("pie", {"test", "1", "1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerEndIncantationErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    cr_assert_throw(guiUpdater.update("pie", {"-1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerStartIncantationInvalidNumberOfArguments, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("pic", {}), Gui::Errors::GuiUpdaterException);

}
Test(GUIUpdater, updatePlayerEggLaying, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("pfk", {"1"});
    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, updatePlayerEggLayingErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    cr_assert_throw(guiUpdater.update("pfk", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerEggLayingErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    cr_assert_throw(guiUpdater.update("pfk", {"-1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerRessourceDropping, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("msz", {"2", "2"});
    guiUpdater.update("pdr", {"1", "1"});
    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, updatePlayerRessourceDroppingErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("msz", {"2", "2"});
    cr_assert_throw(guiUpdater.update("pdr", {"1", "test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerRessourceDroppingErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("msz", {"2", "2"});
    cr_assert_throw(guiUpdater.update("pdr", {"-1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerRessourceDroppingInvalidNumberOfArguments, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    guiUpdater.update("msz", {"2", "2"});
    cr_assert_throw(guiUpdater.update("pdr", {}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateRessourceCollecting, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("msz", {"2", "2"});
    guiUpdater.update("pgt", {"1", "1"});
    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, updateRessourceCollectingErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("msz", {"2", "2"});
    cr_assert_throw(guiUpdater.update("pgt", {"1", "test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateRessourceCollectingErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("msz", {"2", "2"});
    cr_assert_throw(guiUpdater.update("pgt", {"-1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateRessourceCollectingInvalidNumberOfArguments, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    guiUpdater.update("msz", {"2", "2"});
    cr_assert_throw(guiUpdater.update("pgt", {}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerDeath, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("pdi", {"1"});
    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, updatePlayerDeathErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    cr_assert_throw(guiUpdater.update("pdi", {"test", "test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerDeathErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    cr_assert_throw(guiUpdater.update("pdi", {"-1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateEggLaidByPlayer, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("enw", {"1", "1", "1", "1"});
    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, updateEggLaidByPlayerServerId, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData.get()->setMapSize(10, 10);
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData.get()->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData.get()->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("enw", {"1", "-1", "1", "1"});
    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, updateEggLaidByPlayerErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("enw", {"test", "test", "test", "test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateEggLaidByPlayerErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("enw", {"-1", "-1", "-1", "-1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateEggLaidByPlayerInvalidNumberOfArguments, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("enw", {}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerBorn, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    gameData.get()->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("ebo", {"1"});
    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, updatePlayerBornErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("ebo", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerBornErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("ebo", {"-1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateEggDeath, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});
    Gui::Egg egg(1, "TEAM1", std::make_pair(1, 1));
    gameData.get()->getTeam("TEAM1").addEgg(egg);

    guiUpdater.update("edi", {"1"});
    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, updateEggDeathErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("edi", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateEggDeathErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("edi", {"-1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTimeUnitRequest, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    guiUpdater.update("sgt", {"5"});

    cr_assert_eq(gameData->getServerTick(), 5);
}

Test(GUIUpdater, updateTimeUnitRequestErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("sgt", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTimeUnitRequestErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("sgt", {"-1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTimeUnitModification, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);
    gameData->addTeam("TEAM1", (Color){0, 0, 0, 0});

    guiUpdater.update("sst", {"1"});
    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, updateTimeUnitModificationErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("sst", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTimeUnitModificationErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert_throw(guiUpdater.update("sst", {"-1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateEndOfGame, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    cr_assert(!gameData->getIsEndGame());

    guiUpdater.update("seg", {"TEAM"});

    cr_assert(gameData->getIsEndGame());
}

Test(GUIUpdater, updateMessageFromServer, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData.get()->setMapSize(10, 10);
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    guiUpdater.update("smg", {"test"});
    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, updateUnknownMessage, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    guiUpdater.update("suc", {"test"});
    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, updateCommandParameter, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::INetwork> network = std::make_shared<Gui::Network>(4242, "no_tested");
    Gui::GUIUpdater guiUpdater(gameData, network);

    guiUpdater.update("sbp", {"test"});
    cr_assert_not_null(&guiUpdater);
}
