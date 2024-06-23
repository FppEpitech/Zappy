/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TestTeam
*/

#include "Config.hpp"
#include "Assets.hpp"
#include "GameDatas/Team.hpp"
#include "CriterionHeaders.hpp"

Test(Team, name, .timeout = 5)
{
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){0, 0, 0, 0});

    cr_assert_eq(team.getName(), "TEAM1");

    team.setName("TEAM2");
    cr_assert_eq(team.getName(), "TEAM2");
}

Test(Team, players, .timeout = 5)
{
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){0, 0, 0, 0});

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
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){0, 0, 0, 0});

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
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){0, 0, 0, 0});

    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2), 1);
    team.addPlayer(player);

    cr_assert_eq(team.getPlayers().size(), 1);

    team.removePlayer(3);
    cr_assert_eq(team.getPlayers().size(), 0);
}

Test(Team, getPlayer, .timeout = 5)
{
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){0, 0, 0, 0});

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
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){0, 0, 0, 0});

    model = team.getPlayerModel();
    cr_assert_not_null(&model);
}

Test(Team, setPlayerModelPath, .timeout = 5)
{
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){0, 0, 0, 0});

    team.setPlayerModelPath("assets/player.obj");
    cr_assert_not_null(&team);
}

Test(Team, getPlayerFailing, .timeout = 5)
{
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){0, 0, 0, 0});

    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2), 1);
    team.addPlayer(player);

    cr_assert_eq(team.getPlayers().size(), 1);

    auto player2 = team.getPlayer(4);
    cr_assert_eq(player2, nullptr);
}

Test(Team, removePlayerFailing, .timeout = 5)
{
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){0, 0, 0, 0});

    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2), 1);
    team.addPlayer(player);

    cr_assert_eq(team.getPlayers().size(), 1);

    team.removePlayer(4);
    cr_assert_eq(team.getPlayers().size(), 1);
}

Test(Team, eggs, .timeout = 5)
{
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){0, 0, 0, 0});

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
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){0, 0, 0, 0});

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
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){0, 0, 0, 0});

    Gui::Egg egg(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2));
    team.addEgg(egg);

    cr_assert_eq(team.getEggs().size(), 1);

    std::shared_ptr<Gui::Egg> egg2 = team.getEgg(4);
    cr_assert_eq(egg2, nullptr);
}

Test(Team, addEgg, .timeout = 5)
{
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){0, 0, 0, 0});

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
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){0, 0, 0, 0});

    Gui::Egg egg(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2));
    team.addEgg(egg);

    cr_assert_eq(team.getEggs().size(), 1);

    team.removeEgg(3);
    cr_assert_eq(team.getEggs().size(), 0);
}

Test(Team, getEggModel, .timeout = 5)
{
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){0, 0, 0, 0});

    model = team.getEggModel();
    cr_assert_not_null(&model);
}

Test(Team, setEggModelPath, .timeout = 5)
{
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){0, 0, 0, 0});

    team.setEggModelPath("assets/egg.obj");
    cr_assert_not_null(&team);
}

Test(Team, removeEggFailling, .timeout = 5)
{
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){0, 0, 0, 0});

    Gui::Egg egg(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2));
    team.addEgg(egg);

    cr_assert_eq(team.getEggs().size(), 1);

    team.removeEgg(4);
    cr_assert_eq(team.getEggs().size(), 1);
}

Test(Team, getPlayerModelAnimation, .timeout = 5)
{
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){0, 0, 0, 0});

    ModelAnimation *model2 = team.getPlayerModelAnimation();
    cr_assert_null(model2);
}

Test(Team, getPlayerPositionIn3DSpace, .timeout = 5)
{
    Map<Gui::Tile> map;
    for (std::size_t i = 0; i < 10; i++) {
        std::vector<Gui::Tile> row;
        for (std::size_t j = 0; j < 10; j++) {
            row.push_back(Gui::Tile(std::pair<std::size_t, std::size_t>(i, j)));
        }
        map.push_back(row);
    }
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){0, 0, 0, 0});
    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(0, 0), 1);
    team.addPlayer(player);

    Vector3 pos = team.getPlayerPositionIn3DSpace(3, map);
    Vector3 tmp = POS_PLAYER;
    cr_assert_eq(pos.x, tmp.x);
    cr_assert_eq(pos.y, tmp.y);
    cr_assert_eq(pos.z, tmp.z);
}

Test(Team, getPlayerColor, .timeout = 5)
{
    Model model;
    ModelAnimation *modelAnimation = nullptr;
    Gui::Team team("TEAM1", model, model, modelAnimation, (Color){255, 255, 255, 255});

    Color color = team.getPlayerColor();
    cr_assert_eq(color.r, 255);
    cr_assert_eq(color.g, 255);
    cr_assert_eq(color.b, 255);
    cr_assert_eq(color.a, 255);
}
