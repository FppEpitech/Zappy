/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Header file for utils functions.
*/

#pragma once

#include <stdbool.h>

/**
 * @brief Parse a positive int argument.
 *
 * @param arg Argument to parse.
 * @return int - the parsed argument on success.
 * CODE_ERROR_INVALID_NUMBER otherwise.
 */
int parse_positive_int_arg(char *arg);
