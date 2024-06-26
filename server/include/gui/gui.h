/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Gui struct
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

#include "app/app.h"
#include "list/list.h"

typedef struct s_gui {
    size_t fd;
    list_t *list_command;
    list_t *list_messages;
} gui_t;

/**
 * @brief Create a gui object.
 *
 * @param fd File Descriptor of GUI.
 * @return gui_t* Gui created.
 */
gui_t *create_gui(int fd);

/**
 * @brief Add gui to the list.
 *
 * @param app Application with list of gui.
 * @param fd File descriptor of GUI.
 * @param line GRAPHIC team.
 */
void add_gui(app_t *app, size_t fd, char *line);

/**
 * @brief Find a gui throw a file descriptor.
 *
 * @param app Application with list of gui.
 * @param fd File descriptor to find.
 * @return gui_t* GUi find or NULL.
 */
gui_t *find_gui(app_t *app, size_t fd);

/**
 * @brief Destroy gui list.
 *
 * @param gui_list List of gui.
 * @param app Application with all information.
 */
void destroy_gui(app_t *app, list_t *gui_list);

/**
 * @brief Add a command to gui list.
 *
 * @param gui GUI where add the list.
 * @param line Command to add.
 */
void add_command_to_gui_list(gui_t *gui, char *line);

/**
 * @brief Treat the command of all GUI.
 * @param app Application with list of GUI.
 */
void treat_gui_command(app_t *app);
