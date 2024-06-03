/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** app
*/

#include "ia/ia.h"

ia_t *create_ia(int fd)
{
    ia_t *new_ia = malloc(sizeof(ia_t));

    if (new_ia == NULL)
        return NULL;
    new_ia->fd = fd;
    new_ia->level = 0;
    new_ia->have_team = false;
    return new_ia;
}
