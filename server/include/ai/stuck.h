/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Game struct
*/

#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

#include "list/list.h"

typedef struct s_app app_t;

/**
 * @brief Calcul time elapsed whereas time parameter.
 *
 * @param time Time of depart.
 * @return double Time.
 */
double time_elapsed(struct timeval *time);

/**
 * @brief Set the time stuck object.
 *
 * @param ai Ai to stuck.
 * @param total_stuck The total time stuck.
 */
void set_time_stuck(ia_t *ai, double total_stuck);

/**
 * @brief Check if an AI have to be unstuck.
 *
 * @param app Application with list of AI.
 */
void treat_stuck(app_t *app);
