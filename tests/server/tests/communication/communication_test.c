/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Test on list
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "server/client.h"

Test(communication, create_app, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4443;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 2);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = NULL;

    app_t *app = create_app(parsing);

    cr_assert_not_null(app);
    destroy_app(app);
}


Test(communication, add_ia, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4446;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 1;
    parsing->names = malloc(sizeof(char *) * 2);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = NULL;
    app_t *app = create_app(parsing);

    cr_assert_not_null(app);
    node_data_t data1;
    data1.client = create_client(1);
    list_add_back(app->clients_list, data1);
    add_ia(app, 1, strdup("team 1\r"));

    cr_assert_not_null(app->teams_list->first->data.team->list_ai->first);
    destroy_app(app);
}

Test(communication, reset_fd, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4447;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 2);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = NULL;
    app_t *app = create_app(parsing);

    cr_assert_not_null(app);
    node_data_t data;
    data.team = create_team(app, strdup("team 1\r"), 1);
    list_add_front(app->teams_list, data);
    node_data_t data1;
    data1.client = create_client(1);
    list_add_back(app->clients_list, data1);
    add_ia(app, 1, strdup("team 1\r"));
    server_reset_fd(app);
    destroy_app(app);
}

Test(communication, add_ia_in_team, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4448;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 2);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = NULL;
    app_t *app = create_app(parsing);

    cr_assert_not_null(app);
    node_data_t data;
    data.team = create_team(app, strdup("team 1\r"), 1);
    list_add_front(app->teams_list, data);
    node_data_t data1;
    data1.client = create_client(1);
    list_add_back(app->clients_list, data1);
    add_ia(app, 1, strdup("team 1\r"));


    cr_assert_not_null(find_ia(app, 1));
    destroy_app(app);
}

Test(communication, add_ia_with_multiple_team, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4449;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 1;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    node_data_t data;
    data.team = create_team(app, strdup("team 1\r"), 1);
    cr_assert_not_null(data.team);
    list_add_front(app->teams_list, data);
    node_data_t data1;
    data1.client = create_client(1);
    cr_assert_not_null(data1.client);
    list_add_back(app->clients_list, data1);
    add_ia(app, 1, strdup("team 1\r"));

    data.team = create_team(app, strdup("team 2\r"), 1);
    list_add_front(app->teams_list, data);
    node_data_t data4;
    data4.client = create_client(4);
    list_add_back(app->clients_list, data4);
    add_ia(app, 4, strdup("team 2\r"));
    destroy_app(app);
}

Test(communication, add_ia_in_no_existing_team, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4450;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);

    cr_assert_not_null(app);
    node_data_t data;
    data.team = create_team(app, strdup("team 1\r"), 1);
    list_add_front(app->teams_list, data);
    node_data_t data1;
    data1.client = create_client(1);
    list_add_back(app->clients_list, data1);
    add_ia(app, 1, strdup("team\r"));

    destroy_app(app);
}

Test(communication, dont_find_ia, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4451;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);

    cr_assert_not_null(app);
    node_data_t data;
    data.team = create_team(app, strdup("team 1\r"), 1);
    list_add_front(app->teams_list, data);
    node_data_t data1;
    data1.client = create_client(1);
    list_add_back(app->clients_list, data1);
    add_ia(app, 1, strdup("team 1\r"));


    cr_assert_null(find_ia(app, 2));
    destroy_app(app);
}

Test(communication, add_gui, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4452;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);

    cr_assert_not_null(app);
    node_data_t data;
    data.client = create_client(1);
    list_add_back(app->clients_list, data);
    node_data_t data1;
    data1.client = create_client(1);
    list_add_back(app->clients_list, data1);
    add_gui(app, 1, strdup("TEST\n"));

    cr_assert_not_null(app->gui_list->first);
    destroy_app(app);
}

Test(communication, find_gui, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4453;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);

    cr_assert_not_null(app);
    node_data_t data;
    data.client = create_client(1);
    list_add_back(app->clients_list, data);
    add_gui(app, 1, strdup("TEST\n"));

    cr_assert_not_null(app->gui_list->first);

    cr_assert_not_null(find_gui(app, 1));
    destroy_app(app);
}

Test(communication, dont_find_gui, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4454;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);

    cr_assert_not_null(app);
    node_data_t data;
    data.client = create_client(1);
    list_add_back(app->clients_list, data);
    add_gui(app, 1, strdup("TEST\n"));

    cr_assert_not_null(app->gui_list->first);

    cr_assert_null(find_gui(app, 2));
    destroy_app(app);
}

Test(communication, create_client_add_it, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4455;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    node_data_t data;
    data.client = create_client(5);

    list_add_back(app->clients_list, data);
    cr_assert_not_null(app->clients_list->first);
}

Test(communication, its_client, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4456;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    node_data_t data;
    data.client = create_client(5);

    list_add_back(app->clients_list, data);
    cr_assert_not_null(app->clients_list->first);

    cr_assert_eq(its_client(app, 5), true);
}

