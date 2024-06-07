/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TestEgg
*/

#include "GameDatas/Egg.hpp"
#include "CriterionHeaders.hpp"

Test(Egg, constructor, .timeout = 5)
{
    Gui::Egg egg(1, "team", {0, 0});

    cr_assert_eq(egg.getId(), 1);
    cr_assert_str_eq(egg.getTeam().c_str(), "team");
    cr_assert_eq(egg.getPosition().first, 0);
    cr_assert_eq(egg.getPosition().second, 0);

}

Test(Egg, getId, .timeout = 5)
{
    Gui::Egg egg(1, "team", {0, 0});

    cr_assert_eq(egg.getId(), 1);
}

Test(Egg, getTeam, .timeout = 5)
{
    Gui::Egg egg(1, "team", {0, 0});

    cr_assert_str_eq(egg.getTeam().c_str(), "team");
}

Test(Egg, getPosition, .timeout = 5)
{
    Gui::Egg egg(1, "team", {0, 0});

    cr_assert_eq(egg.getPosition().first, 0);
    cr_assert_eq(egg.getPosition().second, 0);
}

Test(Egg, setPosition, .timeout = 5)
{
    Gui::Egg egg(1, "team", {0, 0});

    egg.setPosition({1, 1});
    cr_assert_eq(egg.getPosition().first, 1);
    cr_assert_eq(egg.getPosition().second, 1);
}

Test(Egg, setTeam, .timeout = 5)
{
    Gui::Egg egg(1, "team", {0, 0});

    egg.setTeam("newteam");
    cr_assert_str_eq(egg.getTeam().c_str(), "newteam");
}

Test(Egg, setId, .timeout = 5)
{
    Gui::Egg egg(1, "team", {0, 0});

    egg.setId(2);
    cr_assert_eq(egg.getId(), 2);
}
