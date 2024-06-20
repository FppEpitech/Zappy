/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TestTeam
*/

#include "Config.hpp"
#include "GameDatas/Team.hpp"
#include "CriterionHeaders.hpp"

Model LoadModel(const char *modelPath)
{
    Model model;
    (void) modelPath;
    return model;
}

Test(Team, name, .timeout = 5)
{
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    cr_assert_eq(team.getName(), "TEAM1");

    team.setName("TEAM2");
    cr_assert_eq(team.getName(), "TEAM2");
}

Test(Team, players, .timeout = 5)
{
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2), 1);
    team.getPlayers().push_back(player);

    cr_assert_eq(team.getPlayers().size(), 1);
    cr_assert_eq(team.getPlayers()[0].getId(), 3);
    cr_assert_eq(team.getPlayers()[0].getTeam(), "TEAM1");
    cr_assert_eq(team.getPlayers()[0].getPosition().first, 1);
    cr_assert_eq(team.getPlayers()[0].getPosition().second, 2);
}

Test(Team, addPlayer, .timeout = 5)
{
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2), 1);
    team.addPlayer(player);

    cr_assert_eq(team.getPlayers().size(), 1);
    cr_assert_eq(team.getPlayers()[0].getId(), 3);
    cr_assert_eq(team.getPlayers()[0].getTeam(), "TEAM1");
    cr_assert_eq(team.getPlayers()[0].getPosition().first, 1);
    cr_assert_eq(team.getPlayers()[0].getPosition().second, 2);
}

Test(Team, removePlayer, .timeout = 5)
{
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2), 1);
    team.addPlayer(player);

    cr_assert_eq(team.getPlayers().size(), 1);

    team.removePlayer(3);
    cr_assert_eq(team.getPlayers().size(), 0);
}

Test(Team, getPlayer, .timeout = 5)
{
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2), 1);
    team.addPlayer(player);

    cr_assert_eq(team.getPlayers().size(), 1);

    auto player2 = team.getPlayer(3);
    cr_assert_eq(player2->getId(), 3);
    cr_assert_eq(player2->getTeam(), "TEAM1");
    cr_assert_eq(player2->getPosition().first, 1);
    cr_assert_eq(player2->getPosition().second, 2);
}

Test(Team, getPlayerModel, .timeout = 5)
{
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    Model model = team.getPlayerModel();
    cr_assert_not_null(&model);
}

Test(Team, setPlayerModelPath, .timeout = 5)
{
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    team.setPlayerModelPath("assets/player.obj");
    cr_assert_not_null(&team);
}

Test(Team, getPlayerFailing, .timeout = 5)
{
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2), 1);
    team.addPlayer(player);

    cr_assert_eq(team.getPlayers().size(), 1);

    auto player2 = team.getPlayer(4);
    cr_assert_eq(player2, nullptr);
}

Test(Team, removePlayerFailing, .timeout = 5)
{
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2), 1);
    team.addPlayer(player);

    cr_assert_eq(team.getPlayers().size(), 1);

    team.removePlayer(4);
    cr_assert_eq(team.getPlayers().size(), 1);
}

Test(Team, eggs, .timeout = 5)
{
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    Gui::Egg egg(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2));
    team.getEggs().push_back(egg);

    cr_assert_eq(team.getEggs().size(), 1);
    cr_assert_eq(team.getEggs()[0].getId(), 3);
    cr_assert_eq(team.getEggs()[0].getTeam(), "TEAM1");
    cr_assert_eq(team.getEggs()[0].getPosition().first, 1);
    cr_assert_eq(team.getEggs()[0].getPosition().second, 2);
}

Test(Team, getEgg, .timeout = 5)
{
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    Gui::Egg egg(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2));
    team.addEgg(egg);

    cr_assert_eq(team.getEggs().size(), 1);

    std::shared_ptr<Gui::Egg> egg2 = team.getEgg(3);
    cr_assert_eq(egg2->getId(), 3);
    cr_assert_eq(egg2->getTeam(), "TEAM1");
    cr_assert_eq(egg2->getPosition().first, 1);
    cr_assert_eq(egg2->getPosition().second, 2);
}

Test(Team, getEggFailling, .timeout = 5)
{
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    Gui::Egg egg(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2));
    team.addEgg(egg);

    cr_assert_eq(team.getEggs().size(), 1);

    std::shared_ptr<Gui::Egg> egg2 = team.getEgg(4);
    cr_assert_eq(egg2, nullptr);
}

Test(Team, addEgg, .timeout = 5)
{
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    Gui::Egg egg(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2));
    team.addEgg(egg);

    cr_assert_eq(team.getEggs().size(), 1);
    cr_assert_eq(team.getEggs()[0].getId(), 3);
    cr_assert_eq(team.getEggs()[0].getTeam(), "TEAM1");
    cr_assert_eq(team.getEggs()[0].getPosition().first, 1);
    cr_assert_eq(team.getEggs()[0].getPosition().second, 2);
}

Test(Team, removeEgg, .timeout = 5)
{
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    Gui::Egg egg(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2));
    team.addEgg(egg);

    cr_assert_eq(team.getEggs().size(), 1);

    team.removeEgg(3);
    cr_assert_eq(team.getEggs().size(), 0);
}

Test(Team, getEggModel, .timeout = 5)
{
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    Model model = team.getEggModel();
    cr_assert_not_null(&model);
}

Test(Team, setEggModelPath, .timeout = 5)
{
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    team.setEggModelPath("assets/egg.obj");
    cr_assert_not_null(&team);
}

Test(Team, removeEggFailling, .timeout = 5)
{
    Gui::Team team("TEAM1", "not_tested", "not_tested", (Color){0, 0, 0, 0});

    Gui::Egg egg(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2));
    team.addEgg(egg);

    cr_assert_eq(team.getEggs().size(), 1);

    team.removeEgg(4);
    cr_assert_eq(team.getEggs().size(), 1);
}
