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

    _camera.position = (Vector3){ 5.0f, 5.0f, 5.0f };    // Camera position
    _camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };      // Camera looking at point
    _camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    _camera.fovy = 70.0f;                                // Camera field-of-view Y
    _camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

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
    UpdateCamera(&_camera, CAMERA_FIRST_PERSON);
    BeginDrawing();

    ClearBackground(RAYWHITE);
    BeginMode3D(_camera);
    DrawGrid(10, 1.0f);
    EndMode3D();

    DrawFPS(10, 10);

    EndDrawing();
}
