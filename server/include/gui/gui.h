/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Server struct
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

typedef struct s_gui {
    bool connected;
    size_t fd;
} gui_t;
