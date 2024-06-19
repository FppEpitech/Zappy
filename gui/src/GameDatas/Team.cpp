/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Team
*/

#include "Assets.hpp"
#include "Config.hpp"
#include "GameDatas/Team.hpp"
#include "raymath.h"

Gui::Team::Team(const std::string &name, const std::string &playerModelPath, const std::string &eggModelPath, Color playerColor) : _name(name), _playerColor(playerColor)
{
    _playerModel = LoadModel(playerModelPath.c_str());
    _eggModel = LoadModel(eggModelPath.c_str());
    _animsCount = 0;
    _modelAnimation = LoadModelAnimations(MODEL_PLAYER, &_animsCount);
}

const std::string &Gui::Team::getName() const
{
    return _name;
}

Gui::Team::~Team()
{
}

void Gui::Team::setName(const std::string &name)
{
    _name = name;
}

std::vector<Gui::Player> &Gui::Team::getPlayers()
{
    return _players;
}

std::vector<Gui::Egg> &Gui::Team::getEggs()
{
    return _eggs;
}

void Gui::Team::addPlayer(const Gui::Player &player)
{
    _players.push_back(player);
}

void Gui::Team::addEgg(const Gui::Egg &egg)
{
    _eggs.push_back(egg);
}

bool Gui::Team::removePlayer(std::size_t id)
{
    for (auto iterator = _players.begin(); iterator != _players.end(); iterator++) {
        if (iterator->getId() == id) {
            _players.erase(iterator);
            return true;
        }
    }
    return false;
}

bool Gui::Team::removeEgg(std::size_t id)
{
    for (auto iterator = _eggs.begin(); iterator != _eggs.end(); iterator++) {
        if (iterator->getId() == id) {
            _eggs.erase(iterator);
            return true;
        }
    }
    return false;
}

std::shared_ptr<Gui::Player> Gui::Team::getPlayer(std::size_t id)
{
    for (auto &player : _players) {
        if (player.getId() == id) {
            return std::make_shared<Gui::Player>(player);
        }
    }
    return nullptr;
}

Model Gui::Team::getPlayerModel() const
{
    return _playerModel;
}

ModelAnimation *Gui::Team::getPlayerModelAnimation() const
{
    return _modelAnimation;
}

void Gui::Team::setPlayerModelPath(const std::string &playerModelPath)
{
    _playerModel = LoadModel(playerModelPath.c_str());
}

std::shared_ptr<Gui::Egg> Gui::Team::getEgg(std::size_t id)
{
    for (auto &egg : _eggs) {
        if (egg.getId() == id) {
            return std::make_shared<Gui::Egg>(egg);
        }
    }
    return nullptr;
}

Model Gui::Team::getEggModel() const
{
    return _eggModel;
}

void Gui::Team::setEggModelPath(const std::string &eggModelPath)
{
    _eggModel = LoadModel(eggModelPath.c_str());
}

std::vector<BoundingBox> Gui::Team::getPlayerBoundingBoxes(std::pair<size_t, size_t> pos, size_t orientation, Vector3 center)
{
    std::vector<BoundingBox> bboxes;
    Model model = this->getPlayerModel();

    for (int i = 0; i < model.meshCount; i++) {
        BoundingBox bbox = GetMeshBoundingBox(model.meshes[i]);

        // Set the rotation of the bounding box
        bbox = rotateBoundingBoxByOrientation(bbox, orientation, pos, center);

        // Scale the bounding box to the player scale
        bbox.min.x = bbox.min.x * SCALE_PLAYER.x;
        bbox.min.y = bbox.min.y * SCALE_PLAYER.y;
        bbox.min.z = bbox.min.z * SCALE_PLAYER.z;

        bbox.max.x = bbox.max.x * SCALE_PLAYER.x;
        bbox.max.y = bbox.max.y * SCALE_PLAYER.y;
        bbox.max.z = bbox.max.z * SCALE_PLAYER.z;

        // Translate the bounding box to the player position
        bbox.min.x = bbox.min.x + (pos.first * SIZE_TILE);
        bbox.min.y = bbox.min.y + POS_PLAYER.y;
        bbox.min.z = bbox.min.z + (pos.second * SIZE_TILE);

        bbox.max.x = bbox.max.x + (pos.first * SIZE_TILE);
        bbox.max.y = bbox.max.y + POS_PLAYER.y;
        bbox.max.z = bbox.max.z + (pos.second * SIZE_TILE);

        bboxes.push_back(bbox);
    }
    return bboxes;
}

