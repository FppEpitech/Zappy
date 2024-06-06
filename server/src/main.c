/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** main
*/

#include <stdio.h>

#include "parsing.h"

#include "list/list.h"

int main(int ac, char **av)
{
    parsing_t *parsing = parse_arg(ac, av);
    list_t ***map; //must alloc
    list_t *players = list_new();



    if (!parsing)
        return 84;
    printf("Port: %d\n", parsing->port);
    printf("Width: %d\n", parsing->width);
    printf("Height: %d\n", parsing->height);
    printf("ClientsNb: %d\n", parsing->clientsNb);
    printf("Freq: %d\n", parsing->freq);
    for (int i = 0; parsing->names[i]; i++)
        printf("Name %d: %s\n", i, parsing->names[i]);
    return 0;
}
