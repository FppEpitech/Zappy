/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** ia
*/

#include "ia/ia.h"

ia_t *create_ia(int fd)
{
    ia_t *new_ia = malloc(sizeof(ia_t));

    if (new_ia == NULL)
        return NULL;
    new_ia->fd = fd;
    new_ia->level = 0;
    return new_ia;
}
