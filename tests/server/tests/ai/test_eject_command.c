/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Test on AI command eject
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "ai/cmd/command_ai.h"
#include "server/client.h"

Test(ai_command_eject, eject_command_egg, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8914;
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

    app->teams_list->first->data.team->eggs_list->first->data.egg->pos->x = 0;
    app->teams_list->first->data.team->eggs_list->first->data.egg->pos->y = 0;

    app->teams_list->first->data.team->eggs_list->first->next->data.egg->pos->x = 1;
    app->teams_list->first->data.team->eggs_list->first->next->data.egg->pos->y = 1;

    ia_t *ai = find_ia(app, 1);
    ai->position->x = 0;
    ai->position->y = 0;

    eject_cmd(app, ai);
    cr_assert_eq(app->teams_list->first->data.team->eggs_list->first->data.egg->pos->x, 1);
    cr_assert_eq(app->teams_list->first->data.team->eggs_list->first->data.egg->pos->y, 1);
}

Test(ai_command_eject, eject_command_player_NORTH_NORTH, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8915;
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

    ia_t *ai_eject = find_ia(app, 1);
    ai_eject->position->x = 0;
    ai_eject->position->y = 0;
    ai_eject->direction = NORTH;

    ia_t *ai_ejected = find_ia(app, 4);
    ai_ejected->position->x = 0;
    ai_ejected->position->y = 0;
    ai_ejected->direction = NORTH;

    eject_cmd(app, ai_eject);
    cr_assert_eq(ai_ejected->position->x, 0);
    cr_assert_eq(ai_ejected->position->y, 9);
}

Test(ai_command_eject, eject_command_player_NORTH_EAST, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8916;
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

    ia_t *ai_eject = find_ia(app, 1);
    ai_eject->position->x = 0;
    ai_eject->position->y = 0;
    ai_eject->direction = NORTH;

    ia_t *ai_ejected = find_ia(app, 4);
    ai_ejected->position->x = 0;
    ai_ejected->position->y = 0;
    ai_ejected->direction = EAST;

    eject_cmd(app, ai_eject);
    cr_assert_eq(ai_ejected->position->x, 0);
    cr_assert_eq(ai_ejected->position->y, 9);
}

Test(ai_command_eject, eject_command_player_NORTH_SOUTH, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8917;
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

    ia_t *ai_eject = find_ia(app, 1);
    ai_eject->position->x = 0;
    ai_eject->position->y = 0;
    ai_eject->direction = NORTH;

    ia_t *ai_ejected = find_ia(app, 4);
    ai_ejected->position->x = 0;
    ai_ejected->position->y = 0;
    ai_ejected->direction = SOUTH;

    eject_cmd(app, ai_eject);
    cr_assert_eq(ai_ejected->position->x, 0);
    cr_assert_eq(ai_ejected->position->y, 9);
}

Test(ai_command_eject, eject_command_player_NORTH_WEST, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8918;
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

    ia_t *ai_eject = find_ia(app, 1);
    ai_eject->position->x = 0;
    ai_eject->position->y = 0;
    ai_eject->direction = NORTH;

    ia_t *ai_ejected = find_ia(app, 4);
    ai_ejected->position->x = 0;
    ai_ejected->position->y = 0;
    ai_ejected->direction = WEST;

    eject_cmd(app, ai_eject);
    cr_assert_eq(ai_ejected->position->x, 0);
    cr_assert_eq(ai_ejected->position->y, 9);
}

Test(ai_command_eject, eject_command_player_EAST_NORTH, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8919;
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

    ia_t *ai_eject = find_ia(app, 1);
    ai_eject->position->x = 0;
    ai_eject->position->y = 0;
    ai_eject->direction = EAST;

    ia_t *ai_ejected = find_ia(app, 4);
    ai_ejected->position->x = 0;
    ai_ejected->position->y = 0;
    ai_ejected->direction = NORTH;

    eject_cmd(app, ai_eject);
    cr_assert_eq(ai_ejected->position->x, 1);
    cr_assert_eq(ai_ejected->position->y, 0);
}

Test(ai_command_eject, eject_command_player_EAST_EAST, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8920;
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

    ia_t *ai_eject = find_ia(app, 1);
    ai_eject->position->x = 0;
    ai_eject->position->y = 0;
    ai_eject->direction = EAST;

    ia_t *ai_ejected = find_ia(app, 4);
    ai_ejected->position->x = 0;
    ai_ejected->position->y = 0;
    ai_ejected->direction = EAST;

    eject_cmd(app, ai_eject);
    cr_assert_eq(ai_ejected->position->x, 1);
    cr_assert_eq(ai_ejected->position->y, 0);
}

Test(ai_command_eject, eject_command_player_EAST_SOUTH, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8921;
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

    ia_t *ai_eject = find_ia(app, 1);
    ai_eject->position->x = 0;
    ai_eject->position->y = 0;
    ai_eject->direction = EAST;

    ia_t *ai_ejected = find_ia(app, 4);
    ai_ejected->position->x = 0;
    ai_ejected->position->y = 0;
    ai_ejected->direction = SOUTH;

    eject_cmd(app, ai_eject);
    cr_assert_eq(ai_ejected->position->x, 1);
    cr_assert_eq(ai_ejected->position->y, 0);
}

