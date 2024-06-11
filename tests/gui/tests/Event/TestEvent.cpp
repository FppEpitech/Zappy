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
