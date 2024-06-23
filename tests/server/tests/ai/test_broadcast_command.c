/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Test on AI command broadcast
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "ai/cmd/command_ai.h"
#include "server/client.h"

Test(ai_command_broadcast, wrong_broadcast_command, .timeout = 5)
{
    app_t app;
    ia_t ai;

    bool result = broadcast_command(&app, &ai, "WRONG");
    cr_assert_eq(result, false);
}

Test(ai_command_broadcast, broadcast_command, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8888;
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


    bool result = broadcast_command(app, ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_same_pos, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8889;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 4;
    receive_ai->position->y = 4;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_NORTH_up, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8890;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 4;
    receive_ai->position->y = 3;
    receive_ai->direction = NORTH;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_NORTH_right, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8891;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 5;
    receive_ai->position->y = 4;
    receive_ai->direction = NORTH;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_NORTH_bottom, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8892;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 4;
    receive_ai->position->y = 5;
    receive_ai->direction = NORTH;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_NORTH_left, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8893;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 3;
    receive_ai->position->y = 4;
    receive_ai->direction = NORTH;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_EAST_up, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8894;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 4;
    receive_ai->position->y = 3;
    receive_ai->direction = EAST;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_EAST_right, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8895;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 5;
    receive_ai->position->y = 4;
    receive_ai->direction = EAST;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_EAST_bottom, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8896;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 4;
    receive_ai->position->y = 5;
    receive_ai->direction = EAST;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_EAST_left, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8897;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 3;
    receive_ai->position->y = 4;
    receive_ai->direction = EAST;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_SOUTH_up, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8898;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 4;
    receive_ai->position->y = 3;
    receive_ai->direction = SOUTH;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_SOUTH_right, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8899;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 5;
    receive_ai->position->y = 4;
    receive_ai->direction = SOUTH;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_SOUTH_bottom, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8900;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 4;
    receive_ai->position->y = 5;
    receive_ai->direction = SOUTH;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_SOUTH_left, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8901;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 3;
    receive_ai->position->y = 4;
    receive_ai->direction = SOUTH;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_WEST_up, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8902;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 4;
    receive_ai->position->y = 3;
    receive_ai->direction = WEST;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_WEST_right, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8903;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 5;
    receive_ai->position->y = 4;
    receive_ai->direction = WEST;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_WEST_bottom, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8904;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 4;
    receive_ai->position->y = 5;
    receive_ai->direction = WEST;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_WEST_left, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8905;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 3;
    receive_ai->position->y = 4;
    receive_ai->direction = WEST;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_NORTH_left_up, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8906;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 0;
    receive_ai->position->y = 0;
    receive_ai->direction = NORTH;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_EAST_left_up, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8907;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 0;
    receive_ai->position->y = 0;
    receive_ai->direction = EAST;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_SOUTH_left_up, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8908;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 0;
    receive_ai->position->y = 0;
    receive_ai->direction = SOUTH;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_WEST_left_up, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8909;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 0;
    receive_ai->position->y = 0;
    receive_ai->direction = WEST;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_NORTH_right_up, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8910;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 9;
    receive_ai->position->y = 0;
    receive_ai->direction = NORTH;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_EAST_right_up, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8911;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 9;
    receive_ai->position->y = 0;
    receive_ai->direction = EAST;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_SOUTH_right_up, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8912;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 9;
    receive_ai->position->y = 0;
    receive_ai->direction = SOUTH;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}

Test(ai_command_broadcast, receive_orientation_WEST_right_up, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 8913;
    parsing->height = 10;
    parsing->width = 10;
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

    ia_t *sender_ai = find_ia(app, 1);
    sender_ai->position->x = 4;
    sender_ai->position->y = 4;

    ia_t *receive_ai = find_ia(app, 4);
    receive_ai->position->x = 9;
    receive_ai->position->y = 0;
    receive_ai->direction = WEST;


    bool result = broadcast_command(app, sender_ai, "Broadcast ");
    cr_assert_eq(result, true);
}
