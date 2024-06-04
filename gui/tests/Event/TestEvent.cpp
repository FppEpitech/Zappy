/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TestEvent
*/

#include "Event/Event.hpp"
#include "CriterionHeaders.hpp"

Test(Event, constructor, .timeout = 5)
{
    Gui::Event event;

    cr_assert_not_null(&event);
}

Test(Event, setRender, .timeout = 5)
{
    Gui::Event event;
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    std::shared_ptr<Gui::Render> render = std::make_shared<Gui::Render>(gameData);

    event.setRender(render);
    cr_assert_not_null(&event);
}