Test(communication, its_not_client, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4457;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    node_data_t data;
    data.client = create_client(5);

    list_add_back(app->clients_list, data);
    cr_assert_not_null(app->clients_list->first);

    cr_assert_eq(its_client(app, 8), false);
}

Test(communication, find_client, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4458;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    node_data_t data;
    data.client = create_client(5);
    list_add_back(app->clients_list, data);

    node_data_t data2;
    data2.client = create_client(8);
    list_add_back(app->clients_list, data2);

    server_reset_fd(app);

    cr_assert_not_null(app->clients_list->first);
    cr_assert_not_null(app->clients_list->first->next);

    cr_assert_not_null(find_client(app->clients_list, 8));
}

Test(communication, quit_ia, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4459;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    node_data_t data;
    data.team = create_team(app, strdup("team 1"), 3);
    list_add_front(app->teams_list, data);
    node_data_t data1;
    data1.client = create_client(1);
    list_add_back(app->clients_list, data1);
    node_data_t data2;
    data2.client = create_client(8);
    list_add_back(app->clients_list, data2);
    node_data_t data3;
    data3.client = create_client(12);
    list_add_back(app->clients_list, data3);
    add_ia(app, 1, strdup("team 1"));
    add_ia(app, 8, strdup("team 1"));
    add_ia(app, 12, strdup("team 1"));

    data.team = create_team(app, strdup("team 2"), 3);
    list_add_front(app->teams_list, data);
    node_data_t data4;
    data4.client = create_client(4);
    list_add_back(app->clients_list, data4);
    node_data_t data5;
    data5.client = create_client(5);
    list_add_back(app->clients_list, data5);
    node_data_t data6;
    data6.client = create_client(18);
    list_add_back(app->clients_list, data6);
    add_ia(app, 4, strdup("team 2"));
    add_ia(app, 5, strdup("team 2"));
    add_ia(app, 18, strdup("team 2"));


    server_reset_fd(app);

    server_quit_handler(app, 18);
}

Test(communication, quit_bad_ia, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 5459;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->freq = 100;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1");
    parsing->names[1] = strdup("team 2");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    node_data_t data1;
    data1.client = create_client(1);
    list_add_back(app->clients_list, data1);
    node_data_t data2;
    data2.client = create_client(8);
    list_add_back(app->clients_list, data2);
    node_data_t data3;
    data3.client = create_client(12);
    list_add_back(app->clients_list, data3);
    node_data_t data4;
    data4.client = create_client(4);
    list_add_back(app->clients_list, data4);
    node_data_t data5;
    data5.client = create_client(5);
    list_add_back(app->clients_list, data5);

    add_ia(app, 1, strdup("team 1"));
    add_ia(app, 8, strdup("team 1"));
    add_ia(app, 12, strdup("team 1"));
    add_ia(app, 4, strdup("team 2"));
    add_ia(app, 5, strdup("team 2"));

    server_quit_handler(app, 50);
}

Test(communication, quit_gui, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4460;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);

    cr_assert_not_null(app);
    node_data_t data;
    data.client = create_client(1);
    list_add_back(app->clients_list, data);
    add_gui(app, 1, strdup("TEST\n"));
    node_data_t data1;
    data1.client = create_client(2);
    list_add_back(app->clients_list, data1);
    add_gui(app, 2, strdup("TEST\n"));

    server_reset_fd(app);
    server_quit_handler(app, 2);
    destroy_app(app);
}

Test(communication, bad_server_connection_handler, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4462;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);

    cr_assert_eq(server_connection_handler(app, 1), false);

    destroy_app(app);
}

Test(communication, request_from_gui, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4464;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);

    cr_assert_not_null(app);
    node_data_t data;
    data.client = create_client(1);
    list_add_back(app->clients_list, data);
    add_gui(app, 1, strdup("TEST\n"));
    node_data_t data1;
    data1.client = create_client(2);
    list_add_back(app->clients_list, data1);
    add_gui(app, 2, strdup("TEST\n"));

    handle_request(app, 2, "TEST\n");

    destroy_app(app);
}

Test(communication, request_from_gui_but_too_many_request, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4465;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);

    cr_assert_not_null(app);
    node_data_t data;
    data.client = create_client(1);
    list_add_back(app->clients_list, data);
    add_gui(app, 1, strdup("TEST\n"));
    node_data_t data1;
    data1.client = create_client(2);
    list_add_back(app->clients_list, data1);
    add_gui(app, 2, strdup("TEST\n"));

    app->gui_list->first->next->data.gui->list_messages->len = 0;

    handle_request(app, 2, "TEST\n");

    destroy_app(app);
}

