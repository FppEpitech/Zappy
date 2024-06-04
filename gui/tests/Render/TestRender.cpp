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

Test(Render, isOpen, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::Render render(gameData);

    cr_assert_eq(render.isOpen(), true);
}

Test(Render, draw, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::Render render(gameData);

    render.draw();
    cr_assert_not_null(&render);
}

Test(Render, getCamera, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::Render render(gameData);

    cr_assert_not_null(render.getCamera());
}

Test(Render, setIsDebug, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::Render render(gameData);

    render.setIsDebug(true);
    cr_assert_eq(render.getIsDebug(), true);
}

Test(Render, getIsDebug, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::Render render(gameData);

    render.setIsDebug(false);
    cr_assert_eq(render.getIsDebug(), false);
}

Test(Render, displayNoDebug, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::Render render(gameData);

    render.displayDebug();
    cr_assert_not_null(&render);
}

Test(Render, displayDebug, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::Render render(gameData);

    render.setIsDebug(true);
    render.displayDebug();
    cr_assert_not_null(&render);
}
