/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Tile
*/

#include "Assets.hpp"
#include "GameDatas/Tile.hpp"

Gui::Tile::Tile(std::pair<std::size_t, std::size_t> position)
{
    setPosition(position);
}

Gui::Tile::Tile(std::pair<std::size_t, std::size_t> position, Inventory inventory) : inventory(inventory)
{
    setPosition(position);
}

void Gui::Tile::setPosition(std::pair<std::size_t, std::size_t> position)
{
    _position = position;
    _positionIn3DSpace = (Vector3) {(float)(position.first * SIZE_TILE), 0.0f, (float)(position.second * SIZE_TILE)};
}

std::pair<std::size_t, std::size_t> Gui::Tile::getPosition() const
{
    return _position;
}

Vector3 Gui::Tile::getPositionIn3DSpace()
{
    return _positionIn3DSpace;
}

std::vector<BoundingBox> Gui::Tile::getTileBoundingBoxes(Tile tile, Model tileModel)
{
    std::vector<BoundingBox> bboxes;

    for (int i = 0; i < tileModel.meshCount; i++) {
        BoundingBox bbox = GetMeshBoundingBox(tileModel.meshes[i]);
        bbox.min.x += tile.getPositionIn3DSpace().x;
        bbox.min.y += tile.getPositionIn3DSpace().y;
        bbox.min.z += tile.getPositionIn3DSpace().z;
        bbox.max.x += tile.getPositionIn3DSpace().x;
        bbox.max.y += tile.getPositionIn3DSpace().y;
        bbox.max.z += tile.getPositionIn3DSpace().z;
        bboxes.push_back(bbox);
    }
    return bboxes;
}

std::vector<RayCollision> Gui::Tile::getTileModelHitbox(Tile tile, Camera camera, Model tileModel)
{
    std::vector<BoundingBox> towerBBox = tile.getTileBoundingBoxes(tile, tileModel);
    std::vector<RayCollision> boxHitInfo;

    Ray ray = GetMouseRay((Vector2){(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2}, camera);

    for (size_t i = 0; i < towerBBox.size(); i++)
        boxHitInfo.push_back(GetRayCollisionBox(ray, towerBBox[i]));
    return boxHitInfo;
}

bool Gui::Tile::isTileHit(Camera camera, Model _tileModel)
{
    std::vector<BoundingBox> towerBBox = getTileBoundingBoxes(*this, _tileModel);
    std::vector<RayCollision> boxHitInfo = getTileModelHitbox(*this, camera, _tileModel);

    for (size_t i = 0; i < towerBBox.size(); i++) {
        if (boxHitInfo[i].hit)
            return true;
    }
    return false;
}
