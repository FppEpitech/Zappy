/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** main
*/

#include <stdio.h>
#include <string.h>

#include "app/app.h"

static void print_info_server(parsing_t *parsing)
{
    printf("----------------INFO SERVER----------------\n");
    printf("Port: %d\n", parsing->port);
    printf("Width: %d, Height: %d\n", parsing->width, parsing->height);
    printf("ClientsNb: %d\n", parsing->clientsNb);
    printf("Frequency: %d\n", parsing->freq);
    for (int i = 0; parsing->names[i]; i++)
        printf("Name %d: %s\n", i, parsing->names[i]);
    printf("--------------END INFO SERVER--------------\n");
}

int main(int ac, char **av)
{
    parsing_t *parsing = parse_arg(ac, av);
    app_t *app = NULL;

    if (!parsing)
        return 84;
    print_info_server(parsing);
    srand(time(NULL));
    app = create_app(parsing);
    if (app == NULL) {
        print_help();
        return 84;
    }
    if (!server_run(app))
        return 84;
    destroy_app(app);
    destroy_parsing(parsing);
    return 0;
}
