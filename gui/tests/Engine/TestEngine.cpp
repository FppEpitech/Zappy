/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TestEngine
*/

#include "Engine/Engine.hpp"
#include "CriterionHeaders.hpp"

Test(Engine, constructor, .timeout = 5)
{
    Gui::Network net(4242, "test");
    Gui::Engine engine(net);

    cr_assert_not_null(&engine);
}
