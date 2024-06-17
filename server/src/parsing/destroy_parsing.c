/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Parse all arguments given to the server.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include "rules.h"
#include "parsing.h"

void destroy_parsing(parsing_t *parsing)
{
    free(parsing->names);
    free(parsing);
}
