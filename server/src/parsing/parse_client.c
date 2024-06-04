/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** parse_port
*/

#include <stddef.h>
#include <string.h>

#include "parsing.h"

int parse_client(char **arg, int pos)
{
    if (strcmp(arg[pos], CLIENTS_FLAG) != 0)
        return -1;
    if (arg[pos + 1] == NULL)
        return -1;
    return parse_positive_int_arg(arg[pos + 1]);
}
