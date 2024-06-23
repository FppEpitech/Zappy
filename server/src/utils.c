/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** utils
*/

#include "rules.h"

#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

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

double time_elapsed(struct timeval *time)
{
    struct timeval end;
    double seconds = 0.0;
    double microseconds = 0.0;

    gettimeofday(&end, NULL);
    seconds = (end.tv_sec - time->tv_sec);
    microseconds = (end.tv_usec - time->tv_usec) / 1000000.0;
    return seconds + microseconds;
}
