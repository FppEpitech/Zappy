/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GameData
*/

#include "Assets.hpp"
#include "CriterionHeaders.hpp"
#include "GameDatas/GameData.hpp"

Test(GameData, getTeams, .timeout = 5)
{
    Gui::GameData gameData;

    cr_assert_eq(gameData.getTeams().size(), 0);
}

Test(GameData, getTeam, .timeout = 5)
{
    Gui::GameData gameData;

    gameData.addTeam("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    cr_assert_eq(gameData.getTeam("TEAM1").getName(), "TEAM1");
}

Test(GameData, getTeamFailling, .timeout = 5)
{
    Gui::GameData gameData;

    cr_assert_throw(gameData.getTeam("TEAM1"), Gui::Errors::GuiGameDataException);
}

Test(GameData, addTeamByObject, .timeout = 5)
{
    Gui::GameData gameData;
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    gameData.addTeam(team);

    cr_assert_eq(gameData.getTeams().size(), 1);
    cr_assert_eq(gameData.getTeams()[0].getName(), "TEAM1");
}

Test(GameData, addTeamByObjectAlreadyExists, .timeout = 5)
{
    Gui::GameData gameData;
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    gameData.addTeam(team);

    cr_assert_throw(gameData.addTeam(team), Gui::Errors::GuiGameDataException);
}

Test(GameData, addTeamByNameAlreadyExists, .timeout = 5)
{
    Gui::GameData gameData;

    gameData.addTeam("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    cr_assert_throw(gameData.addTeam("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0}), Gui::Errors::GuiGameDataException);
}

Test(GameData, addPlayerToTeam, .timeout = 5)
{
    Gui::GameData gameData;

    gameData.addTeam("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});
    gameData.addPlayerToTeam("TEAM1", Gui::Player(3, "TEAM1", std::make_pair(1, 2), 1));

    cr_assert_eq(gameData.getTeam("TEAM1").getPlayers().size(), 1);
    cr_assert_eq(gameData.getTeam("TEAM1").getPlayers()[0].getId(), 3);
    cr_assert_eq(gameData.getTeam("TEAM1").getPlayers()[0].getTeam(), "TEAM1");
    cr_assert_eq(gameData.getTeam("TEAM1").getPlayers()[0].getPosition().first, 1);
    cr_assert_eq(gameData.getTeam("TEAM1").getPlayers()[0].getPosition().second, 2);
}

Test(GameData, addPlayerToTeamNotFound, .timeout = 5)
{
    Gui::GameData gameData;

    cr_assert_throw(gameData.addPlayerToTeam("TEAM1", Gui::Player(3, "TEAM1", std::make_pair(1, 2), 1)), Gui::Errors::GuiGameDataException);
}

Test(GameData, getPlayer, .timeout = 5)
{
    Gui::GameData gameData;

    gameData.addTeam("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});
    gameData.addPlayerToTeam("TEAM1", Gui::Player(3, "TEAM1", std::make_pair(1, 2), 1));

    cr_assert_eq(gameData.getPlayer(3).getId(), 3);
    cr_assert_eq(gameData.getPlayer(3).getTeam(), "TEAM1");
    cr_assert_eq(gameData.getPlayer(3).getPosition().first, 1);
    cr_assert_eq(gameData.getPlayer(3).getPosition().second, 2);
}

Test(GameData, getPlayerFailed, .timeout = 5)
{
    Gui::GameData gameData;

    cr_assert_throw(gameData.getPlayer(3), Gui::Errors::GuiGameDataException);
}

Test(GameData, SetMap, .timeout = 5)
{
    Gui::GameData gameData;
    Map<Gui::Tile> map;

    for (int i = 0; i < 10; i++) {
        std::vector<Gui::Tile> row;
        for (int j = 0; j < 10; j++) {
            row.push_back(Gui::Tile(std::make_pair(i, j)));
        }
        map.push_back(row);
    }

    gameData.setMap(map);

    cr_assert_eq(gameData.getMap().size(), 10);
    cr_assert_eq(gameData.getMap()[0].size(), 10);
}

Test(GameData, GetTile, .timeout = 5)
{
    Gui::GameData gameData;
    Map<Gui::Tile> map;

    for (int i = 0; i < 10; i++) {
        std::vector<Gui::Tile> row;
        for (int j = 0; j < 10; j++) {
            row.push_back(Gui::Tile(std::make_pair(i, j)));
        }
        map.push_back(row);
    }

    gameData.setMap(map);

    cr_assert_eq(gameData.getTile(0, 0).getPosition().first, 0);
    cr_assert_eq(gameData.getTile(0, 0).getPosition().second, 0);
    cr_assert_eq(gameData.getTile(9, 9).getPosition().first, 9);
    cr_assert_eq(gameData.getTile(9, 9).getPosition().second, 9);
}

Test(GameData, TileNotFound, .timeout = 5)
{
    Gui::GameData gameData;
    Map<Gui::Tile> map;

    for (int i = 0; i < 10; i++) {
        std::vector<Gui::Tile> row;
        for (int j = 0; j < 10; j++) {
            row.push_back(Gui::Tile(std::make_pair(i, j)));
        }
        map.push_back(row);
    }

    gameData.setMap(map);

    cr_assert_throw(gameData.getTile(10, 0), Gui::Errors::GuiGameDataException);
    cr_assert_throw(gameData.getTile(0, 10), Gui::Errors::GuiGameDataException);
}

Test(GameData, setLittleMapSize, .timeout = 5)
{
    Gui::GameData gameData;

    gameData.setMapSize(2, 2);
    gameData.setMapSize(1, 1);

    cr_assert_eq(gameData.getMap().size(), 1);
    cr_assert_eq(gameData.getMap()[0].size(), 1);
}

Test(GameData, getEmptyMapSize, .timeout = 5)
{
    Gui::GameData gameData;

    cr_assert_eq(gameData.getMapSize().first, 0);
    cr_assert_eq(gameData.getMapSize().second, 0);

    gameData.setMapSize(2, 0);

    cr_assert_eq(gameData.getMapSize().first, 2);
    cr_assert_eq(gameData.getMapSize().second, 0);
}

Test(GameData, endGame, .timeout = 5)
{
    Gui::GameData gameData;

    cr_assert(!gameData.getIsEndGame());

    gameData.setIsEndGame(true);
    cr_assert(gameData.getIsEndGame());
}

Test(GameData, restartLastTick, .timeout = 5)
{
    Gui::GameData gameData;

    gameData.restartLastTick();
    cr_assert_neq(gameData.getLastTick(), 0);
}


Test(GameData, getLastError, .timeout = 5)
{
    Gui::GameData gameData;

    gameData.setLastError("test");
    cr_assert_str_eq(gameData.getLastError().c_str(), "test");
}

Test(GameData, getTeamById, .timeout = 5)
{
    Gui::GameData gameData;

    gameData.addTeam("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});
    gameData.addPlayerToTeam("TEAM1", Gui::Player(0, "TEAM1", std::make_pair(1, 2), 1));

    cr_assert_eq(gameData.getTeamById(0).getName(), "TEAM1");
}

Test(GameData, getTeamByIdFailed, .timeout = 5)
{
    Gui::GameData gameData;

    cr_assert_throw(gameData.getTeamById(0), Gui::Errors::GuiGameDataException);
}
