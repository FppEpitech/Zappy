/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Render
*/

#include "Assets.hpp"
#include "Render/Render.hpp"

#include <string>

Gui::Render::Render(std::shared_ptr<GameData> gameData)
    : _gameData(gameData)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    DisableCursor();
    SetTargetFPS(140);
    _isDebug = false;
    this->LoadModels();
}

void Gui::Render::LoadModels(void)
{
    _tileModel = LoadModel(MODEL_TILE);
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
    displayMap();
    EndMode3D();

    displayDebug();

    EndDrawing();
}

std::shared_ptr<Camera> Gui::Render::getCamera()
{
    return _camera.getCamera();
}

void Gui::Render::setIsDebug(bool isDebug)
{
    _isDebug = isDebug;
}

bool Gui::Render::getIsDebug(void)
{
    return _isDebug;
}

void Gui::Render::displayDebug(void)
{
    if (_isDebug) {
        DrawFPS(10, 10);
        DrawText(("XYZ: " +
            std::to_string(_camera.getCamera()->position.x) + " / " +
            std::to_string(_camera.getCamera()->position.y) + " / " +
            std::to_string(_camera.getCamera()->position.z)
            ).c_str(), 10, 30, 20, LIME);
        DrawText(("LOOK AT: " +
            std::to_string(_camera.getCamera()->target.x) + " / " +
            std::to_string(_camera.getCamera()->target.y) + " / " +
            std::to_string(_camera.getCamera()->target.z)
            ).c_str(), 10, 50, 20, LIME);
    }
}

void Gui::Render::displayMap()
{
    for (auto &line : _gameData->getMap()) {
        for (auto &tile : line)
            DrawModel(_tileModel, tile.getPositionIn3DSpace(), 0.001f, WHITE);
    }
}
