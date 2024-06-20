/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Decoration
*/

#include "Config.hpp"
#include "Render/Decoration.hpp"

Gui::Decoration::Decoration()
{
    _treeModel = LoadModel(MODEL_TREE);
}

Map<bool> Gui::Decoration::getGenerationItem(std::size_t ratio)
{
    Map<bool> map;

    for (size_t i = 0; i < _mapSize.first; i++) {
        std::vector<bool> line;
        for (size_t j = 0; j < _mapSize.second; j++) {
            if (std::rand() % ratio == 1)
                line.push_back(true);
            else
                line.push_back(false);
        }
        map.push_back(line);
    }
    return map;
}

void Gui::Decoration::display(std::pair<std::size_t, std::size_t> mapSize, size_t renderDistance, std::pair<std::size_t, std::size_t> camPos)
{
    if (mapSize != _mapSize) {
        _mapSize = mapSize;
        _mapTree = getGenerationItem(5);
    }

    for (int i = 0; i < (int)_mapSize.first; i++) {
        for (int j = 0; j < (int)_mapSize.second; j++) {
            if (i > (int)(camPos.first - renderDistance) && i < (int)(camPos.first + renderDistance) && j > (int)(camPos.second - renderDistance) && j < (int)(camPos.second + renderDistance)) {
                Vector3 posTile = {(float)(i * SIZE_TILE), 0.0f, (float)(j * SIZE_TILE)};
                displayTree(i, j, posTile);
            }
        }
    }
}

void Gui::Decoration::displayTree(size_t i, size_t j, Vector3 posTile)
{
    Vector3 posTreeModel = POS_TREE;
    if (_mapTree[i][j])
        DrawModelEx(_treeModel, (Vector3){posTile.x + posTreeModel.x, posTile.y + posTreeModel.y, posTile.z + posTreeModel.z}, ROTATION_AXIS_TREE, ROTATION_ANGLE_TREE, SCALE_TREE, WHITE);
}
