/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** argument
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "parsing.h"

static int check_one_parameter(int *pos, char **av, parsing_t *parsing)
{
    int result = -2;

    printf("pos: %d\n", *pos);
    result = parse_client(av, pos, parsing);
    if (result == CODE_ERROR_MISSING_ARG || result == CODE_ERROR_INVALID_ARG)
        return -1;
    printf("result: %d\n", result);
    dprintf(2, "Error: wrong flag\n");
    return result;
}

static int check_all_parameters(int ac, char **av, parsing_t *parsing)
{
    int pos = 1;
    int nb_args = 0;
    int result = 0;

    while (1) {
        if (pos >= ac)
            break;
        result = check_one_parameter(&pos, av, parsing);
        if (result == -2 || result == -1)
            return -1;
    }
    return 0;
}

int parse_arg(int ac, char **av)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    if (parsing == NULL) {
        printf("Error: malloc failed\n");
        return -1;
    }
    if (handle_help(ac, av) == 1)
        return 0;
    if (ac < NB_ARGS_MIN) {
        printf("Error: not enough arguments\n");
        return -1;
    }
    return check_all_parameters(ac, av, parsing);
}
