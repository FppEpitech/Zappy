/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI Command
*/

#pragma once

#include "ai/ai.h"

#define BEGIN_INCANTATION 1
#define END_INCANTATION 2

/**
 * @brief Handler of AI command.
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 * @param line The command of AI.
 */
void command_ai_handler(app_t *app, ia_t *ai, char *line);

/**
 * @brief Handler of command who move player (Forward, Right, Left).
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 * @param line The command of AI.
 * @return true If command was find.
 * @return false If command wasn't find.
 */
bool move_command(app_t *app, ia_t *ai, char *line);

/**
 * @brief Handler of command who send object info (Look, Inventory).
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 * @param line The command of AI.
 * @return true If command was find.
 * @return false If command wasn't find.
 */
bool object_info_command(app_t *app, ia_t *ai, char *line);

/**
 * @brief Handler of other command (Connect_nbr).
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
void take_cmd(app_t *app, ia_t *ai, char *ressource);

/**
 * @brief Command set objects.
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 */
void set_cmd(app_t *app, ia_t *ai, char *ressource);

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
 * @brief Incantation of command.
 *
 * @param app Application with necessary information.
 * @param ai AI who have done a command.
 * @param line The command of AI.
 * @return true If command was find.
 * @return false If command wasn't find.
 */
bool incantation_command(app_t *app, ia_t *ai, char *line);

/**
 * @brief Check condition of incantation.
 *
 * @param app Application with necessary information.
 * @param ai AI who have launch the incantation.
 * @param status BEGIN_INCANTATION or END_INCANTATION
 * (to know if I have to verify status incantation).
 * @return NULL if failed or list of ai in incantation.
 */
list_t *check_incantation(app_t *app, ia_t *ai, int status);

/**
 * @brief Update status incantation of all participating people.
 *
 * @param app Application with necessary information.
 * @param ai AI who have launch the incantation.
 * @param update_status Status of the update.
 */
void update_status(app_t *app, ia_t *ai, int update_status);

/**
 * @brief Level up all player of incantation and delete all ressources.
 *
 * @param app Application with necessary information.
 * @param ai AI who have launch the incantation.
 */
void level_up(app_t *app, ia_t *ai);

/**
 * @brief Add a command to the list.
 *
 * @param ai Ai who do the command.
 * @param line The command to add.
 */
void add_command_to_list(ia_t *ai, char *line);

/**
 * @brief Treat command of all ai.
 *
 * @param app Application with necessary information.
 */
void treat_command(app_t *app);

/**
 * @brief Destroy the list of command.
 *
 * @param command_list List of command to destroy.
 */
void destroy_command_list(list_t *command_list);

/**
 * @brief Calcul The K number.
 *
 * @param app Application with all informations.
 * @param ai_sender IA who send the message.
 * @param ai_destination IA who received the message.
 * @return size_t The tile where hit th broadcast.
 */
size_t calcul_k(app_t *app, ia_t *ai_sender, ia_t *ai_destination);
