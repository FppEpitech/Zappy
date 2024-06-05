/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Handle help flag.
*/

#include "parsing.h"
#include "rules.h"

#include <stdio.h>
#include <string.h>

static void print_help(void)
{
    printf("USAGE:\t./zappy_server -p port -x width -y height "
    "-n name1 name2 ... -c clientsNb -f freq\n");
    fflush(stdout);
}

int handle_help(int ac, char **av)
{
    if (ac == NB_ARGS_HELP && (strcmp(av[1], HELP_FLAG) == 0
    || strcmp(av[1], HELP_FLAG_LABEL) == 0)) {
        print_help();
        return CODE_HELP_SUCCESS;
    }
    return CODE_SUCCESS;
}
