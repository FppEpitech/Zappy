/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Header file for utils functions.
*/

#pragma once

#include <stdbool.h>
#include <sys/time.h>

/**
 * @brief Parse a positive int argument.
 *
 * @param arg Argument to parse.
 * @return int - the parsed argument on success.
 * CODE_ERROR_INVALID_NUMBER otherwise.
 */
int parse_positive_int_arg(char *arg);

/**
 * @brief Calcul time elapsed whereas time parameter.
 *
 * @param time Time of depart.
 * @return double Time.
 */
double time_elapsed(struct timeval *time);
