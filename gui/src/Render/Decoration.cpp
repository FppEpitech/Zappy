/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Decoration
*/

#include "Render/Decoration.hpp"

Gui::Decoration::Decoration()
{
    _treeModel = LoadModel(MODEL_TREE);
}

Map<bool> Gui::Decoration::getGenerationItem(std::size_t ratio)
{
    (void) ratio;
    Map<bool> map;

    for (size_t i = 0; i < _mapSize.first; i++) {
        std::vector<bool> line;
        for (size_t j = 0; j < _mapSize.second; j++) {
            if (std::rand() % ratio == 1) line.push_back(true);
            else line.push_back(false);
        }
        map.push_back(line);
    }
    return map;
}

void Gui::Decoration::display(std::pair<std::size_t, std::size_t> mapSize)
{
    if (mapSize != _mapSize) {
        _mapSize = mapSize;
        _mapTree = getGenerationItem(5);
    }
    displayTree();
}

void Gui::Decoration::displayTree(void)
{
    Vector3 posTreeModel = POS_TREE;

    for (size_t i = 0; i < _mapTree.size(); i++) {
        for (size_t j = 0; j < _mapTree[i].size(); j++) {
            if (_mapTree[i][j]) {
                Vector3 posTile = {(float)(i * SIZE_TILE), 0.0f, (float)(j * SIZE_TILE)};
                DrawModelEx(_treeModel, (Vector3){posTile.x + posTreeModel.x, posTile.y + posTreeModel.y, posTile.z + posTreeModel.z}, ROTATION_AXIS_TREE, ROTATION_ANGLE_TREE, SCALE_TREE, WHITE);
            }
        }
    }
}
