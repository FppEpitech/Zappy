/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Header file for the communication functions between the GUI and the server.
*/

#pragma once

#include "gui.h"
#include "../app/app.h"

#define POS_SPACE 3
#define LEN_COMMAND 3
#define LEN_COMMAND_AND_SPACE LEN_COMMAND + 1

enum e_command_label {
    CL_MSZ,
    CL_BCT,
    CL_MCT,
    CL_TNA,
    CL_PPO,
    CL_PLV,
    CL_PIN,
    CL_SGT,
    CL_SST,
    CL_LEN,
};

/**
 * @brief Handle all the commands of the GUI.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line The command to handle.
 */
void handle_command_gui(gui_t *gui, app_t *app, char *line);

/**
 * @brief Response to the msz command. For get the size of the map.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line Unused.
 */
void msz_response(gui_t *gui, app_t *app, char *line);

/**
 * @brief Response to the tna command. For get the names of all the teams.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line Unused.
 */
void tna_response(gui_t *gui, app_t *app, char *line);

/**
 * @brief Response to the sgt command. For get the time unit of the server.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line Unused.
 */
void sgt_response(gui_t *gui, app_t *app, char *line);

/**
 * @brief Response to the sst command. For set the time unit of the server.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line The command to handle.
 */
void sst_response(gui_t *gui, app_t *app, char *line);

/**
 * @brief Response to the bct command. For get the content of a tile.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line The command to handle.
 */
void bct_response(gui_t *gui, app_t *app, char *line);

/**
 * @brief Response to the mct command. For get the content of all the tiles.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line Unused.
 */
void mct_response(gui_t *gui, app_t *app, char *line);

/**
 * @brief Response to the ppo command. For get the position of a player.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line The command to handle.
 */
void ppo_response(gui_t *gui, app_t *app, char *line);

/**
 * @brief Response to the plv command. For get the level of a player.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line The command to handle.
 */
void plv_response(gui_t *gui, app_t *app, char *line);

/**
 * @brief Response to the pin command. For get the inventory of a player.
 *
 * @param gui The gui structure of client requested.
 * @param app The app structure.
 * @param line The command to handle.
 */
void pin_response(gui_t *gui, app_t *app, char *line);

/**
 * @brief Response to the pnw command. For inform the GUI of a new player.
 *
 * @param app The app structure with all the gui fds.
 * @param ai The ia structure of client requested.
 * @param gui The gui structure of client requested,
 * if no client requestes set it to null.
 */
void pnw_command(app_t *app, ia_t *ai, gui_t *gui);

/**
 * @brief Perform the pex command. For inform the GUI when a player expulse.
 *
 * @param app The app structure with all the gui fds.
 * @param player_id The player id expulsed.
 */
void pex_command(app_t *app, int player_id);

/**
 * @brief Perform the pbc command. For inform the GUI when a player broadcast.
 *
 * @param app The app structure with all the gui fds.
 * @param player_id The player id expulsed.
 * @param message The message send.
 */
void pbc_command(app_t *app, int player_id, char *message);

/**
 * @brief Perform the pfk command. For inform the GUI when a player fork.
 *
 * @param app The app structure with all the gui fds.
 * @param player_id The player id who call the command.
 */
void pfk_command(app_t *app, int player_id);

/**
 * @brief Perform the pdr command.
 * For inform the GUI when a player drop an object.
 *
 * @param app The app structure with all the gui fds.
 * @param player_id The player id who call the command.
 */
void pdr_command(app_t *app, int player_id);

/**
 * @brief Perform the pgt command.
 * For inform the GUI when a player take an object.
 *
 * @param app The app structure with all the gui fds.
 * @param player_id The player id who call the command.
 */
void pgt_command(app_t *app, int player_id);

/**
 * @brief Perform the pdi command. For inform the GUI when a player die.
 *
 * @param app The app structure with all the gui fds.
 * @param player_id The player id who call the command.
 */
void pdi_command(app_t *app, int player_id);

/**
 * @brief Perform the enw command. For inform the GUI when an egg is laid.
 *
 * @param app The app structure with all the gui fds.
 * @param team The winner team name.
 */
void seg_command(app_t *app, char *team);

/**
 * @brief Perform the smg command. For send a message to all the GUI.
 *
 * @param app The app structure with all the gui fds.
 * @param message The message to send.
 */
void smg_command(app_t *app, char *message);

/**
 * @brief Response to a command when the command is unknown.
 *
 * @param gui The gui structure of client requested.
 */
void suc_command(gui_t *gui);

/**
 * @brief Response to a command when a command.s parameter.s is invalid.
 *
 * @param gui The gui structure of client requested.
 */
void sbp_command(gui_t *gui);

/**
 * @brief The pic command. For send message to all the GUI,
 *  when a incantation start.
 *
 * @param app The app structure.
 * @param ai The list of all the ia in the incantation.
 */
void pic_command(app_t *app, list_t *ai);

/**
 * @brief The pie command. For send message to all the GUI,
 * when a incantation end.
 * @param app The app structure.
 * @param ai The list of all the ia in the incantation.
 */
void pie_command(app_t *app, list_t *ai);

/**
 * @brief The enw command. For send message to all the GUI,
 * when an egg is laid.
 * @param app The app structure.
 * @param egg The egg structure.
 * @param gui The gui structure of client requested,
 * if no client requestes set it to null.
 */
void enw_command(app_t *app, egg_t *egg, gui_t *gui);

/**
 * @brief The eht command. For send message to all the GUI,
 * when an egg is killed.
 * @param app The app structure.
 * @param egg_id The egg id.
 */
void edi_command(app_t *app, int egg_id);

/**
 * @brief The ebo command. For send message to all the GUI.
 *
 * @param app The app structure.
 * @param egg_id The player id.
 */
void ebo_command(app_t *app, int egg_id);