Test(communication, request_from_ia, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4466;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    node_data_t data;
    data.team = create_team(app, strdup("team 1"), 3);
    list_add_front(app->teams_list, data);
    node_data_t data1;
    data1.client = create_client(1);
    list_add_back(app->clients_list, data1);
    node_data_t data2;
    data2.client = create_client(8);
    list_add_back(app->clients_list, data2);
    node_data_t data3;
    data3.client = create_client(12);
    list_add_back(app->clients_list, data3);
    add_ia(app, 1, strdup("team 1"));
    add_ia(app, 8, strdup("team 1"));
    add_ia(app, 12, strdup("team 1"));

    data.team = create_team(app, strdup("team 2"), 3);
    list_add_front(app->teams_list, data);
    node_data_t data4;
    data4.client = create_client(4);
    list_add_back(app->clients_list, data4);
    node_data_t data5;
    data5.client = create_client(5);
    list_add_back(app->clients_list, data5);
    node_data_t data6;
    data6.client = create_client(18);
    list_add_back(app->clients_list, data6);
    add_ia(app, 4, strdup("team 2"));
    add_ia(app, 5, strdup("team 2"));
    add_ia(app, 18, strdup("team 2"));

    handle_request(app, 1, "TEST\n");
}

Test(communication, request_from_ai_but_too_many_request, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4467;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    node_data_t data;
    data.team = create_team(app, strdup("team 1"), 3);
    list_add_front(app->teams_list, data);
    node_data_t data1;
    data1.client = create_client(1);
    list_add_back(app->clients_list, data1);
    node_data_t data2;
    data2.client = create_client(8);
    list_add_back(app->clients_list, data2);
    node_data_t data3;
    data3.client = create_client(12);
    list_add_back(app->clients_list, data3);
    add_ia(app, 1, strdup("team 1"));
    add_ia(app, 8, strdup("team 1"));
    add_ia(app, 12, strdup("team 1"));

    data.team = create_team(app, strdup("team 2"), 3);
    list_add_front(app->teams_list, data);
    node_data_t data4;
    data4.client = create_client(4);
    list_add_back(app->clients_list, data4);
    node_data_t data5;
    data5.client = create_client(5);
    list_add_back(app->clients_list, data5);
    node_data_t data6;
    data6.client = create_client(18);
    list_add_back(app->clients_list, data6);
    add_ia(app, 4, strdup("team 2"));
    add_ia(app, 5, strdup("team 2"));
    add_ia(app, 18, strdup("team 2"));

    ia_t *ai = find_ia(app, 1);
    cr_assert_not_null(ai);

    ai->list_messages->len = 10;

    cr_assert_eq(ai->list_messages->len, 10);

    handle_request(app, 1, "TEST\n");
}

Test(communication, append_char, .timeout = 5)
{
    char *test = strdup("HEY");

    append_char(test, 'a');
    cr_assert_str_eq("HEYa", test);
}

Test(communication, handle_client_read_server, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4468;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    handle_client_read(app, app->server->fd);
}

Test(communication, handle_client_write_ai, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4469;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    node_data_t data;
    data.team = create_team(app, strdup("team 1"), 3);
    list_add_front(app->teams_list, data);
    node_data_t data1;
    data1.client = create_client(1);
    list_add_back(app->clients_list, data1);
    node_data_t data2;
    data2.client = create_client(8);
    list_add_back(app->clients_list, data2);
    node_data_t data3;
    data3.client = create_client(12);
    list_add_back(app->clients_list, data3);
    add_ia(app, 1, strdup("team 1"));
    add_ia(app, 8, strdup("team 1"));
    add_ia(app, 12, strdup("team 1"));

    data.team = create_team(app, strdup("team 2"), 3);
    list_add_front(app->teams_list, data);
    node_data_t data4;
    data4.client = create_client(4);
    list_add_back(app->clients_list, data4);
    node_data_t data5;
    data5.client = create_client(5);
    list_add_back(app->clients_list, data5);
    node_data_t data6;
    data6.client = create_client(18);
    list_add_back(app->clients_list, data6);
    add_ia(app, 4, strdup("team 2"));
    add_ia(app, 5, strdup("team 2"));
    add_ia(app, 18, strdup("team 2"));

    handle_client_write(app, 4);
}

Test(communication, handle_client_write_gui, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4470;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1\r");
    parsing->names[1] = strdup("team 2\r");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    node_data_t data;
    data.client = create_client(1);
    list_add_back(app->clients_list, data);
    add_gui(app, 1, strdup("TEST\n"));
    node_data_t data1;
    data1.client = create_client(2);
    list_add_back(app->clients_list, data1);
    add_gui(app, 2, strdup("TEST\n"));

    handle_client_write(app, 2);
    destroy_app(app);
}

Test(communication, add_ai_to_complete_team, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4471;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = strdup("team 1");
    parsing->names[1] = strdup("team 2");
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    node_data_t data;
    data.team = create_team(app, strdup("team 1"), 1);
    list_add_front(app->teams_list, data);
    node_data_t data1;
    data1.client = create_client(1);
    list_add_back(app->clients_list, data1);
    node_data_t data2;
    data2.client = create_client(8);
    list_add_back(app->clients_list, data2);
    add_ia(app, 1, strdup("team 1"));
    add_ia(app, 8, strdup("team 1"));
}
