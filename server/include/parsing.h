/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Header file for parsing the arguments passed to the server.
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

#include "types.h"

#include <stdbool.h>

/**
 * @brief Parse the arguments passed to the server.
 *
 * @param ac Numbers of arguments passed to the server.
 * @param av Arguments passed to the server.
 * @return parsing_t - NULL in case of error, the structure otherwise.
 */
parsing_t *parse_arg(int ac, char **av);

/**
 * @brief Check if the help flag is present.
 *
 * @param ac Numbers of arguments passed to the server.
 * @param av Arguments passed to the server.
 * @return int - The result of the parsing.
 * CODE_HELP_SUCCESS if the help flag is present.
 * CODE_SUCCESS if the help flag is not present.
 */
int handle_help(int ac, char **av);

/**
 * @brief Parse a positive int argument.
 *
 * @param arg Argument to parse.
 * @return int - the parsed argument on success.
 * CODE_ERROR_INVALID_NUMBER otherwise.
 */
int parse_positive_int_arg(char *arg);

/**
 * @brief Parse the client argument.
 *
 * @param arg Argument passed to the server.
 * @param pos Pointer to position of the client argument in the arguments.
 * @param parsing Parsing struct for store the element.
 * @return int - The result of the parsing.
 * CODE_ERROR_MISSING_ARG if the arg is missing.
 * CODE_ERROR_INVALID_ARG if the arg is invalid.
 * CODE_ERROR_WRONG_FLAG if the flag is invalid.
 * 0 if the arg is valid.
 */
int parse_client(char **arg, int *pos, parsing_t *parsing);

/**
 * @brief Parse the frequency argument.
 *
 * @param arg Argument passed to the server.
 * @param pos Pointer to position of the frequency argument in the arguments.
 * @param parsing Parsing struct for store the element.
 * @return int - the result of the parsing.
 * CODE_ERROR_MISSING_ARG if the arg is missing.
 * CODE_ERROR_INVALID_ARG if the arg is invalid.
 * CODE_ERROR_WRONG_FLAG if the flag is invalid.
 * 0 if the arg is valid.
 */
int parse_frequency(char **arg, int *pos, parsing_t *parsing);

/**
 * @brief Parse the height argument.
 *
 * @param arg Argument passed to the server.
 * @param pos Pointer to position of the height argument in the arguments.
 * @param parsing Parsing struct for store the element.
 * @return int - the result of the parsing.
 * CODE_ERROR_MISSING_ARG if the arg is missing.
 * CODE_ERROR_INVALID_ARG if the arg is invalid.
 * CODE_ERROR_WRONG_FLAG if the flag is invalid.
 * 0 if the arg is valid.
 */
int parse_height(char **arg, int *pos, parsing_t *parsing);

/**
 * @brief Parse the port argument.
 *
 * @param arg Argument passed to the server.
 * @param pos Pointer to position of the port argument in the arguments.
 * @param parsing Parsing struct for store the element.
 * @return int - The result of the parsing.
 * CODE_ERROR_MISSING_ARG if the arg is missing.
 * CODE_ERROR_INVALID_ARG if the arg is invalid.
 * CODE_ERROR_WRONG_FLAG if the flag is invalid.
 * 0 if the arg is valid.
 */
int parse_port(char **arg, int *pos, parsing_t *parsing);

/**
 * @brief Parse the width argument.
 *
 * @param arg Argument passed to the server.
 * @param pos Pointer to position of the width argument in the arguments.
 * @param parsing Parsing struct for store the element.
 * @return int - The result of the parsing.
 * CODE_ERROR_MISSING_ARG if the arg is missing.
 * CODE_ERROR_INVALID_ARG if the arg is invalid.
 * CODE_ERROR_WRONG_FLAG if the flag is invalid.
 * 0 if the arg is valid.
 */
int parse_width(char **arg, int *pos, parsing_t *parsing);

/**
 * @brief Parse the names argument.
 *
 * @param arg Argument passed to the server.
 * @param pos Pointer to position of the names argument in the arguments.
 * @param parsing Parsing struct for store the element.
 * @return int - The result of the parsing.
 * CODE_ERROR_MISSING_ARG if the arg is missing.
 * CODE_ERROR_WRONG_FLAG if the flag is invalid.
 * CODE_ERROR_MALLOC_FAILEd if any malloc failed.
 * 0 if the arg is valid.
 */
int parse_names(char **arg, int *pos, parsing_t *parsing);

/**
 * @brief Destroy the parsing struct.
 *
 * @param parsing Parsing struct to destroy.
 */
void destroy_parsing(parsing_t *parsing);
