/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Parse port argument for the server
*/

#include "rules.h"
#include "types.h"
#include "parsing.h"

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

int parse_port(char **arg, int *pos, parsing_t *parsing)
{
    int result = 0;

    if (strcmp(arg[*pos], PORT_FLAG) != 0)
        return CODE_ERROR_WRONG_FLAG;
    if (arg[*pos + 1] == NULL) {
        dprintf(2, "Error: missing argument for -p\n");
        return CODE_ERROR_MISSING_ARG;
    }
    result = parse_positive_int_arg(arg[*pos + 1]);
    if (result == CODE_ERROR_INVALID_NUMBER) {
        dprintf(2, "Error: invalid argument for -p, "
            "must be a positive value\n");
        return CODE_ERROR_INVALID_ARG;
    }
    (*pos) += 2;
    parsing->port = result;
    return CODE_SUCCESS;
}
