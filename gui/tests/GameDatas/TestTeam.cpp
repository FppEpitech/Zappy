/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TestTeam
*/

#include "GameDatas/Team.hpp"
#include "CriterionHeaders.hpp"

Test(Team, name, .timeout = 5)
{
    Gui::Team team("TEAM1");

    cr_assert_eq(team.getName(), "TEAM1");

    team.setName("TEAM2");
    cr_assert_eq(team.getName(), "TEAM2");
}

Test(Team, players, .timeout = 5)
{
    Gui::Team team("TEAM1");

    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2));
    team.getPlayers().push_back(player);

    cr_assert_eq(team.getPlayers().size(), 1);
    cr_assert_eq(team.getPlayers()[0].getId(), 3);
    cr_assert_eq(team.getPlayers()[0].getTeam(), "TEAM1");
    cr_assert_eq(team.getPlayers()[0].getPosition().first, 1);
    cr_assert_eq(team.getPlayers()[0].getPosition().second, 2);
}

Test(Team, addPlayer, .timeout = 5)
{
    Gui::Team team("TEAM1");

    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2));
    team.addPlayer(player);

    cr_assert_eq(team.getPlayers().size(), 1);
    cr_assert_eq(team.getPlayers()[0].getId(), 3);
    cr_assert_eq(team.getPlayers()[0].getTeam(), "TEAM1");
    cr_assert_eq(team.getPlayers()[0].getPosition().first, 1);
    cr_assert_eq(team.getPlayers()[0].getPosition().second, 2);
}

Test(Team, removePlayer, .timeout = 5)
{
    Gui::Team team("TEAM1");

    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2));
    team.addPlayer(player);

    cr_assert_eq(team.getPlayers().size(), 1);

    team.removePlayer(3);
    cr_assert_eq(team.getPlayers().size(), 0);
}

Test(Team, getPlayer, .timeout = 5)
{
    Gui::Team team("TEAM1");

    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2));
    team.addPlayer(player);

    cr_assert_eq(team.getPlayers().size(), 1);

    auto player2 = team.getPlayer(3);
    cr_assert_eq(player2->getId(), 3);
    cr_assert_eq(player2->getTeam(), "TEAM1");
    cr_assert_eq(player2->getPosition().first, 1);
    cr_assert_eq(player2->getPosition().second, 2);
}

Test(Team, getPlayerFailing, .timeout = 5)
{
    Gui::Team team("TEAM1");

    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2));
    team.addPlayer(player);

    cr_assert_eq(team.getPlayers().size(), 1);

    auto player2 = team.getPlayer(4);
    cr_assert_eq(player2, nullptr);
}

Test(Team, removePlayerFailing, .timeout = 5)
{
    Gui::Team team("TEAM1");

    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2));
    team.addPlayer(player);

    cr_assert_eq(team.getPlayers().size(), 1);

    team.removePlayer(4);
    cr_assert_eq(team.getPlayers().size(), 1);
}
