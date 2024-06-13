/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TestDecoration
*/

#include "Render/Decoration.hpp"
#include "CriterionHeaders.hpp"

void DrawModelEx(Model model, Vector3 position, Vector3 rotationAxis,
    float rotationAngle, Vector3 scale, Color tint)
{
    (void) model;
    (void) position;
    (void) rotationAxis;
    (void) rotationAngle;
    (void) scale;
    (void) tint;
}

Test(Decoration, getGenerationItem, .timeout = 5)
{
    Gui::Decoration deco;

    deco.display(std::make_pair(2,2));
    Map<bool> generation = deco.getGenerationItem(1);

    cr_assert(!generation[0][0]);
    cr_assert(!generation[0][1]);
    cr_assert(!generation[1][0]);
    cr_assert(!generation[1][1]);
}
