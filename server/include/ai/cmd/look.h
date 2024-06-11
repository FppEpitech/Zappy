/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI Command
*/

#pragma once

#include "ai/ai.h"

#define PLAYER_STRING " player"
#define EGG_STRING " egg"
#define FOOD_STRING " food"
#define LINEMATE_STRING " linemate"
#define DERAUMERE_STRING " deraumere"
#define SIBUR_STRING " sibur"
#define MENDIANE_STRING " mendiane"
#define PHIRAS_STRING " phiras"
#define THYSTAME_STRING " thystame"

/**
 * @brief Handler of command look.
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 */
void look_cmd(app_t *app, ia_t *ai);

/**
 * @brief Check if there is a player in pos indicate.
 *
 * @param pos Pos to check.
 * @param app Application with necessary information.
 * @param reply Reply where add player.
 * @param ai AI who have done a command.
 */
void check_player(vector2i_t *pos, app_t *app, char **reply, ia_t *ai);

/**
 * @brief Check if there is an egg in pos indicate.
 *
 * @param pos Pos to check.
 * @param app Application with necessary information.
 * @param reply Reply where add player.
 */
void check_egg(vector2i_t *pos, app_t *app, char **reply);

/**
 * @brief Check if there is resources in pos indicate.
 *
 * @param pos Pos to check.
 * @param app Application with necessary information.
 * @param reply Reply where add player.
 */
void check_resources(vector2i_t *pos, app_t *app, char **reply);

/**
 * @brief Handler of look command with the north orientation.
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 * @param index_line Index for line to get elements.
 * @param reply Reply of command look.
 */
void look_north(app_t *app, ia_t *ai, int index_line, char **reply);

/**
 * @brief Handler of look command with the east orientation.
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 * @param index_line Index for line to get elements.
 * @param reply Reply of command look.
 */
void look_east(app_t *app, ia_t *ai, int index_line, char **reply);

/**
 * @brief Handler of look command with the south orientation.
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 * @param index_line Index for line to get elements.
 * @param reply Reply of command look.
 */
void look_south(app_t *app, ia_t *ai, int index_line, char **reply);

/**
 * @brief Handler of look command with the west orientation.
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 * @param index_line Index for line to get elements.
 * @param reply Reply of command look.
 */
void look_west(app_t *app, ia_t *ai, int index_line, char **reply);
