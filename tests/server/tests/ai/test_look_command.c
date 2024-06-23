/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Test on AI command eject
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "ai/cmd/look.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

Test(ai_command_look, look_command, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8931;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1");
    parsing->names[1] = strdup("team 2");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    node_data_t client1;
    client1.client = create_client(1);
    list_add_back(app->clients_list, client1);
    add_ia(app, 1, strdup("team 2"));
    node_data_t client2;
    client2.client = create_client(4);
    list_add_back(app->clients_list, client2);
    add_ia(app, 4, strdup("team 2"));


    ia_t *ai = find_ia(app, 1);
    ai->position->x = 0;
    ai->position->y = 0;
    ai->direction = NORTH;
    ai->level = 1;

    look_cmd(app, ai);
    cr_assert_eq(app->teams_list->first->data.team->eggs_list->first->data.egg->pos->x, 1);
    cr_assert_eq(app->teams_list->first->data.team->eggs_list->first->data.egg->pos->y, 1);
}