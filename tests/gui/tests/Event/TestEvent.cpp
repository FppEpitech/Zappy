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

Test(Event, setGameData, .timeout = 5)
{
    Gui::Event event;
    Gui::GameData gameData;

    cr_assert_null(event.getGameData());
    event.setGameData(std::make_shared<Gui::GameData>(gameData));
    cr_assert_not_null(event.getGameData());
}

Test(Event, getRender, .timeout = 5)
{
    Gui::Event event;

    cr_assert_null(event.getRender());
}
