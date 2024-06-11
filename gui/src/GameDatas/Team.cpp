/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Team
*/

#include "Assets.hpp"
#include "GameDatas/Team.hpp"

Gui::Team::Team(const std::string &name, const std::string &playerModelPath, const std::string &eggModelPath) : _name(name)
{
    _playerModel = LoadModel(playerModelPath.c_str());
    _eggModel = LoadModel(eggModelPath.c_str());
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

std::vector<BoundingBox> Gui::Team::getPlayerBoundingBoxes()
{
    std::vector<BoundingBox> bboxes;

    for (int i = 0; i < this->getPlayerModel().meshCount; i++) {
        BoundingBox bbox = GetMeshBoundingBox(this->getPlayerModel().meshes[i]);

        // Scale the bounding box to the player scale
        bbox.min.x = bbox.min.x * SCALE_PLAYER.x;
        bbox.min.y = bbox.min.y * SCALE_PLAYER.y;
        bbox.min.z = bbox.min.z * SCALE_PLAYER.z;

        bbox.max.x = bbox.max.x * SCALE_PLAYER.x;
        bbox.max.y = bbox.max.y * SCALE_PLAYER.y;
        bbox.max.z = bbox.max.z * SCALE_PLAYER.z;

        bboxes.push_back(bbox);
    }
    return bboxes;
}

Vector3 Gui::Team::getPlayerPositionIn3DSpace(std::size_t id, std::vector<std::vector<Gui::Tile>> map)
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
    (void)id;
    std::vector<RayCollision> boxHitInfo;
    std::vector<BoundingBox> towerBBox = this->getPlayerBoundingBoxes();
    Ray ray = GetMouseRay((Vector2){(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2}, camera);

    for (int i = 0; i < this->getPlayerModel().meshCount; i++)
        boxHitInfo.push_back(GetRayCollisionBox(ray, towerBBox[i]));
    return boxHitInfo;
}

bool Gui::Team::isPlayerHit(size_t id, Camera camera)
{
    std::vector<RayCollision> boxHitInfo = this->getPlayerModelHitbox(id, camera);
    std::vector<BoundingBox> towerBBox = this->getPlayerBoundingBoxes();

    for (size_t i = 0; i < towerBBox.size(); i++) {
        if (boxHitInfo[i].hit)
            return true;
    }
    return false;
}
