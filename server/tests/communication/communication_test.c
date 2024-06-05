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
    app_t *app = create_app(4444, 10, 15);

    cr_assert_not_null(app);
    destroy_app(app);
}

Test(communication, create_team, .timeout = 5)
{
    app_t *app = create_app(4445, 10, 15);

    cr_assert_not_null(app);
    node_data_t data;
    data.team = create_team(strdup("team 1\r"), 1);
    list_add_front(app->teams_list, data);

    cr_assert_not_null(app->teams_list->first);
    destroy_app(app);
}

Test(communication, add_ia, .timeout = 5)
{
    app_t *app = create_app(4446, 10, 15);

    cr_assert_not_null(app);
    node_data_t data;
    data.team = create_team(strdup("team 1\r"), 1);
    list_add_front(app->teams_list, data);
    add_ia(app, 1, "team 1\r");

    cr_assert_not_null(app->teams_list->first->data.team->list_ai->first);
    destroy_app(app);
}

Test(communication, reset_fd, .timeout = 5)
{
    app_t *app = create_app(4447, 10, 15);

    cr_assert_not_null(app);
    node_data_t data;
    data.team = create_team(strdup("team 1\r"), 1);
    list_add_front(app->teams_list, data);
    add_ia(app, 1, "team 1\r");
    server_reset_fd(app);
    destroy_app(app);
}

Test(communication, add_ia_in_team, .timeout = 5)
{
    app_t *app = create_app(4448, 10, 15);

    cr_assert_not_null(app);
    node_data_t data;
    data.team = create_team(strdup("team 1\r"), 1);
    list_add_front(app->teams_list, data);
    add_ia(app, 1, "team 1\r");


    cr_assert_not_null(find_ia(app, 1));
    destroy_app(app);
}

Test(communication, add_ia_with_multiple_team, .timeout = 5)
{
    app_t *app = create_app(4449, 10, 15);
    cr_assert_not_null(app);

    node_data_t data;
    data.team = create_team(strdup("team 1\r"), 1);
    list_add_front(app->teams_list, data);
    cr_assert_eq(true, add_ia(app, 1, "team 1\r"));

    data.team = create_team(strdup("team 2\r"), 1);
    list_add_front(app->teams_list, data);
    cr_assert_eq(true, add_ia(app, 4, "team 2\r"));
    destroy_app(app);
}

Test(communication, add_ia_in_no_existing_team, .timeout = 5)
{
    app_t *app = create_app(4450, 10, 15);

    cr_assert_not_null(app);
    node_data_t data;
    data.team = create_team(strdup("team 1\r"), 1);
    list_add_front(app->teams_list, data);
    add_ia(app, 1, "team\r");

    cr_assert_eq(true, add_ia(app, 1, "team\r"));
    destroy_app(app);
}

Test(communication, dont_find_ia, .timeout = 5)
{
    app_t *app = create_app(4451, 10, 15);

    cr_assert_not_null(app);
    node_data_t data;
    data.team = create_team(strdup("team 1\r"), 1);
    list_add_front(app->teams_list, data);
    add_ia(app, 1, "team 1\r");


    cr_assert_null(find_ia(app, 2));
    destroy_app(app);
}

Test(communication, add_gui, .timeout = 5)
{
    app_t *app = create_app(4452, 10, 15);

    cr_assert_not_null(app);
    add_gui(app, 1);

    cr_assert_not_null(app->gui_list->first);
    destroy_app(app);
}

Test(communication, find_gui, .timeout = 5)
{
    app_t *app = create_app(4453, 10, 15);

    cr_assert_not_null(app);
    add_gui(app, 1);

    cr_assert_not_null(app->gui_list->first);

    cr_assert_not_null(find_gui(app, 1));
    destroy_app(app);
}

Test(communication, dont_find_gui, .timeout = 5)
{
    app_t *app = create_app(4454, 10, 15);

    cr_assert_not_null(app);
    add_gui(app, 1);

    cr_assert_not_null(app->gui_list->first);

    cr_assert_null(find_gui(app, 2));
    destroy_app(app);
}

