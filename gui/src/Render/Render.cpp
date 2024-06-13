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
    _hudList.push_back(std::make_shared<HudPlayer>(HudPlayer(gameData)));
    _hudList.push_back(std::make_shared<HudGame>(HudGame(gameData)));
    _decoration = std::make_shared<Decoration>(Decoration());
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

    ClearBackground(ORANGE);

    BeginMode3D(*_camera.getCamera());
    displayMap();
    displayPlayers();
    EndMode3D();

    displayHUD();
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

bool Gui::Render::getIsDebug()
{
    return _isDebug;
}

void Gui::Render::displayDebug()
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

void Gui::Render::displayPlayers()
{
    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (_gameData.get()->getMap().size() == 0 || _gameData.get()->getMap()[player.getPosition().first].size() == 0)
                return;

            float rotation = player.getRotationFromOrientation();

            DrawModelEx(team.getPlayerModel(), team.getPlayerPositionIn3DSpace(player.getId(), _gameData.get()->getMap()), ROTATION_AXIS_PLAYER, rotation, SCALE_PLAYER, WHITE);

            if (_isDebug) {
                std::vector<BoundingBox> bboxes = team.getPlayerBoundingBoxes(player.getPosition(), player.getOrientation(), player.getCenterPosition());
                std::vector<RayCollision> hitbox = team.getPlayerModelHitbox(player.getId(), *_camera.getCamera().get());

                for (size_t i = 0; i < bboxes.size(); i++)
                    DrawBoundingBox(bboxes[i], GREEN);
            }
        }
    }
}

void Gui::Render::displayMap()
{
    for (auto &line : _gameData->getMap()) {
        for (auto &tile : line) {
            displayTile(tile);
            displayFood(tile);
            displayResources(tile);
            displayEggs(tile);
            _decoration->display(_gameData->getMapSize());
        }
    }
}

void Gui::Render::displayTile(Tile tile)
{
    DrawModel(_tileModel, tile.getPositionIn3DSpace(), 1.0f, WHITE);
    if (_isDebug) {
        std::vector<BoundingBox> bboxes = tile.getTileBoundingBoxes(tile, _tileModel);
        for (size_t i = 0; i < bboxes.size(); i++)
            DrawBoundingBox(bboxes[i], GREEN);
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

void Gui::Render::displayHUD(void)
{
    for (auto &hud : _hudList) {
        if (hud->getType() == Gui::HudPlayer::POV_PLAYER && _camera.getType() == Gui::UserCamera::POV_PLAYER) {
            hud->setPlayer(std::make_shared<Player>(_gameData->getPlayer(_camera.getPlayerId())));
            hud->display();
        }
        if (hud->getType() == Gui::HudGame::GAME && _camera.getType() == Gui::UserCamera::FREE)
            hud->display();
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

void Gui::Render::setCameraPlayerPov(std::size_t id)
{
    _camera.setPlayerId(id);
}

std::size_t Gui::Render::getCameraPlayerPov() const
{
    return _camera.getPlayerId();
}

Model Gui::Render::getTileModel() const
{
    return _tileModel;
}
