/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** parse_port
*/

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "parsing.h"
#include "rules.h"
#include "types.h"

int parse_client(char **arg, int *pos, parsing_t *parsing)
{
    int result = 0;

    if (strcmp(arg[*pos], CLIENTS_FLAG) != 0)
        return CODE_ERROR_WRONG_FLAG;
    if (arg[*pos + 1] == NULL) {
        dprintf(2, "Error: missing argument for -c\n");
        return CODE_ERROR_MISSING_ARG;
    }
    result = parse_positive_int_arg(arg[*pos + 1]);
    if (result == CODE_ERROR_INVALID_NUMBER) {
        dprintf(2, "Error: invalid argument for -c, "
            "must be a positive value\n");
        return CODE_ERROR_INVALID_ARG;
    }
    (*pos) += 2;
    parsing->clientsNb = result;
    return 0;
}
