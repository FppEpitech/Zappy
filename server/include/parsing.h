/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** parsing
*/

#pragma once

#define HELP_FLAG_LABEL "--help"
#define HELP_FLAG "-h"
#define PORT_FLAG "-p"
#define WIDTH_FLAG "-x"
#define HEIGHT_FLAG "-y"
#define TEAMS_NAMES_FLAG "-n"
#define CLIENTS_FLAG "-c"
#define FREQUENCY_FLAG "-f"

#define NB_ARGS_MIN 13
#define NB_ARGS_HELP 2

#define USAGE "USAGE:\t./zappy_server -p port -x width -y height " \
                "-n name1 name2 ... -c clientsNb -f freq\n"

/**
 * @brief check if the help flag is present
 *
 * @param ac numbers of arguments passed to the server.
 * @param av arguments passed to the server.
 * @return int
 */
int handle_help(int ac, char **av);

/**
 * @brief parse a positive int argument.
 *
 * @param arg argument to parse.
 * @return int - the parsed argument, -1 if the argument is not a positive int.
 */
int parse_positive_int_arg(char *arg);
