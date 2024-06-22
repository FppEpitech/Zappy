/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Parse all arguments given to the server.
*/

#include "rules.h"
#include "parsing.h"

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

static int (*parse_args[])(char **arg, int *pos, parsing_t *parsing) = {
    &parse_port,
    &parse_width,
    &parse_height,
    &parse_names,
    &parse_client,
    &parse_frequency,
    NULL
};

static parsing_t *init_parsing(void)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    if (parsing == NULL) {
        dprintf(2, "Error: malloc failed\n");
        return NULL;
    }
    parsing->clientsNb = -1;
    parsing->port = -1;
    parsing->width = -1;
    parsing->height = -1;
    parsing->freq = -1;
    parsing->names = NULL;
    return parsing;
}

static int check_one_parameter(int *pos, char **av, parsing_t *parsing)
{
    int result = 0;
    int i = 0;

    while (parse_args[i] != NULL) {
        result = parse_args[i](av, pos, parsing);
        if (result != CODE_ERROR_WRONG_FLAG)
            return result;
        i++;
    }
    return CODE_ERROR_WRONG_FLAG;
}

static bool is_all_parameters_parsed(parsing_t *parsing)
{
    if (parsing->clientsNb == -1 || parsing->port == -1 || parsing->width == -1
        || parsing->height == -1 || parsing->freq == -1
        || parsing->names == NULL)
        return false;
    return true;
}

static int check_all_parameters(int ac, char **av, parsing_t *parsing)
{
    int pos = 1;
    int result = 0;

    while (pos < ac) {
        result = check_one_parameter(&pos, av, parsing);
        if (result == CODE_ERROR_MISSING_ARG ||
                result == CODE_ERROR_INVALID_ARG ||
                result == CODE_ERROR_MALLOC_FAILED)
            return CODE_FAILLURE;
        if (result == CODE_ERROR_WRONG_FLAG) {
            dprintf(2, "Error: missing argument\n");
            return CODE_FAILLURE;
        }
    }
    if (!is_all_parameters_parsed(parsing)) {
        dprintf(2, "Error: missing argument\n");
        return CODE_FAILLURE;
    }
    return CODE_SUCCESS;
}

parsing_t *parse_arg(int ac, char **av)
{
    parsing_t *parsing = init_parsing();

    if (parsing == NULL)
        return NULL;
    if (handle_help(ac, av) == 1)
        return 0;
    if (ac < NB_ARGS_MIN) {
        dprintf(2, "Error: not enough arguments\n");
        print_help();
        return NULL;
    }
    if (check_all_parameters(ac, av, parsing) == CODE_FAILLURE) {
        print_help();
        return NULL;
    }
    return parsing;
}
