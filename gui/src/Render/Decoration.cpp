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
    //TODO : Unlock when multithreading: _lanternModel = LoadModel(MODEL_LANTERN);
}

Map<bool> Gui::Decoration::getGenerationItem(std::size_t ratio)
{
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
        //TODO : Unlock when multithreading: _mapLantern = getGenerationItem(3);
    }

    for (size_t i = 0; i < _mapSize.first; i++) {
        for (size_t j = 0; j < _mapSize.second; j++) {
            Vector3 posTile = {(float)(i * SIZE_TILE), 0.0f, (float)(j * SIZE_TILE)};
            displayTree(i, j, posTile);
            //TODO : Unlock when multithreading: displayLantern(i, j, posTile);
        }
    }
}

void Gui::Decoration::displayTree(size_t i, size_t j, Vector3 posTile)
{
    Vector3 posTreeModel = POS_TREE;
    if (_mapTree[i][j])
        DrawModelEx(_treeModel, (Vector3){posTile.x + posTreeModel.x, posTile.y + posTreeModel.y, posTile.z + posTreeModel.z}, ROTATION_AXIS_TREE, ROTATION_ANGLE_TREE, SCALE_TREE, WHITE);
}

void Gui::Decoration::displayLantern(size_t i, size_t j, Vector3 posTile)
{
    Vector3 posLanternModel = POS_LANTERN;
    if (_mapLantern[i][j])
        DrawModelEx(_lanternModel, (Vector3){posTile.x + posLanternModel.x, posTile.y + posLanternModel.y, posTile.z + posLanternModel.z}, ROTATION_AXIS_LANTERN, ROTATION_ANGLE_LANTERN, SCALE_LANTERN, WHITE);
}
