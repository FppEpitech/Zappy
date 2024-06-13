/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Types
*/

#pragma once

#include <vector>

/**
 * @brief Map type.
 *
 * @tparam T Type of the map.
*/
template<typename T>
using Map = std::vector<std::vector<T>>;
