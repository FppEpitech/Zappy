/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** parse_name
*/

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "rules.h"
#include "types.h"
#include "parsing.h"

static int get_size_names(char **arg, int pos)
{
    int i = pos + 1;

    while (1) {
        if (arg[i] == NULL || arg[i][0] == '-')
            break;
        i++;
    }
    return i - pos;
}

static bool fill_names(char **arg, int pos, parsing_t *parsing)
{
    int i = 0;

    for (int j = 0; j < pos; j++) {
        parsing->names[j] = strdup(arg[j]);
        if (parsing->names[j] == NULL) {
            dprintf(2, "Error: strdup failed\n");
            return false;
        }
    }
    return true;
}

int parse_names(char **arg, int *pos, parsing_t *parsing)
{
    int i = 0;

    if (strcmp(arg[*pos], TEAMS_NAMES_FLAG) != 0)
        return CODE_ERROR_WRONG_FLAG;
    if (arg[*pos + 1] == NULL) {
        dprintf(2, "Error: missing argument for -n\n");
        return CODE_ERROR_MISSING_ARG;
    }
    i = get_size_names(arg, i);
    parsing->names = malloc(sizeof(char *) * (i - *pos) + 1);
    if (parsing->names == NULL) {
        dprintf(2, "Error: malloc failed\n");
        return CODE_ERROR_MALLOC_FAILED;
    }
    if (!fill_names(arg, i, parsing))
        return CODE_ERROR_MALLOC_FAILED;
    *pos = i;
    return CODE_SUCCESS;
}