Test(communication, create_client_add_it, .timeout = 5)
{
    app_t *app = create_app(4455, 10, 15);
    cr_assert_not_null(app);

    node_data_t data;
    data.client = create_client(5);

    list_add_back(app->clients_list, data);
    cr_assert_not_null(app->clients_list->first);
}

Test(communication, its_client, .timeout = 5)
{
    app_t *app = create_app(4456, 10, 15);
    cr_assert_not_null(app);

    node_data_t data;
    data.client = create_client(5);

    list_add_back(app->clients_list, data);
    cr_assert_not_null(app->clients_list->first);

    cr_assert_eq(its_client(app, 5), true);
}

Test(communication, its_not_client, .timeout = 5)
{
    app_t *app = create_app(4457, 10, 15);
    cr_assert_not_null(app);

    node_data_t data;
    data.client = create_client(5);

    list_add_back(app->clients_list, data);
    cr_assert_not_null(app->clients_list->first);

    cr_assert_eq(its_client(app, 8), false);
}

Test(communication, find_client, .timeout = 5)
{
    app_t *app = create_app(4458, 10, 15);
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
    app_t *app = create_app(4459, 10, 15);
    cr_assert_not_null(app);

    node_data_t data;
    data.team = create_team(strdup("team 1"), 3);
    list_add_front(app->teams_list, data);
    add_ia(app, 1, "team 1");
    add_ia(app, 8, "team 1");
    add_ia(app, 12, "team 1");

    data.team = create_team(strdup("team 2"), 3);
    list_add_front(app->teams_list, data);
    add_ia(app, 4, "team 2");
    add_ia(app, 5, "team 2");
    add_ia(app, 18, "team 2");


    server_reset_fd(app);

    server_quit_handler(app, 18);
    destroy_app(app);
}

Test(communication, quit_bad_ia, .timeout = 5)
{
    app_t *app = create_app(4459, 10, 15);
    cr_assert_not_null(app);

    node_data_t data;
    data.team = create_team(strdup("team 1"), 3);
    list_add_front(app->teams_list, data);
    add_ia(app, 1, "team 1");
    add_ia(app, 8, "team 1");
    add_ia(app, 12, "team 1");

    data.team = create_team(strdup("team 2"), 3);
    list_add_front(app->teams_list, data);
    add_ia(app, 4, "team 2");
    add_ia(app, 5, "team 2");
    add_ia(app, 18, "team 2");

    server_quit_handler(app, 50);
    destroy_app(app);
}

Test(communication, quit_gui, .timeout = 5)
{
    app_t *app = create_app(4460, 10, 15);

    cr_assert_not_null(app);
    add_gui(app, 1);
    add_gui(app, 2);

    server_reset_fd(app);
    server_quit_handler(app, 2);
    destroy_app(app);
}

Test(communication, quit_client, .timeout = 5)
{
    app_t *app = create_app(4461, 10, 15);

    cr_assert_not_null(app);
    node_data_t data;
    data.client = create_client(5);
    list_add_back(app->clients_list, data);

    node_data_t data2;
    data2.client = create_client(8);
    list_add_back(app->clients_list, data2);


    server_quit_handler(app, 8);
    destroy_app(app);
}

Test(communication, bad_server_connection_handler, .timeout = 5)
{
    app_t *app = create_app(4462, 10, 15);

    cr_assert_eq(server_connection_handler(app, 1), false);

    destroy_app(app);
}

Test(communication, bad_server_data_handler, .timeout = 5)
{
    app_t *app = create_app(4463, 10, 15);

    write(4, "HELLO\n", strlen("HELLO\n"));

    cr_assert_eq(true, server_data_handler(app, 4));

    destroy_app(app);
}

Test(communication, request_from_gui, .timeout = 5)
{
    app_t *app = create_app(4460, 10, 15);

    cr_assert_not_null(app);
    add_gui(app, 1);
    add_gui(app, 2);

    handle_request(app, 2, "TEST\n");

    destroy_app(app);
}

