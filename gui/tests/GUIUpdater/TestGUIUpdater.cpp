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
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, update, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    guiUpdater.update("test", {"test"});
    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, updateMapSize, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    guiUpdater.update("msz", {"10", "10"});
    cr_assert_eq(gameData->getMapSize().first, 10);
    cr_assert_eq(gameData->getMapSize().second, 10);
}

Test(GUIUpdater, updateMapContent, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    // guiUpdater.update("bct", {"1", "1", "1", "1", "1", "1", "1", "1", "1"});
    // cr_assert_eq(gameData->getMap()[1][1].inventory.getFood(), 1);
    // cr_assert_eq(gameData->getMap()[1][1].inventory.getLinemate(), 1);
    // cr_assert_eq(gameData->getMap()[1][1].inventory.getDeraumere(), 1);
    // cr_assert_eq(gameData->getMap()[1][1].inventory.getSibur(), 1);
    // cr_assert_eq(gameData->getMap()[1][1].inventory.getMendiane(), 1);
    // cr_assert_eq(gameData->getMap()[1][1].inventory.getPhiras(), 1);
    // cr_assert_eq(gameData->getMap()[1][1].inventory.getThystame(), 1);
}

Test(GUIUpdater, updateTeamNames, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    guiUpdater.update("tna", {"TEAM1"});
    cr_assert_eq(gameData->getTeams()[0].getName(), "TEAM1");
}

Test(GUIUpdater, updateTeamMember, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    gameData->addTeam("TEAM1");

    guiUpdater.update("pnw", {"TEAM1", "1", "1", "1", "1", "1"});
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getTeam(), "TEAM1");
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getId(), 1);
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getLevel(), 1);
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getPosition().first, 1);
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getPosition().second, 1);
}

Test(GUIUpdater, updatePlayerPosition, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    gameData->addTeam("TEAM1");
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("ppo", {"1", "1", "1", "1"});
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getPosition().first, 1);
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getPosition().second, 1);
}

Test(GUIUpdater, updatePlayerLevel, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    gameData->addTeam("TEAM1");
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("plv", {"1", "2"});
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getLevel(), 2);
}

Test(GUIUpdater, updatePlayerInventory, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    gameData->addTeam("TEAM1");
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

Test(GUIUpdater, updatePlayerExpulsion, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    gameData->addTeam("TEAM1");
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("pex", {"1"});
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getPosition().first, 1);
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getPosition().second, 1);
}

Test(GUIUpdater, updatePlayerBroadcast, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    gameData->addTeam("TEAM1");
    gameData->addPlayerToTeam("TEAM1", Gui::Player(1, "TEAM1", std::make_pair(1, 1), 1, 1));

    guiUpdater.update("pbc", {"1", "test"});
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getPosition().first, 1);
    cr_assert_eq(gameData->getTeam("TEAM1").getPlayer(1).get()->getPosition().second, 1);
}

Test(GUIUpdater, updateMapSizeError, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("msz", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateMapSizeErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("msz", {"-5"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateMapContentError, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("bct", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTeamNamesError, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    guiUpdater.update("tna", {"test"});
    cr_assert_throw(guiUpdater.update("tna", {"test"}), Gui::Errors::GuiUpdaterException);
}

// Test(GUIUpdater, updateTeamMemberError, .timeout = 5)
// {
//     std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
//     Gui::GUIUpdater guiUpdater(gameData);

//     cr_assert_throw(guiUpdater.update("pnw", {"test"}), Gui::Errors::GuiUpdaterException);
// }

Test(GUIUpdater, updatePlayerPositionError, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("ppo", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerPositionErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("ppo", {"-5"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerPositionOrientationErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("ppo", {"1", "1", "0"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerLevelError, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("plv", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerLevelErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("plv", {"-5"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerLevelErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("plv", {"0"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerInventoryError, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("pin", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerInventoryErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("pin", {"-5"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerExpulsionError, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("pex", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerExpulsionErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("pex", {"-5"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerBroadcastError, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("pbc", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerBroadcastErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("pbc", {"-5"}), Gui::Errors::GuiUpdaterException);
}
