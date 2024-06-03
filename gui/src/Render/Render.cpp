/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Render
*/

#include "Render/Render.hpp"

Gui::Render::Render()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    DisableCursor();
    SetTargetFPS(140);
}

Gui::Render::~Render()
{
    CloseWindow();
}

bool Gui::Render::isOpen()
{
    return !WindowShouldClose();
}

void Gui::Render::draw()
{
    UpdateCamera(_camera.getCamera().get(), CAMERA_FIRST_PERSON);
    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginMode3D(*_camera.getCamera());
    DrawGrid(20, 1.0f);
    EndMode3D();

    DrawFPS(10, 10);

    EndDrawing();
}
