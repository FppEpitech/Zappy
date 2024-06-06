/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** GameData
*/

#include "Assets.hpp"
#include "CriterionHeaders.hpp"
#include "GameDatas/GameData.hpp"

Test(GameData, Teams, .timeout = 5)
{
    InitWindow(1,1,"ok");
    Gui::GameData gameData;

    Gui::Team team1("TEAM1", MODEL_PLAYER);
    Gui::Team team2("TEAM2", MODEL_PLAYER);

    gameData.addTeam(team1);
    gameData.addTeam(team2);

    cr_assert_eq(gameData.getTeams().size(), 2);
    cr_assert_eq(gameData.getTeam("TEAM1").getName(), "TEAM1");
    cr_assert_eq(gameData.getTeam("TEAM2").getName(), "TEAM2");
    CloseWindow();
}

Test(GameData, AddTeam, .timeout = 5)
{
    InitWindow(1,1,"ok");
    Gui::GameData gameData;

    Gui::Team team1("TEAM1", MODEL_PLAYER);

    gameData.addTeam(team1);
    gameData.addTeam("TEAM2", MODEL_PLAYER);

    cr_assert_eq(gameData.getTeams().size(), 2);
    cr_assert_eq(gameData.getTeam("TEAM1").getName(), "TEAM1");
    cr_assert_eq(gameData.getTeam("TEAM2").getName(), "TEAM2");
    CloseWindow();
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

Test(GameData, NoTeamFound, .timeout = 5)
{
    InitWindow(1,1,"ok");
    Gui::GameData gameData;

    Gui::Team team1("TEAM1", MODEL_PLAYER);

    gameData.addTeam(team1);

    cr_assert_throw(gameData.getTeam("TEAM2"), Gui::Errors::GuiGameDataException);
    CloseWindow();
}

Test(GameData, TeamAlreadyExisting, .timeout = 5)
{
    InitWindow(1,1,"ok");
    Gui::GameData gameData;

    Gui::Team team1("TEAM1", MODEL_PLAYER);

    gameData.addTeam(team1);

    cr_assert_throw(gameData.addTeam(team1), Gui::Errors::GuiGameDataException);
    cr_assert_throw(gameData.addTeam("TEAM1", MODEL_PLAYER), Gui::Errors::GuiGameDataException);
    CloseWindow();
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
