/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** utils
*/

#include "rules.h"

#include <stdlib.h>
#include <stdbool.h>

static bool is_str_number(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '\r')
            continue;
        if (str[i] == '\n' && str[i - 1] == '\r')
            return true;
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

int parse_positive_int_arg(char *arg)
{
    if (!is_str_number(arg))
        return CODE_ERROR_INVALID_NUMBER;
    return atoi(arg);
}
