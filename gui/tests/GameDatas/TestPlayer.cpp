/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** test player
*/

#include "GameDatas/Player.hpp"
#include "CriterionHeaders.hpp"
#include "Error/Error.hpp"

Test(Player, position, .timeout = 5)
{
    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2), 1);

    cr_assert_eq(player.getPosition().first, 1);
    cr_assert_eq(player.getPosition().second, 2);

    player.setPosition(std::pair<std::size_t, std::size_t>(3, 4));
    cr_assert_eq(player.getPosition().first, 3);
    cr_assert_eq(player.getPosition().second, 4);
}

Test(Player, id, .timeout = 5)
{
    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2), 1);

    cr_assert_eq(player.getId(), 3);

    player.setId(78);
    cr_assert_eq(player.getId(), 78);
}

Test(Player, level, .timeout = 5)
{
    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2), 1);

    cr_assert_eq(player.getLevel(), 1);

    player.setLevel(8);
    cr_assert_eq(player.getLevel(), 8);
}

Test(Player, team, .timeout = 5)
{
    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2), 1);

    cr_assert_eq(player.getTeam(), "TEAM1");

    player.setTeam("TEAM2");
    cr_assert_eq(player.getTeam(), "TEAM2");
}

Test(Player, inventory, .timeout = 5)
{
    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2), 1);

    player.inventory.setFood(34);
    cr_assert_eq(player.inventory.getFood(), 34);
}

Test(Player, orientation, .timeout = 5)
{
    Gui::Player player(3, "TEAM1", std::pair<std::size_t, std::size_t>(1, 2), 1);

    cr_assert_eq(player.getOrientation(), 1);

    player.setOrientation(3);
    cr_assert_eq(player.getOrientation(), 3);
}
