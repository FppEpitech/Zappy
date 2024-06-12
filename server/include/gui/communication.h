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

/**
 * @brief Response to the msz command.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line Unused.
 */
void msz_response(gui_t *gui, app_t *app, char *line);

/**
 * @brief Response to the tna command.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line Unused.
 */
void tna_response(gui_t *gui, app_t *app, char *line);

/**
 * @brief Response to the sgt command.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line Unused.
 */
void sgt_response(gui_t *gui, app_t *app, char *line);

/**
 * @brief Response to the sst command.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line The command to handle.
 */
void sst_response(gui_t *gui, app_t *app, char *line);

/**
 * @brief Response to the bct command.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line The command to handle.
 */
void bct_response(gui_t *gui, app_t *app, char *line);

/**
 * @brief Response to the mct command.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line Unused.
 */
void mct_response(gui_t *gui, app_t *app, char *line);

/**
 * @brief Response to the ppo command.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line The command to handle.
 */
void ppo_response(gui_t *gui, app_t *app, char *line);

/**
 * @brief Response to the plv command.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line The command to handle.
 */
void plv_response(gui_t *gui, app_t *app, char *line);

/**
 * @brief Response to the pin command.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line The command to handle.
 */
void pin_response(gui_t *gui, app_t *app, char *line);

/**
 * @brief Response to the pnw command.
 *
 * @param app The app structure with all the gui fds.
 * @param ai The ia structure of client requested.
 */
void pnw_command(app_t *app, ia_t *ai);

/**
 * @brief Perform the pex command.
 *
 * @param app The app structure with all the gui fds.
 * @param player_id The player id expulsed.
 */
void pex_command(app_t *app, int player_id);
