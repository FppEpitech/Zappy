/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Parse frequency argument for the server
*/

#include "rules.h"
#include "types.h"
#include "parsing.h"

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

static int check_size(int result)
{
    if (result > 800) {
        dprintf(2, "Frequence must be below of 801\n");
        return CODE_ERROR_INVALID_ARG;
    }
    return CODE_SUCCESS;
}

int parse_frequency(char **arg, int *pos, parsing_t *parsing)
{
    int result = 0;

    if (strcmp(arg[*pos], FREQUENCY_FLAG) != 0)
        return CODE_ERROR_WRONG_FLAG;
    if (arg[*pos + 1] == NULL) {
        dprintf(2, "Error: missing argument for -f\n");
        return CODE_ERROR_MISSING_ARG;
    }
    result = parse_positive_int_arg(arg[*pos + 1]);
    if (result == CODE_ERROR_INVALID_NUMBER) {
        dprintf(2, "Error: invalid argument for -f, "
            "must be a positive value\n");
        return CODE_ERROR_INVALID_ARG;
    }
    if (check_size(result) == CODE_ERROR_INVALID_ARG)
        return CODE_ERROR_INVALID_ARG;
    (*pos) += 2;
    parsing->freq = result;
    return CODE_SUCCESS;
}