Test(communication, request_from_gui_but_too_many_request, .timeout = 5)
{
    app_t *app = create_app(4461, 10, 15);

    cr_assert_not_null(app);
    add_gui(app, 1);
    add_gui(app, 2);

    app->gui_list->first->next->data.gui->list_messages->len = 10;

    handle_request(app, 2, "TEST\n");

    destroy_app(app);
}

Test(communication, request_from_ia, .timeout = 5)
{
    app_t *app = create_app(4462, 10, 15);
    cr_assert_not_null(app);

    node_data_t data;
    data.team = create_team(strdup("team 1"), 3);
    list_add_front(app->teams_list, data);
    add_ia(app, 1, "team 1");
    add_ia(app, 8, "team 1");
    add_ia(app, 12, "team 1");

    data.team = create_team(strdup("team 2"), 3);
    list_add_front(app->teams_list, data);
    add_ia(app, 4, "team 2");
    add_ia(app, 5, "team 2");
    add_ia(app, 18, "team 2");

    handle_request(app, 1, "TEST\n");
    destroy_app(app);
}

Test(communication, request_from_ai_but_too_many_request, .timeout = 5)
{
    app_t *app = create_app(4463, 10, 15);
    cr_assert_not_null(app);

    node_data_t data;
    data.team = create_team(strdup("team 1"), 3);
    list_add_front(app->teams_list, data);
    add_ia(app, 1, "team 1");
    add_ia(app, 8, "team 1");
    add_ia(app, 12, "team 1");

    data.team = create_team(strdup("team 2"), 3);
    list_add_front(app->teams_list, data);
    add_ia(app, 4, "team 2");
    add_ia(app, 5, "team 2");
    add_ia(app, 18, "team 2");

    ia_t *ai = find_ia(app, 1);
    cr_assert_not_null(ai);

    ai->list_messages->len = 10;

    cr_assert_eq(ai->list_messages->len, 10);

    handle_request(app, 1, "TEST\n");
    destroy_app(app);
}

Test(communication, append_char, .timeout = 5)
{
    char *test = strdup("HEY");

    append_char(test, 'a');
    cr_assert_str_eq("HEYa", test);
}

Test(communication, handle_client_read_server, .timeout = 5)
{
    app_t *app = create_app(4464, 10, 15);
    cr_assert_not_null(app);

    cr_assert_eq(0, handle_client_read(app, app->server->fd));
}

Test(communication, handle_client_write_ai, .timeout = 5)
{
    app_t *app = create_app(4465, 10, 15);
    cr_assert_not_null(app);

    node_data_t data;
    data.team = create_team(strdup("team 1"), 3);
    list_add_front(app->teams_list, data);
    add_ia(app, 1, "team 1");
    add_ia(app, 8, "team 1");
    add_ia(app, 12, "team 1");

    data.team = create_team(strdup("team 2"), 3);
    list_add_front(app->teams_list, data);
    add_ia(app, 4, "team 2");
    add_ia(app, 5, "team 2");
    add_ia(app, 18, "team 2");

    cr_assert_eq(0, handle_client_write(app, 4));
    destroy_app(app);
}

Test(communication, handle_client_write_gui, .timeout = 5)
{
    app_t *app = create_app(4466, 10, 15);
    cr_assert_not_null(app);

    add_gui(app, 1);
    add_gui(app, 2);

    cr_assert_eq(0, handle_client_write(app, 2));
    destroy_app(app);
}

Test(communication, add_ai_to_complete_team, .timeout = 5)
{
    app_t *app = create_app(4467, 10, 15);
    cr_assert_not_null(app);

    node_data_t data;
    data.team = create_team(strdup("team 1"), 1);
    list_add_front(app->teams_list, data);
    cr_assert_eq(true, add_ia(app, 1, "team 1"));
    cr_assert_eq(true, add_ia(app, 8, "team 1"));

    destroy_app(app);
}
