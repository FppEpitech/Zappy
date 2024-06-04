/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TestRender
*/

#include "Render/Render.hpp"
#include "CriterionHeaders.hpp"

Test(Render, constructor, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::Render render(gameData);

    cr_assert_not_null(&render);
}
