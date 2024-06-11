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
    ToggleFullscreen();
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
    if (_camera.getType() != Gui::UserCamera::POV_PLAYER)
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

#define FLOAT_MAX     340282346638528859811704183484516925440.0f

void Gui::Render::displayPlayers(void)
{
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            Vector3 posAssetPlayer = POS_PLAYER;
            Vector3 posTile = _gameData->getMap()[player.getPosition().first][player.getPosition().second].getPositionIn3DSpace();
            DrawModelEx(team.getPlayerModel(), (Vector3){posTile.x + posAssetPlayer.x, posTile.y + posAssetPlayer.y, posTile.z + posAssetPlayer.z}, ROTATION_AXIS_PLAYER, ROTATION_ANGLE_PLAYER, SCALE_PLAYER, WHITE);
            DrawModelEx(team.getPlayerModel(), (Vector3){posPlayer.x + posAssetPlayer.x, posPlayer.y + posAssetPlayer.y, posPlayer.z + posAssetPlayer.z}, ROTATION_AXIS_PLAYER, ROTATION_ANGLE_PLAYER, SCALE_PLAYER, WHITE);
            BoundingBox towerBBox = GetMeshBoundingBox(_gameData->getTeams()[0].getPlayerModel().meshes[0]);
            DrawBoundingBox(towerBBox, LIME);

            Ray ray;
            RayCollision collision;
            collision.distance = FLOAT_MAX;
            collision.hit = false;

            ray = GetScreenToWorldRayEx(GetMousePosition(), *_camera.getCamera(), GetScreenWidth(), GetScreenHeight());

            // // BoundingBox towerBBox = GetMeshBoundingBox(_gameData->getTeams()[0].getPlayerModel().meshes[0]);


            RayCollision boxHitInfo = GetRayCollisionBox(ray, towerBBox);
            // DrawBoundingBox(towerBBox, LIME);

            if ((boxHitInfo.hit) && (boxHitInfo.distance < collision.distance))
                {
                    std::cout << "hit" << std::endl;
            //         collision = boxHitInfo;

            //         RayCollision meshHitInfo;
            //         for (int m = 0; m < _gameData->getTeams()[0].getPlayerModel().meshCount; m++)
            //         {
            //             // NOTE: We consider the model.transform for the collision check but
            //             // it can be checked against any transform Matrix, used when checking against same
            //             // model drawn multiple times with multiple transforms
            //             meshHitInfo = GetRayCollisionMesh(ray, _gameData->getTeams()[0].getPlayerModel().meshes[m], _gameData->getTeams()[0].getPlayerModel().transform);
            //             if (meshHitInfo.hit)
            //             {
            //                 // Save the closest hit mesh
            //                 if ((!collision.hit) || (collision.distance > meshHitInfo.distance)) collision = meshHitInfo;

            //                 break;  // Stop once one mesh collision is detected, the colliding mesh is m
            //             }
            //         }

            //         if (meshHitInfo.hit)
            //         {
            //             collision = meshHitInfo;
            //         }
                }
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
            displayEggs(tile);
        }
    }
}

void Gui::Render::displayEggs(Tile tile) const
{
    for (auto &team : _gameData->getTeams()) {
        for (auto &egg: team.getEggs()) {
            if (egg.getPosition().first != tile.getPosition().first || egg.getPosition().second != tile.getPosition().second)
                continue;
            Vector3 posEggModel = POS_EGG;
            Vector3 posTile = tile.getPositionIn3DSpace();
            DrawModelEx(team.getEggModel(), (Vector3){posTile.x + posEggModel.x, posTile.y + posEggModel.y, posTile.z + posEggModel.z}, ROTATION_AXIS_EGG, ROTATION_ANGLE_EGG, SCALE_EGG, WHITE);
        }
    }
}

void Gui::Render::displayFood(Tile tile) const
{
    if (tile.inventory.getFood() == 0)
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

    if (tile.inventory.getLinemate() != 0) {
        Vector3 posLinemate = POS_LINEMATE;
        DrawModelEx(_linemateModel, (Vector3){posTile.x + posLinemate.x, posTile.y + posLinemate.y, posTile.z + posLinemate.z}, ROTATION_AXIS_LINEMATE, ROTATION_ANGLE_LINEMATE, SCALE_LINEMATE, WHITE);
    }
}

void Gui::Render::displayMendiane(Tile tile) const
{
    Vector3 posTile = tile.getPositionIn3DSpace();

    if (tile.inventory.getMendiane() != 0) {
        Vector3 posMendiane = POS_MENDIANE;
        DrawModelEx(_mendianeModel, (Vector3){posTile.x + posMendiane.x, posTile.y + posMendiane.y, posTile.z + posMendiane.z}, ROTATION_AXIS_MENDIANE, ROTATION_ANGLE_MENDIANE, SCALE_MENDIANE, WHITE);
    }
}

void Gui::Render::displayPhiras(Tile tile) const
{
    Vector3 posTile = tile.getPositionIn3DSpace();

    if (tile.inventory.getPhiras() != 0) {
        Vector3 posPhiras = POS_PHIRAS;
        DrawModelEx(_phirasModel, (Vector3){posTile.x + posPhiras.x, posTile.y + posPhiras.y, posTile.z + posPhiras.z}, ROTATION_AXIS_PHIRAS, ROTATION_ANGLE_PHIRAS, SCALE_PHIRAS, WHITE);
    }
}

void Gui::Render::displaySibur(Tile tile) const
{
    Vector3 posTile = tile.getPositionIn3DSpace();

    if (tile.inventory.getSibur() != 0) {
        Vector3 posSibur = POS_SIBUR;
        DrawModelEx(_siburModel, (Vector3){posTile.x + posSibur.x, posTile.y + posSibur.y, posTile.z + posSibur.z}, ROTATION_AXIS_SIBUR, ROTATION_ANGLE_SIBUR, SCALE_SIBUR, WHITE);
    }
}

void Gui::Render::displayThystame(Tile tile) const
{
    Vector3 posTile = tile.getPositionIn3DSpace();

    if (tile.inventory.getThystame() != 0) {
        Vector3 posThystame = POS_THYSTAME;
        DrawModelEx(_thystameModel, (Vector3){posTile.x + posThystame.x, posTile.y + posThystame.y, posTile.z + posThystame.z}, ROTATION_AXIS_THYSTAME, ROTATION_ANGLE_THYSTAME, SCALE_THYSTAME, WHITE);
    }
}

void Gui::Render::displayDeraumere(Tile tile) const
{
    Vector3 posTile = tile.getPositionIn3DSpace();

    if (tile.inventory.getDeraumere() != 0) {
        Vector3 posDeraumere = POS_DERAUMERE;
        DrawModelEx(_deraumereModel, (Vector3){posTile.x + posDeraumere.x, posTile.y + posDeraumere.y, posTile.z + posDeraumere.z}, ROTATION_AXIS_DERAUMERE, ROTATION_ANGLE_DERAUMERE, SCALE_DERAUMERE, WHITE);
    }
}

void Gui::Render::setCameraType(Gui::UserCamera::CameraType type)
{
    _camera.setType(type);
}

Gui::UserCamera::CameraType Gui::Render::getCameraType() const
{
    return _camera.getType();
}
