/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI Command
*/

#pragma once

#include "ai/ai.h"

/**
 * @brief Handler of AI command.
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 * @param line The command of AI.
 */
void command_ai_handler(app_t *app, ia_t *ai, char *line);

/**
 * @brief Handler of command who move player(Forward, Right, Left)
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 * @param line The command of AI.
 * @return true If command was find.
 * @return false If command wasn't find.
 */
bool move_command(app_t *app, ia_t *ai, char *line);

/**
 * @brief Handler of command who send object info (Look, Inventory)
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 * @param line The command of AI.
 * @return true If command was find.
 * @return false If command wasn't find.
 */
bool object_info_command(app_t *app, ia_t *ai, char *line);

/**
 * @brief Handler of other command (Connect_nbr)
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 * @param line The command of AI.
 * @return true If command was find.
 * @return false If command wasn't find.
 */
bool other_command(app_t *app, ia_t *ai, char *line);

/**
 * @brief Command eject.
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 */
void eject_cmd(app_t *app, ia_t *ai);

/**
 * @brief Command eject player.
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 */
void eject_player(app_t *app, ia_t *ai);

/**
 * @brief Command eject egg.
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 */
void eject_egg(app_t *app, ia_t *ai);

/**
 * @brief Dead response for all other AI.
 *
 * @param app Application with necessary information.
 */
void dead_response(app_t *app);

/**
 * @brief Command to fork and create an egg.
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 */
void fork_cmd(app_t *app, ia_t *ai);

/**
 * @brief Command to know the place available in the team's ai.
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 */
void connect_nbr_cmd(app_t *app, ia_t *ai);

/**
 * @brief Command take objects.
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 */
void take_cmd(app_t *app, ia_t *ai);

/**
 * @brief Command set objects.
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 */
void set_cmd(app_t *app, ia_t *ai);
