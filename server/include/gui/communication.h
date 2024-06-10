/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** communication
*/

#pragma once

#include "../app/app.h"
#include "gui.h"

/**
 * @brief Handle all the commands of the GUI.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line The command to handle.
 */
void handle_command_gui(gui_t *gui, app_t *app, char *line);
