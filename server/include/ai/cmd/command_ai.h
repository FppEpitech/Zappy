/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI Command
*/

#pragma once

#include "ai/ai.h"

#define BEGIN 1
#define END 2

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

/**
 * @brief Command Broadcast.
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 * @param line The command of AI.
 * @return true If command was find.
 * @return false If command wasn't find.
 */
bool broadcast_command(app_t *app, ia_t *ai, char *line);

/**
 * @brief
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 * @param line The command of AI.
 * @return true If command was find.
 * @return false If command wasn't find.
 */
bool incantation_command(app_t *app, ia_t *ai, char *line);

/**
 * @brief Check condition of incantation
 *
 * @param app Application with necessary information.
 * @param ai AI who have launch the incantation.
 * @param status BEGIN or END (to know if I have to verify status incantation)
 * @return true If condition is good
 * @return false If condition isn't good
 */
bool check_incantation(app_t *app, ia_t *ai, int status);

/**
 * @brief Update status incantation of all participating people.
 *
 * @param app Application with necessary information.
 * @param ai AI who have launch the incantation.
 */
void update_status(app_t *app, ia_t *ai);

/**
 * @brief Level up all player of incantation and delete all ressources.
 *
 * @param app Application with necessary information.
 * @param ai AI who have launch the incantation.
 */
void level_up(app_t *app, ia_t *ai);

/**
 * @brief Add a command to the list
 *
 * @param ai Ai who do the command
 * @param line Command.
 */
void add_command_to_list(ia_t *ai, char *line);

/**
 * @brief Treat command of all ai.
 *
 * @param app Application with necessary information.
 */
void treat_command(app_t *app);
