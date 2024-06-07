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

Test(GUIUpdater, updateMapSizeInvalidNumberOfArguments, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);
    cr_assert_throw(guiUpdater.update("msz", {}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateMapContent, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

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
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("bct", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateMapContentErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData.get()->setMapSize(10, 10);
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("bct", {"-5"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateMapContentInvalidNumberOfArguments, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData.get()->setMapSize(10, 10);
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("bct", {}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateMapContentErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData.get()->setMapSize(2, 2);
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("bct", {"5", "5", "2", "3", "4", "5", "6", "7", "8"}),Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTeamNamesInvalidNumberOfArguments, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);
    cr_assert_throw(guiUpdater.update("tna", {}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTeamMemberError, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("pnw", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTeamMemberInvalidNumberOfArguments, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);
    cr_assert_throw(guiUpdater.update("pnw", {}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTeamMemberErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData.get()->setMapSize(10, 10);
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("pnw", {"1", "1", "1", "0", "1", "1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTeamMemberErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData.get()->setMapSize(10, 10);
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("pnw", {"1", "1", "1", "2", "0", "1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerPositionErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("ppo", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerPositionErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("ppo", {"-5"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerPositionInvalidNumberOfArguments, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData.get()->setMapSize(10, 10);
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("ppo", {}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerPositionOrientationErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("ppo", {"1", "1", "0", "50"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerLevelErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("plv", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerLevelErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("plv", {"-5"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerLevelErrorValue3, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("plv", {"0", "50"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerLevelInvalidNumberOfArguments, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData.get()->setMapSize(10, 10);
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("plv", {}), Gui::Errors::GuiUpdaterException);
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

Test(GUIUpdater, updatePlayerStartIncantation, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    gameData.get()->setMapSize(10, 10);
    Gui::GUIUpdater guiUpdater(gameData);

    guiUpdater.update("pic", {"1", "1", "1", "1"});
    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, updateEggLaidByPlayerErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("enw", {"test", "test", "test", "test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateEggLaidByPlayerErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("enw", {"-1", "-1", "-1", "-1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerBornErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("ebo", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updatePlayerBornErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("ebo", {"-1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateEggDeathErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("edi", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateEggDeathErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("edi", {"-1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTimeUnitRequest, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    guiUpdater.update("sgt", {"5"});

    cr_assert_eq(gameData->getServerTick(), 5);
}

Test(GUIUpdater, updateTimeUnitRequestErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("sgt", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTimeUnitRequestErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("sgt", {"-1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTimeUnitModificationErrorValue, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("sst", {"test"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateTimeUnitModificationErrorValue2, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_throw(guiUpdater.update("sst", {"-1"}), Gui::Errors::GuiUpdaterException);
}

Test(GUIUpdater, updateUnknownMessage, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    guiUpdater.update("suc", {"test"});
    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, updateCommandParameter, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    guiUpdater.update("sbp", {"test"});
    cr_assert_not_null(&guiUpdater);
}
