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

#define CODE_ERROR_MISSING_ARG -1
#define CODE_ERROR_WRONG_FLAG -2
#define CODE_ERROR_INVALID_ARG -3

#define USAGE "USAGE:\t./zappy_server -p port -x width -y height " \
                "-n name1 name2 ... -c clientsNb -f freq\n"

#include "types.h"

#include <stdbool.h>

/**
 * @brief Parse the arguments passed to the server.
 *
 * @param ac numbers of arguments passed to the server.
 * @param av arguments passed to the server.
 * @return int - -1 in case of error, 0 otherwise.
 */
int parse_arg(int ac, char **av);

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

/**
 * @brief Parse the client argument.
 *
 * @param arg argument passed to the server.
 * @param pos pointer to position of the client argument in the arguments.
 * @param parsing parsing struct for store the element.
 * @return int - the result of the parsing.
 * CODE_ERROR_MISSING_ARG if the arg is missing
 * CODE_ERROR_INVALID_ARG if the arg is invalid
 * CODE_ERROR_WRONG_FLAG if the flag is invalid
 * 0 if the arg is valid.
 */
int parse_client(char **arg, int *pos, parsing_t *parsing);

/**
 * @brief Parse the frequency argument.
 *
 * @param arg argument passed to the server.
 * @param pos pointer to position of the frequency argument in the arguments.
 * @param parsing parsing struct for store the element.
 * @return int - the result of the parsing.
 * CODE_ERROR_MISSING_ARG if the arg is missing
 * CODE_ERROR_INVALID_ARG if the arg is invalid
 * CODE_ERROR_WRONG_FLAG if the flag is invalid
 * 0 if the arg is valid.
 */
int parse_frequency(char **arg, int *pos, parsing_t *parsing);

/**
 * @brief Parse the height argument.
 *
 * @param arg argument passed to the server.
 * @param pos pointer to position of the height argument in the arguments.
 * @param parsing parsing struct for store the element.
 * @return int - the result of the parsing.
 * CODE_ERROR_MISSING_ARG if the arg is missing
 * CODE_ERROR_INVALID_ARG if the arg is invalid
 * CODE_ERROR_WRONG_FLAG if the flag is invalid
 * 0 if the arg is valid.
 */
int parse_height(char **arg, int *pos, parsing_t *parsing);

/**
 * @brief Parse the port argument.
 *
 * @param arg argument passed to the server.
 * @param pos pointer to position of the port argument in the arguments.
 * @param parsing parsing struct for store the element.
 * @return int - the result of the parsing.
 * CODE_ERROR_MISSING_ARG if the arg is missing
 * CODE_ERROR_INVALID_ARG if the arg is invalid
 * CODE_ERROR_WRONG_FLAG if the flag is invalid
 * 0 if the arg is valid.
 */
int parse_port(char **arg, int *pos, parsing_t *parsing);
