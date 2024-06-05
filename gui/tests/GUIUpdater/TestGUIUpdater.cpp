/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TestGUIUpdater
*/

#include "CriterionHeaders.hpp"
#include "GUIUpdater/GUIUpdater.hpp"

Test(GUIUpdater, constructor, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    cr_assert_not_null(&guiUpdater);
}

Test(GUIUpdater, update, .timeout = 5)
{
    std::shared_ptr<Gui::GameData> gameData = std::make_shared<Gui::GameData>();
    Gui::GUIUpdater guiUpdater(gameData);

    guiUpdater.update("test", "test");
    cr_assert_not_null(&guiUpdater);
}