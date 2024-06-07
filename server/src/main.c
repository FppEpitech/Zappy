/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** main
*/

#include <stdio.h>
#include <string.h>

#include "app/app.h"
#include "ai/team.h"
#include "parsing.h"
#include "map/map.h"

int main(int ac, char **av)
{
    parsing_t *parsing = parse_arg(ac, av);
    app_t *app = NULL;
    tile_t **map = NULL;

    if (!parsing)
        return 84;
    map = get_map(parsing->width, parsing->height);
    display_map(map, 2, 2);
    free_map(map, 2);
    printf("Port: %d\n", parsing->port);
    printf("Width: %d, Height: %d\n", parsing->width, parsing->height);
    printf("ClientsNb: %d, Freq: %d\n", parsing->clientsNb, parsing->freq);
    for (int i = 0; parsing->names[i]; i++)
        printf("Name %d: %s\n", i, parsing->names[i]);
    app = create_app(parsing);
    if (app == NULL)
        return 84;
    server_run(app);
    destroy_app(app);
    return 0;
}