Vector3 Gui::Team::getPlayerPositionIn3DSpace(std::size_t id, Map<Gui::Tile> map)
{
    Vector3 result;
    for (auto &row : map) {
        for (auto &tile : row) {
            if (tile.getPosition().first == this->getPlayer(id).get()->getPosition().first && tile.getPosition().second == this->getPlayer(id).get()->getPosition().second) {
                Vector3 posTile = tile.getPositionIn3DSpace();
                result.x = posTile.x + POS_PLAYER.x;
                result.y = posTile.y + POS_PLAYER.y;
                result.z = posTile.z + POS_PLAYER.z;
            }
        }
    }
    return result;
}

std::vector<RayCollision> Gui::Team::getPlayerModelHitbox(size_t id, Camera camera)
{
    std::vector<BoundingBox> towerBBox;

    for (auto &player : this->getPlayers()) {
        if (player.getId() == id)
            towerBBox = this->getPlayerBoundingBoxes(player.getPosition(), player.getOrientation(), player.getCenterPosition());
    }
    std::vector<RayCollision> boxHitInfo;

    Ray ray = GetMouseRay((Vector2){(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2}, camera);

    for (int i = 0; i < this->getPlayerModel().meshCount; i++)
        boxHitInfo.push_back(GetRayCollisionBox(ray, towerBBox[i]));
    return boxHitInfo;
}

bool Gui::Team::isPlayerHit(size_t id, Camera camera)
{
    std::vector<BoundingBox> towerBBox;
    std::vector<RayCollision> boxHitInfo = this->getPlayerModelHitbox(id, camera);

    for (auto &player : this->getPlayers()) {
        if (player.getId() == id)
            towerBBox = this->getPlayerBoundingBoxes(player.getPosition(), player.getOrientation(), player.getCenterPosition());
    }
    for (size_t i = 0; i < towerBBox.size(); i++) {
        if (boxHitInfo[i].hit)
            return true;
    }
    return false;
}

Color Gui::Team::getPlayerColor() const
{
    return _playerColor;
}

BoundingBox Gui::Team::rotateBoundingBoxByOrientation(BoundingBox bbox, size_t orientation, std::pair<size_t, size_t> pos, Vector3 centerPos)
{
    BoundingBox result = bbox;

    switch (orientation) {
    case 1:
        result.min.x = centerPos.x - bbox.max.x - (pos.first * SIZE_TILE + SIZE_TILE / 2);
        result.min.z = centerPos.z - bbox.max.z - (pos.second * SIZE_TILE + SIZE_TILE / 2);
        result.max.x = centerPos.x - bbox.min.x - (pos.first * SIZE_TILE + SIZE_TILE / 2);
        result.max.z = centerPos.z - bbox.min.z - (pos.second * SIZE_TILE + SIZE_TILE / 2);
        break;
    case 2:
        result.min.x = bbox.min.z - centerPos.z + (pos.second * SIZE_TILE + SIZE_TILE / 2);
        result.min.z = bbox.min.x - centerPos.x + (pos.first * SIZE_TILE + SIZE_TILE / 2);
        result.max.x = bbox.max.z - centerPos.z + (pos.second * SIZE_TILE + SIZE_TILE / 2);
        result.max.z = bbox.max.x - centerPos.x + (pos.first * SIZE_TILE + SIZE_TILE / 2);
        break;
    case 3:
        result.min.x = bbox.min.x - centerPos.x + (pos.first * SIZE_TILE + SIZE_TILE / 2);
        result.min.z = bbox.min.z - centerPos.z + (pos.second * SIZE_TILE + SIZE_TILE / 2);
        result.max.x = bbox.max.x - centerPos.x + (pos.first * SIZE_TILE + SIZE_TILE / 2);
        result.max.z = bbox.max.z - centerPos.z + (pos.second * SIZE_TILE + SIZE_TILE / 2);
        break;
    case 4:
        result.min.x = centerPos.z - bbox.max.z - (pos.second * SIZE_TILE + SIZE_TILE / 2);
        result.min.z = centerPos.x - bbox.max.x - (pos.first * SIZE_TILE + SIZE_TILE / 2);
        result.max.x = centerPos.z - bbox.min.z - (pos.second * SIZE_TILE + SIZE_TILE / 2);
        result.max.z = centerPos.x - bbox.min.x - (pos.first * SIZE_TILE + SIZE_TILE / 2);
        break;
    default:
        break;
    }
    return result;
}
