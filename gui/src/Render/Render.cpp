/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Render
*/

#include "Assets.hpp"
#include "Config.hpp"
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
    _hudList.push_back(std::make_shared<HudTile>(HudTile(gameData)));
    _hudList.push_back(std::make_shared<HudHelp>(HudHelp(gameData)));
    _decoration = std::make_shared<Decoration>(Decoration());
    this->LoadModels();
    _renderDistance = DEFAULT_RENDER_DISTANCE;
    _isHelpMenu = false;
    _endHudSet = false;
    int animCount = 0;
    _gameData.get()->setAnimsCount(animCount);
}

void Gui::Render::LoadModels()
{
    _tileModel = LoadModel(MODEL_TILE);
    _foodModel = LoadModel(MODEL_FOOD);
    _linemateModel = LoadModel(MODEL_LINEMATE);
    _mendianeModel = LoadModel(MODEL_MENDIANE);
    _phirasModel = LoadModel(MODEL_PHIRAS);
    _siburModel = LoadModel(MODEL_SIBUR);
    _thystameModel = LoadModel(MODEL_THYSTAME);
    _deraumereModel = LoadModel(MODEL_DERAUMERE);

    int animCount = 0;
    Model playerModel = LoadModel(MODEL_PLAYER);
    Model eggModel = LoadModel(MODEL_EGG);
    ModelAnimation* playerModelAnimation = LoadModelAnimations(MODEL_PLAYER, &animCount);
    _gameData.get()->setAnimsCount(animCount);
    _gameData.get()->setPlayerModel(playerModel);
    _gameData.get()->setEggModel(eggModel);
    _gameData.get()->setPlayerModelAnimation(playerModelAnimation);

    _cursorTexture = LoadTexture(PNG_CURSOR);
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
    if (_gameData.get()->getIsEndGame()) {
        if (!_endHudSet) {
            _endHudSet = true;
            _hudList.push_back(std::make_shared<HudEnd>(HudEnd(_gameData)));
        }
        drawEnd();
        return;
    }
    _playerVisionPositions.clear();
    if (!_camera.isPlayerPov())
        UpdateCamera(_camera.getCamera().get(), CAMERA_FIRST_PERSON);
    else
        setPlayerPov(_camera.getPlayerId());

    BeginDrawing();

    ClearBackground(ORANGE);

    BeginMode3D(*_camera.getCamera());
    displayMap();
    displayPlayers();
    EndMode3D();

    displayHUD();
    displayDebug();
    displayCursor();

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

void Gui::Render::setCameraTile(std::pair<std::size_t, std::size_t> pos)
{
    _camera.setTilePos(pos);
}

std::pair<std::size_t, std::size_t> Gui::Render::getCameraTile() const
{
    return _camera.getTilePos();
}

Model Gui::Render::getTileModel() const
{
    return _tileModel;
}

void Gui::Render::setRenderDistance(size_t renderDistance)
{
    if (renderDistance < MIN_RENDER_DISTANCE)
        renderDistance = MIN_RENDER_DISTANCE;
    if (renderDistance > MAX_RENDER_DISTANCE)
        renderDistance = MAX_RENDER_DISTANCE;
    _renderDistance = renderDistance;
}

size_t Gui::Render::getRenderDistance() const
{
    return _renderDistance;
}

bool Gui::Render::isCameraInPlayerPov() const
{
    return _camera.isPlayerPov();
}

size_t Gui::Render::getTimeUnit() const
{
    return _gameData.get()->getServerTick();
}

void Gui::Render::setTimeUnit(size_t timeUnit)
{
    _gameData.get()->setServerTick(timeUnit);
}

void Gui::Render::setPlayerVision(bool isPlayerVision)
{
    _camera.setPlayerVision(isPlayerVision);
}

bool Gui::Render::getPlayerVision() const
{
    return _camera.isPlayerVision();
}

void Gui::Render::setHelpMenu(bool isHelpMenu)
{
    _isHelpMenu = isHelpMenu;
}

bool Gui::Render::getHelpMenu() const
{
    return _isHelpMenu;
}

void Gui::Render::drawEnd() const
{
    BeginDrawing();

    ClearBackground(ORANGE);

    for (auto &hud : _hudList) {
        if (hud->getType() == Gui::HudEnd::END)
            hud->display();
    }

    EndDrawing();
}

void Gui::Render::displayDebug()
{
    if (_isDebug) {
        int fps = GetFPS();
        DrawText(("FPS: " + std::to_string(fps)).c_str(), 10, 10, 20, LIME);
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
        DrawText(("Render distance: " + std::to_string(_renderDistance) + " chunks.").c_str(), 10, 70, 20, LIME);
        DrawText(("Camera Tile XZ: " + std::to_string(getCameraTile().first) + " / " + std::to_string(getCameraTile().second)).c_str(), 10, 90, 20, LIME);
        DrawText(("CAMERA TYPE: " + std::to_string(_camera.getType())).c_str(), 10, 110, 20, LIME);
    }
    DrawText(("Time Unit: " + std::to_string(_gameData.get()->getServerTick())).c_str(), 10, WINDOW_HEIGHT - 20, 20, WHITE);
}

void Gui::Render::displayPlayers()
{
    std::pair<size_t, size_t> camTile = getCameraTile();

    for (auto &team : _gameData->getTeams()) {
        for (auto &player : team.getPlayers()) {
            if (_camera.isPlayerPov())
                camTile = _gameData->getPlayer(_camera.getPlayerId()).getPosition();
            if (_gameData.get()->getMap().size() == 0 || _gameData.get()->getMap()[player.getPosition().first].size() == 0)
                return;
            if (abs(player.getPosition().first - camTile.first) > (_renderDistance - 1) || abs(player.getPosition().second - camTile.second) > (_renderDistance - 1))
                continue;
            if (abs(player.getPosition().first - camTile.first) == (_renderDistance - 1) && abs(player.getPosition().second - camTile.second) == (_renderDistance - 1))
                continue;
            if (!isInArrayPlayerVision(player.getPosition()))
                continue;

            if (!displayAnimations(team, player))
                continue;

            if (_camera.getPlayerId() == (int)player.getId() && _camera.getType() == Gui::UserCamera::FIRST_PERSON)
                continue;

            float rotation = player.getRotationFromOrientation();

            if (player.getState() == Gui::Player::WALK)
                DrawModelEx(team.getPlayerModel(), player.getPosition3D(), ROTATION_AXIS_PLAYER, rotation, SCALE_PLAYER, team.getPlayerColor());
            else
                DrawModelEx(team.getPlayerModel(), team.getPlayerPositionIn3DSpace(player.getId(), _gameData.get()->getMap()), ROTATION_AXIS_PLAYER, rotation, SCALE_PLAYER, team.getPlayerColor());

            if (player.getState() == Gui::Player::BROADCAST)
                displayPlayerBroadcast(team, player);

            if (_isDebug) {
                std::vector<BoundingBox> bboxes = team.getPlayerBoundingBoxes(player.getPosition(), player.getOrientation(), player.getCenterPosition());
                std::vector<RayCollision> hitbox = team.getPlayerModelHitbox(player.getId(), *_camera.getCamera().get());

                for (size_t i = 0; i < bboxes.size(); i++)
                    DrawBoundingBox(bboxes[i], GREEN);
            }
            displayPlayerLevel(player, team.getPlayerPositionIn3DSpace(player.getId(), _gameData.get()->getMap()), team);
        }
    }
}

void Gui::Render::displayPlayerLevel(Gui::Player &player, Vector3 playerPos, Team &team)
{
    EndMode3D();

    Vector2 playerScreenPosition = GetWorldToScreen((Vector3){playerPos.x, playerPos.y + PLAYER_HEIGHT + 0.5f, playerPos.z}, *_camera.getCamera().get());
    std::string countStr = "Lvl: " + std::to_string(player.getLevel());
    Vector3 posDiff = (Vector3){playerPos.x, playerPos.y + PLAYER_HEIGHT + 0.5f, playerPos.z};
    posDiff.x -= _camera.getCamera()->position.x;
    posDiff.y -= _camera.getCamera()->position.y;
    posDiff.z -= _camera.getCamera()->position.z;

    posDiff.z = posDiff.z < 0 ? posDiff.z * -1 : posDiff.z;
    posDiff.x = posDiff.x < 0 ? posDiff.x * -1 : posDiff.x;
    posDiff.y = posDiff.y < 0 ? posDiff.y * -1 : posDiff.y;
    int fontSize = PLAYER_TEXT_SIZE - (int)(posDiff.z * PLAYER_TEXT_SIZE_RATIO);

    bool isHit = team.isPlayerHit(player.getId(), *_camera.getCamera().get());
    if (isHit)
        DrawText(countStr.c_str(), (int)playerScreenPosition.x - MeasureText(countStr.c_str(), fontSize)/2, (int)playerScreenPosition.y , fontSize, WHITE);
    BeginMode3D(*_camera.getCamera());
}

void Gui::Render::displayPlayerBroadcast(Gui::Team &team, Gui::Player &player)
{
    EndMode3D();

    Vector3 playerPos = team.getPlayerPositionIn3DSpace(player.getId(), _gameData.get()->getMap());
    Vector2 playerScreenPosition = GetWorldToScreen((Vector3){playerPos.x, playerPos.y + PLAYER_HEIGHT + 0.7f, playerPos.z}, *_camera.getCamera().get());
    std::string countStr = player.getBroadcast();

    Vector3 posDiff = (Vector3){playerPos.x, playerPos.y + PLAYER_HEIGHT + 0.7f, playerPos.z};
    posDiff.x -= _camera.getCamera()->position.x;
    posDiff.y -= _camera.getCamera()->position.y;
    posDiff.z -= _camera.getCamera()->position.z;

    posDiff.z = posDiff.z < 0 ? posDiff.z * -1 : posDiff.z;
    posDiff.x = posDiff.x < 0 ? posDiff.x * -1 : posDiff.x;
    posDiff.y = posDiff.y < 0 ? posDiff.y * -1 : posDiff.y;
    int fontSize = PLAYER_TEXT_SIZE - (int)(posDiff.z * PLAYER_TEXT_SIZE_RATIO);

    DrawText(countStr.c_str(), (int)playerScreenPosition.x - MeasureText(countStr.c_str(), fontSize)/2, (int)playerScreenPosition.y , fontSize, WHITE);

    BeginMode3D(*_camera.getCamera());
}

void Gui::Render::displayMap()
{
    std::pair<size_t, size_t> camTile = getCameraTile();

    for (auto &line : _gameData->getMap()) {
        for (auto &tile : line) {
            if (_camera.isPlayerPov())
                camTile = _gameData->getPlayer(_camera.getPlayerId()).getPosition();
            if (abs(camTile.first - tile.getPosition().first) > (_renderDistance - 1) || abs(camTile.second - tile.getPosition().second) > (_renderDistance - 1))
                continue;
            if (!isInArrayPlayerVision(tile.getPosition()))
                continue;
            displayTile(tile);
            displayFood(tile);
            displayResources(tile);
            displayEggs(tile);
        }
    }
    _decoration->display(_gameData->getMapSize(), _renderDistance, camTile, _playerVisionPositions);
}

void Gui::Render::displayTile(Tile tile)
{
    Vector3 tilePos3D = tile.getPositionIn3DSpace();
    DrawModel(_tileModel, tilePos3D, 1.0f, WHITE);

    if (_isDebug) {
        std::vector<BoundingBox> bboxes = tile.getTileBoundingBoxes(tile, _tileModel);
        for (size_t i = 0; i < bboxes.size(); i++)
            DrawBoundingBox(bboxes[i], GREEN);
    } else {
        DrawLine3D( (Vector3){(float)(tilePos3D.x - SIZE_TILE / 2.0f), tilePos3D.y + POS_Y_DELIMITATION, (float)(tilePos3D.z - SIZE_TILE / 2.0f)},
                    (Vector3){(float)(tilePos3D.x - SIZE_TILE / 2.0f), tilePos3D.y + POS_Y_DELIMITATION, (float)(tilePos3D.z + SIZE_TILE / 2.0f)}, DARKGREEN);

        DrawLine3D( (Vector3){(float)(tilePos3D.x - SIZE_TILE / 2.0f), tilePos3D.y + POS_Y_DELIMITATION, (float)(tilePos3D.z + SIZE_TILE / 2.0f)},
                    (Vector3){(float)(tilePos3D.x + SIZE_TILE / 2.0f), tilePos3D.y + POS_Y_DELIMITATION, (float)(tilePos3D.z + SIZE_TILE / 2.0f)}, DARKGREEN);

        DrawLine3D( (Vector3){(float)(tilePos3D.x + SIZE_TILE / 2.0f), tilePos3D.y + POS_Y_DELIMITATION, (float)(tilePos3D.z + SIZE_TILE / 2.0f)},
                    (Vector3){(float)(tilePos3D.x + SIZE_TILE / 2.0f), tilePos3D.y + POS_Y_DELIMITATION, (float)(tilePos3D.z - SIZE_TILE / 2.0f)}, DARKGREEN);

        DrawLine3D( (Vector3){(float)(tilePos3D.x + SIZE_TILE / 2.0f), tilePos3D.y + POS_Y_DELIMITATION, (float)(tilePos3D.z - SIZE_TILE / 2.0f)},
                    (Vector3){(float)(tilePos3D.x - SIZE_TILE / 2.0f), tilePos3D.y + POS_Y_DELIMITATION, (float)(tilePos3D.z - SIZE_TILE / 2.0f)}, DARKGREEN);
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
    for (auto &eggs: _gameData.get()->getServerEggs()) {
        if (eggs.getPosition().first != tile.getPosition().first || eggs.getPosition().second != tile.getPosition().second)
            continue;
        Vector3 posEggModel = POS_EGG;
        Vector3 posTile = tile.getPositionIn3DSpace();
        DrawModelEx(_gameData.get()->getTeams()[0].getEggModel(), (Vector3){posTile.x + posEggModel.x, posTile.y + posEggModel.y, posTile.z + posEggModel.z}, ROTATION_AXIS_EGG, ROTATION_ANGLE_EGG, SCALE_EGG, WHITE);
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

void Gui::Render::displayHUD()
{
    for (auto &hud : _hudList) {
        if (hud->getType() == Gui::HudPlayer::POV_PLAYER && _camera.isPlayerPov()) {
            hud->setPlayer(std::make_shared<Player>(_gameData->getPlayer(_camera.getPlayerId())));
            hud->display();
        }
        if (hud->getType() == Gui::HudGame::GAME && _camera.getType() == Gui::UserCamera::FREE)
            hud->display();
        if (hud->getType() == Gui::HudTile::TILE && _camera.getType() == Gui::UserCamera::FREE_TILE) {
            hud->setTile(std::make_shared<Tile>(_gameData->getTile(_camera.getTilePos().first, _camera.getTilePos().second)));
            hud->display();
        }
        if (hud->getType() == Gui::HudHelp::HELP_MENU || hud->getType() == Gui::HudHelp::HELP_TEXT)
            displayHelpMenu(hud);
    }
}

void Gui::Render::displayCursor()
{
    if (_camera.getType() != Gui::UserCamera::CameraType::SECOND_PERSON && _camera.getType() != Gui::UserCamera::CameraType::THIRD_PERSON && !_isHelpMenu)
        DrawTexture(_cursorTexture, GetScreenWidth() / 2 - _cursorTexture.width / 2, GetScreenHeight() / 2 - _cursorTexture.height / 2, BLACK);
}

std::pair<size_t, size_t> Gui::Render::getCameraTile()
{
    std::pair<size_t, size_t> tilePos = {1, 1};
    if (_gameData.get()->getMap().size() == 0 || _gameData.get()->getMap()[0].size() == 0)
        return tilePos;
    tilePos = _gameData.get()->getMap()[0][0].getPosition();
    Tile tileTmp = _gameData.get()->getMap()[0][0];

    for (auto &line: _gameData.get()->getMap()) {
        for (auto &tile: line) {
            Vector3 tmpPos = tile.getPositionIn3DSpace();
            Vector3 camPos = _camera.getCamera()->position;
            size_t xDiffNew = abs(tmpPos.x - camPos.x);
            size_t zDiffNew = abs(tmpPos.z - camPos.z);
            size_t xDiffOld = abs(tileTmp.getPositionIn3DSpace().x - camPos.x);
            size_t zDiffOld = abs(tileTmp.getPositionIn3DSpace().z - camPos.z);
            if (xDiffNew < xDiffOld) {
                tileTmp = tile;
                tilePos = tile.getPosition();
            }
            if (zDiffNew < zDiffOld) {
                tileTmp = tile;
                tilePos = tile.getPosition();
            }
        }
    }
    return tilePos;
}

// Camera Pov //

void Gui::Render::changePlayerPOV(size_t playerId)
{
    if (getCameraType() == Gui::UserCamera::CameraType::FIRST_PERSON)
        changePOVToThirdPerson(playerId);
    else if (getCameraType() == Gui::UserCamera::CameraType::SECOND_PERSON)
        changePOVToFirstPerson(playerId);
    else if (getCameraType() == Gui::UserCamera::CameraType::THIRD_PERSON)
        changePOVToSecondPerson(playerId);
    if (_camera.isPlayerVision())
        _playerVisionPositions = getPositionsInPlayerVision(playerId);
}

void Gui::Render::setPlayerPov(size_t playerId)
{
    if (getCameraType() == Gui::UserCamera::CameraType::FIRST_PERSON)
        changePOVToFirstPerson(playerId);
    else if (getCameraType() == Gui::UserCamera::CameraType::SECOND_PERSON)
        changePOVToSecondPerson(playerId);
    else if (getCameraType() == Gui::UserCamera::CameraType::THIRD_PERSON)
        changePOVToThirdPerson(playerId);
    if (_camera.isPlayerVision())
        _playerVisionPositions = getPositionsInPlayerVision(playerId);
}

void Gui::Render::changePOVToFirstPerson(size_t playerId)
{
    Gui::Player player = _gameData->getPlayer(playerId);
    Vector3 playerPos;

    try {
        playerPos = player.getPosition3D();
    } catch (const Gui::Errors::GuiGameDataException &e) {
        return;
    }
    getCamera().get()->target = playerPos;

    if (player.getOrientation() == 1)
        getCamera().get()->target.z = playerPos.z - 2.0f;
    else if (player.getOrientation() == 3)
        getCamera().get()->target.z = playerPos.z + 2.0f;
    else if (player.getOrientation() == 2)
        getCamera().get()->target.x = playerPos.x + 2.0f;
    else if (player.getOrientation() == 4)
        getCamera().get()->target.x = playerPos.x - 2.0f;
    getCamera().get()->target.y = playerPos.y + PLAYER_HEIGHT;
    getCamera().get()->position = playerPos;
    getCamera().get()->position.y += PLAYER_HEIGHT;
    setCameraType(Gui::UserCamera::CameraType::FIRST_PERSON);
    setCameraPlayerPov(playerId);
}

void Gui::Render::changePOVToSecondPerson(size_t playerId)
{
    Gui::Player player = _gameData->getPlayer(playerId);
    Vector3 playerPos;

    try {
        playerPos = player.getPosition3D();
    } catch (const Gui::Errors::GuiGameDataException &e) {
        return;
    }
    getCamera().get()->position = playerPos;

    if (player.getOrientation() == 1)
        getCamera().get()->position.z = playerPos.z - PLAYER_SECOND_PERSON_FOV;
    else if (player.getOrientation() == 3)
        getCamera().get()->position.z = playerPos.z + PLAYER_SECOND_PERSON_FOV;
    else if (player.getOrientation() == 2)
        getCamera().get()->position.x = playerPos.x + PLAYER_SECOND_PERSON_FOV;
    else if (player.getOrientation() == 4)
        getCamera().get()->position.x = playerPos.x - PLAYER_SECOND_PERSON_FOV;
    getCamera().get()->position.y = playerPos.y + PLAYER_HEIGHT;
    getCamera().get()->target = playerPos;
    getCamera().get()->target.y += PLAYER_HEIGHT;
    setCameraType(Gui::UserCamera::CameraType::SECOND_PERSON);
    setCameraPlayerPov(playerId);
}

void Gui::Render::changePOVToThirdPerson(size_t playerId)
{
    Gui::Player player = _gameData->getPlayer(playerId);
    Vector3 playerPos;

    try {
        playerPos = player.getPosition3D();
    } catch (const Gui::Errors::GuiGameDataException &e) {
        return;
    }
    getCamera().get()->position = playerPos;
    getCamera().get()->position.y = playerPos.y + 4.0f;

    if (player.getOrientation() == 1)
        getCamera().get()->position.z = playerPos.z + PLAYER_THIRD_PERSON_FOV;
    else if (player.getOrientation() == 3)
        getCamera().get()->position.z = playerPos.z - PLAYER_THIRD_PERSON_FOV;
    else if (player.getOrientation() == 2)
        getCamera().get()->position.x = playerPos.x - PLAYER_THIRD_PERSON_FOV;
    else if (player.getOrientation() == 4)
        getCamera().get()->position.x = playerPos.x + PLAYER_THIRD_PERSON_FOV;
    getCamera().get()->target = playerPos;
    getCamera().get()->target.y += PLAYER_HEIGHT;
    setCameraType(Gui::UserCamera::CameraType::THIRD_PERSON);
    setCameraPlayerPov(playerId);
}

std::vector<Vector2> Gui::Render::getPositionsInPlayerVision(size_t playerId)
{
    Player player = _gameData->getPlayer(playerId);
    std::vector<Vector2> positions = {(Vector2){(float)player.getPosition().first, (float)player.getPosition().second}};
    size_t orientation = player.getOrientation();
    Vector2 tmp = {(float)player.getPosition().first, (float)player.getPosition().second};

    for (size_t i = 1; i <= player.getLevel() && i < (_renderDistance + 3) && i <= 3; i++) {
        switch (orientation) {
            case 1:
                tmp.y -= 1;
                break;
            case 2:
                tmp.x += 1;
                break;
            case 3:
                tmp.y += 1;
                break;
            case 4:
                tmp.x -= 1;
                break;
            default:
                break;
        }
        positions = addVisionPosition(positions, getLineOfVision(tmp, i, orientation));
    }
    return positions;
}

bool Gui::Render::isInArrayPlayerVision(std::pair<size_t, size_t> pos)
{
    if (_playerVisionPositions.empty())
        return true;
    for (auto &position : _playerVisionPositions) {
        if (position.x == pos.first && position.y == pos.second)
            return true;
    }
    return false;
}

std::vector<Vector2> Gui::Render::getLineOfVision(Vector2 pos, size_t sizeOfHalf, size_t direction)
{
    std::vector<Vector2> positions;
    Vector2 tmp1 = pos;
    Vector2 tmp2 = pos;

    positions.push_back(pos);
    for (size_t i = 0; i < sizeOfHalf; i++) {
        if (direction == 1 || direction == 3) {
            tmp1.x -= 1;
            tmp2.x += 1;
        } else if (direction == 2 || direction == 4) {
            tmp1.y += 1;
            tmp2.y -= 1;
        }
        positions.push_back(tmp1);
        positions.push_back(tmp2);
    }
    return positions;
}

std::vector<Vector2> Gui::Render::addVisionPosition(std::vector<Vector2> vision, std::vector<Vector2> pos)
{
    for (auto &position : pos)
        vision.push_back(position);
    return vision;
}

void Gui::Render::displayHelpMenu(std::shared_ptr<Gui::IHud> hud)
{
    if (_isHelpMenu)
        hud->setType(Gui::HudHelp::HELP_MENU);
    else
        hud->setType(Gui::HudHelp::HELP_TEXT);
    hud->display();
}
