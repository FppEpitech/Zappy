/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Handle help flag.
*/

#include "rules.h"
#include "parsing.h"

#include <stdio.h>
#include <string.h>

void print_help(void)
{
    printf("USAGE:\t./zappy_server -p port -x width -y height "
    "-n name1 name2 ... -c clientsNb -f freq\n\n");
    printf("Description:\n");
    printf("\t-p port\tis the port number\n");
    printf("\t-x width\tis the width of the world\n");
    printf("\t-y height\tis the height of the world\n");
    printf("\t-n name1 name2 ...\tis the name of the teams\n");
    printf("\t-c clientsNb\tis the number of authorized clients per team\n");
    printf("\t-f freq\tis the reciprocal of time unit for execution "
    "of actions\n");
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