Test(ai_command_eject, eject_command_player_EAST_WEST, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8922;
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

    ia_t *ai_eject = find_ia(app, 1);
    ai_eject->position->x = 0;
    ai_eject->position->y = 0;
    ai_eject->direction = EAST;

    ia_t *ai_ejected = find_ia(app, 4);
    ai_ejected->position->x = 0;
    ai_ejected->position->y = 0;
    ai_ejected->direction = WEST;

    eject_cmd(app, ai_eject);
    cr_assert_eq(ai_ejected->position->x, 1);
    cr_assert_eq(ai_ejected->position->y, 0);
}

Test(ai_command_eject, eject_command_player_SOUTH_NORTH, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8923;
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

    ia_t *ai_eject = find_ia(app, 1);
    ai_eject->position->x = 0;
    ai_eject->position->y = 0;
    ai_eject->direction = SOUTH;

    ia_t *ai_ejected = find_ia(app, 4);
    ai_ejected->position->x = 0;
    ai_ejected->position->y = 0;
    ai_ejected->direction = NORTH;

    eject_cmd(app, ai_eject);
    cr_assert_eq(ai_ejected->position->x, 0);
    cr_assert_eq(ai_ejected->position->y, 1);
}

Test(ai_command_eject, eject_command_player_SOUTH_EAST, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8924;
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

    ia_t *ai_eject = find_ia(app, 1);
    ai_eject->position->x = 0;
    ai_eject->position->y = 0;
    ai_eject->direction = SOUTH;

    ia_t *ai_ejected = find_ia(app, 4);
    ai_ejected->position->x = 0;
    ai_ejected->position->y = 0;
    ai_ejected->direction = EAST;

    eject_cmd(app, ai_eject);
    cr_assert_eq(ai_ejected->position->x, 0);
    cr_assert_eq(ai_ejected->position->y, 1);
}

Test(ai_command_eject, eject_command_player_SOUTH_SOUTH, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8925;
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

    ia_t *ai_eject = find_ia(app, 1);
    ai_eject->position->x = 0;
    ai_eject->position->y = 0;
    ai_eject->direction = SOUTH;

    ia_t *ai_ejected = find_ia(app, 4);
    ai_ejected->position->x = 0;
    ai_ejected->position->y = 0;
    ai_ejected->direction = SOUTH;

    eject_cmd(app, ai_eject);
    cr_assert_eq(ai_ejected->position->x, 0);
    cr_assert_eq(ai_ejected->position->y, 1);
}

Test(ai_command_eject, eject_command_player_SOUTH_WEST, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8926;
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

    ia_t *ai_eject = find_ia(app, 1);
    ai_eject->position->x = 0;
    ai_eject->position->y = 0;
    ai_eject->direction = SOUTH;

    ia_t *ai_ejected = find_ia(app, 4);
    ai_ejected->position->x = 0;
    ai_ejected->position->y = 0;
    ai_ejected->direction = WEST;

    eject_cmd(app, ai_eject);
    cr_assert_eq(ai_ejected->position->x, 0);
    cr_assert_eq(ai_ejected->position->y, 1);
}

Test(ai_command_eject, eject_command_player_WEST_NORTH, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8927;
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

    ia_t *ai_eject = find_ia(app, 1);
    ai_eject->position->x = 0;
    ai_eject->position->y = 0;
    ai_eject->direction = WEST;

    ia_t *ai_ejected = find_ia(app, 4);
    ai_ejected->position->x = 0;
    ai_ejected->position->y = 0;
    ai_ejected->direction = NORTH;

    eject_cmd(app, ai_eject);
    cr_assert_eq(ai_ejected->position->x, 14);
    cr_assert_eq(ai_ejected->position->y, 0);
}

Test(ai_command_eject, eject_command_player_WEST_EAST, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8928;
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

    ia_t *ai_eject = find_ia(app, 1);
    ai_eject->position->x = 0;
    ai_eject->position->y = 0;
    ai_eject->direction = WEST;

    ia_t *ai_ejected = find_ia(app, 4);
    ai_ejected->position->x = 0;
    ai_ejected->position->y = 0;
    ai_ejected->direction = EAST;

    eject_cmd(app, ai_eject);
    cr_assert_eq(ai_ejected->position->x, 14);
    cr_assert_eq(ai_ejected->position->y, 0);
}

Test(ai_command_eject, eject_command_player_WEST_SOUTH, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8929;
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

    ia_t *ai_eject = find_ia(app, 1);
    ai_eject->position->x = 0;
    ai_eject->position->y = 0;
    ai_eject->direction = WEST;

    ia_t *ai_ejected = find_ia(app, 4);
    ai_ejected->position->x = 0;
    ai_ejected->position->y = 0;
    ai_ejected->direction = SOUTH;

    eject_cmd(app, ai_eject);
    cr_assert_eq(ai_ejected->position->x, 14);
    cr_assert_eq(ai_ejected->position->y, 0);
}

Test(ai_command_eject, eject_command_player_WEST_WEST, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8930;
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

    ia_t *ai_eject = find_ia(app, 1);
    ai_eject->position->x = 0;
    ai_eject->position->y = 0;
    ai_eject->direction = WEST;

    ia_t *ai_ejected = find_ia(app, 4);
    ai_ejected->position->x = 0;
    ai_ejected->position->y = 0;
    ai_ejected->direction = WEST;

    eject_cmd(app, ai_eject);
    cr_assert_eq(ai_ejected->position->x, 14);
    cr_assert_eq(ai_ejected->position->y, 0);
}
