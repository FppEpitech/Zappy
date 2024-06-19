/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Colors
*/

#pragma once

#include "raylib.h"

#include <vector>

#define STR_BLUE "\033[0;34m"
#define STR_GREEN "\033[0;32m"
#define STR_RED "\033[0;31m"
#define STR_YELLOW "\033[0;33m"
#define STR_VIOLET "\033[0;35m"
#define STR_CYAN "\033[0;36m"
#define STR_RESET "\033[0m"

static std::vector<Color> playerColors = {
    PINK,
    LIGHTGRAY,
    GRAY,
    DARKGRAY,
    YELLOW,
    GOLD,
    ORANGE,
    RED,
    MAROON,
    GREEN,
    LIME,
    DARKGREEN,
    SKYBLUE,
    BLUE,
    DARKBLUE,
    PURPLE,
    VIOLET,
    DARKPURPLE,
    BEIGE,
    BROWN,
    DARKBROWN,
    WHITE,
    BLACK,
    MAGENTA,
    RAYWHITE
};
