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
 * @brief Handler of command who send object info(Look, Inventory)
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 * @param line The command of AI.
 * @return true If command was find.
 * @return false If command wasn't find.
 */
bool object_info_command(app_t *app, ia_t *ai, char *line);
