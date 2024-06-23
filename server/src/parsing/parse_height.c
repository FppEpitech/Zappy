/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Parse height argument for the server
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
    if (result < 10 || result > 30) {
        dprintf(2, "Value must be between 10 and 30\n");
        return CODE_ERROR_INVALID_ARG;
    }
    return CODE_SUCCESS;
}

int parse_height(char **arg, int *pos, parsing_t *parsing)
{
    int result = 0;

    if (strcmp(arg[*pos], HEIGHT_FLAG) != 0)
        return CODE_ERROR_WRONG_FLAG;
    if (arg[*pos + 1] == NULL) {
        dprintf(2, "Error: missing argument for -y\n");
        return CODE_ERROR_MISSING_ARG;
    }
    result = parse_positive_int_arg(arg[*pos + 1]);
    if (result == CODE_ERROR_INVALID_NUMBER) {
        dprintf(2, "Error: invalid argument for -y, "
        "must be a positive value\n");
        return CODE_ERROR_INVALID_ARG;
    }
    (*pos) += 2;
    if (check_size(result) == CODE_ERROR_INVALID_ARG)
        return CODE_ERROR_INVALID_ARG;
    parsing->height = result;
    return CODE_SUCCESS;
}
