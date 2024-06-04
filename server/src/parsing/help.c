/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** help
*/

#include "parsing.h"

#include <stdio.h>
#include <string.h>

static void print_help(void)
{
    printf("%s", USAGE);
    fflush(stdout);
}

int handle_help(int ac, char **av)
{
    if (ac == NB_ARGS_HELP && (strcmp(av[1], HELP_FLAG) == 0
    || strcmp(av[1], HELP_FLAG_LABEL) == 0)) {
        print_help();
        return 1;
    }
    return 0;
}
