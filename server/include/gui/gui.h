/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Gui struct
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

#include "list/list.h"

typedef struct s_gui {
    size_t fd;
    list_t *list_messages;
} gui_t;

/**
 * @brief Create a gui object
 *
 * @param fd File Descriptor of GUI.
 * @return gui_t* Gui created.
 */
gui_t *create_gui(int fd);

/**
 * @brief Add gui to the list
 *
 * @param app Application with list of gui.
 * @param fd File descriptor of GUI.
 * @return true If no error.
 * @return false If error.
 */
void add_gui(app_t *app, size_t fd);

/**
 * @brief Find a gui throw a file descriptor.
 *
 * @param app Application with list of gui.
 * @param fd File descriptor to find.
 * @return gui_t* GUi find or NULL.
 */
gui_t *find_gui(app_t *app, size_t fd);
