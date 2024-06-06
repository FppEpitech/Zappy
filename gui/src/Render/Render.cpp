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
    _foodModel = LoadModel(MODEL_FOOD);
    _linemateModel = LoadModel(MODEL_LINEMATE);
    _mendianeModel = LoadModel(MODEL_MENDIANE);
    _phirasModel = LoadModel(MODEL_PHIRAS);
    _siburModel = LoadModel(MODEL_SIBUR);
    _thystameModel = LoadModel(MODEL_THYSTAME);
    _deraumereModel = LoadModel(MODEL_DERAUMERE);
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

    ClearBackground(SKYBLUE);

    BeginMode3D(*_camera.getCamera());
    displayMap();
    displayPlayers();
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

void Gui::Render::displayPlayers(void) const
{
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            Vector3 posPlayer = (Vector3){(float)(player.getPosition().first), 0, (float)(player.getPosition().second)};
            Vector3 posAssetPlayer = POS_PLAYER;
            DrawModelEx(team.getModel(), (Vector3){posPlayer.x + posAssetPlayer.x, posPlayer.y + posAssetPlayer.y, posPlayer.z + posAssetPlayer.z}, ROTATION_AXIS_PLAYER, ROTATION_ANGLE_PLAYER, SCALE_PLAYER, WHITE);
        }
    }
}

void Gui::Render::displayMap(void) const
{
    for (auto &line : _gameData->getMap()) {
        for (auto &tile : line) {
            DrawModel(_tileModel, tile.getPositionIn3DSpace(), 0.001f, WHITE);
            displayFood(tile);
            displayResources(tile);
        }
    }
}

void Gui::Render::displayFood(Tile tile) const
{
    if (tile._inventory.getFood() == 0)
        return;
    Vector3 posTile = tile.getPositionIn3DSpace();
    Vector3 posFood = POS_FOOD;

    DrawModelEx(_foodModel, (Vector3){posTile.x + posFood.x, posTile.y + posFood.y, posTile.z + posFood.z}, ROTATION_AXIS_FOOD, ROTATION_ANGLE_FOOD, SCALE_FOOD, WHITE);
}

void Gui::Render::displayResources(Tile tile) const
{
    displayLinemate(tile);
    displayMendiane(tile);
    displayPhiras(tile);
    displaySibur(tile);
    displayThystame(tile);
    displayDeraumere(tile);
}

void Gui::Render::displayLinemate(Tile tile) const
{
    Vector3 posTile = tile.getPositionIn3DSpace();

    if (tile._inventory.getLinemate() != 0) {
        Vector3 posLinemate = POS_LINEMATE;
        DrawModelEx(_linemateModel, (Vector3){posTile.x + posLinemate.x, posTile.y + posLinemate.y, posTile.z + posLinemate.z}, ROTATION_AXIS_LINEMATE, ROTATION_ANGLE_LINEMATE, SCALE_LINEMATE, WHITE);
    }
}

void Gui::Render::displayMendiane(Tile tile) const
{
    Vector3 posTile = tile.getPositionIn3DSpace();

    if (tile._inventory.getMendiane() != 0) {
        Vector3 posMendiane = POS_MENDIANE;
        DrawModelEx(_mendianeModel, (Vector3){posTile.x + posMendiane.x, posTile.y + posMendiane.y, posTile.z + posMendiane.z}, ROTATION_AXIS_MENDIANE, ROTATION_ANGLE_MENDIANE, SCALE_MENDIANE, WHITE);
    }
}

void Gui::Render::displayPhiras(Tile tile) const
{
    Vector3 posTile = tile.getPositionIn3DSpace();

    if (tile._inventory.getPhiras() != 0) {
        Vector3 posPhiras = POS_PHIRAS;
        DrawModelEx(_phirasModel, (Vector3){posTile.x + posPhiras.x, posTile.y + posPhiras.y, posTile.z + posPhiras.z}, ROTATION_AXIS_PHIRAS, ROTATION_ANGLE_PHIRAS, SCALE_PHIRAS, WHITE);
    }
}

void Gui::Render::displaySibur(Tile tile) const
{
    Vector3 posTile = tile.getPositionIn3DSpace();

    if (tile._inventory.getSibur() != 0) {
        Vector3 posSibur = POS_SIBUR;
        DrawModelEx(_siburModel, (Vector3){posTile.x + posSibur.x, posTile.y + posSibur.y, posTile.z + posSibur.z}, ROTATION_AXIS_SIBUR, ROTATION_ANGLE_SIBUR, SCALE_SIBUR, WHITE);
    }
}

void Gui::Render::displayThystame(Tile tile) const
{
    Vector3 posTile = tile.getPositionIn3DSpace();

    if (tile._inventory.getThystame() != 0) {
        Vector3 posThystame = POS_THYSTAME;
        DrawModelEx(_thystameModel, (Vector3){posTile.x + posThystame.x, posTile.y + posThystame.y, posTile.z + posThystame.z}, ROTATION_AXIS_THYSTAME, ROTATION_ANGLE_THYSTAME, SCALE_THYSTAME, WHITE);
    }
}

void Gui::Render::displayDeraumere(Tile tile) const
{
    Vector3 posTile = tile.getPositionIn3DSpace();

    if (tile._inventory.getDeraumere() != 0) {
        Vector3 posDeraumere = POS_DERAUMERE;
        DrawModelEx(_deraumereModel, (Vector3){posTile.x + posDeraumere.x, posTile.y + posDeraumere.y, posTile.z + posDeraumere.z}, ROTATION_AXIS_DERAUMERE, ROTATION_ANGLE_DERAUMERE, SCALE_DERAUMERE, WHITE);
    }
}
