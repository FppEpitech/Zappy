/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_ppo
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "types.h"
#include "app/app.h"
#include "gui/gui.h"
#include "gui/communication.h"

Test(ppo_response, basic_test)
{
    gui_t gui;
    app_t app;
    char line[] = "ppo 2";

    app.game = create_game(5, 5, 1);
    app.teams_list = list_new();

    team_t *team = create_team(&app, "kiki", 3);
    cr_assert_not_null(team);
    node_data_t team_data;
    team_data.team = team;
    list_add_front(app.teams_list, team_data);

    team->list_ai = list_new();
    cr_assert_not_null(team->list_ai);
    ia_t *ia = malloc(sizeof(ia_t));
    cr_assert_not_null(ia);
    ia->position = create_vector2i(1, 1);
    ia->fd = 1;
    ia->direction = 1;
    ia_t *ia2 = malloc(sizeof(ia_t));
    cr_assert_not_null(ia2);
    ia2->position = create_vector2i(1, 1);
    ia2->fd = 2;
    ia2->direction = 1;
    node_data_t ia_data;
    ia_data.ai = ia;
    node_data_t ia_data2;
    ia_data2.ai = ia2;
    list_add_back(team->list_ai, ia_data);
    list_add_back(team->list_ai, ia_data2);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);

    ppo_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "ppo 2 1 1 1\n");
    free_map(app.game->map, 5);
}

Test(ppo_response, basic_test_2)
{
    gui_t gui;
    app_t app;
    char line[] = "ppo 42";

    app.game = create_game(5, 5, 1);
    app.teams_list = list_new();

    team_t *team = create_team(&app, "kiki", 3);
    cr_assert_not_null(team);
    node_data_t team_data;
    team_data.team = team;
    list_add_front(app.teams_list, team_data);

    team->list_ai = list_new();
    cr_assert_not_null(team->list_ai);
    ia_t *ia = malloc(sizeof(ia_t));
    cr_assert_not_null(ia);
    ia->position = create_vector2i(3, 2);
    ia->fd = 42;
    ia->direction = 2;
    ia_t *ia2 = malloc(sizeof(ia_t));
    cr_assert_not_null(ia2);
    ia2->position = create_vector2i(1, 1);
    ia2->fd = 2;
    ia2->direction = 1;
    node_data_t ia_data;
    ia_data.ai = ia;
    node_data_t ia_data2;
    ia_data2.ai = ia2;
    list_add_back(team->list_ai, ia_data);
    list_add_back(team->list_ai, ia_data2);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);

    ppo_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "ppo 42 3 2 2\n");
    free_map(app.game->map, 5);
}

Test(ppo_response, basic_test_3)
{
    gui_t gui;
    app_t app;
    char line[] = "ppo 84";

    app.game = create_game(5, 5, 1);
    app.teams_list = list_new();

    team_t *team = create_team(&app, "kiki", 3);
    cr_assert_not_null(team);
    node_data_t team_data;
    team_data.team = team;
    list_add_front(app.teams_list, team_data);

    team->list_ai = list_new();
    cr_assert_not_null(team->list_ai);
    ia_t *ia = malloc(sizeof(ia_t));
    cr_assert_not_null(ia);
    ia->position = create_vector2i(12, 62);
    ia->fd = 84;
    ia->direction = 3;
    ia_t *ia2 = malloc(sizeof(ia_t));
    cr_assert_not_null(ia2);
    ia2->position = create_vector2i(5, 14);
    ia2->fd = 42;
    ia2->direction = 0;
    node_data_t ia_data;
    ia_data.ai = ia;
    node_data_t ia_data2;
    ia_data2.ai = ia2;
    list_add_back(team->list_ai, ia_data);
    list_add_back(team->list_ai, ia_data2);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);

    ppo_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "ppo 84 12 62 3\n");
    ppo_response(&gui, &app, "ppo 42");
    cr_assert_str_eq(gui.list_messages->first->next->data.message, "ppo 42 5 14 0\n");
    free_map(app.game->map, 5);
}

Test(ppo_response, unknow_id)
{
    gui_t gui;
    app_t app;
    char line[] = "ppo 15";

    app.game = create_game(5, 5, 1);
    app.teams_list = list_new();

    team_t *team = create_team(&app, "kiki", 3);
    cr_assert_not_null(team);
    node_data_t team_data;
    team_data.team = team;
    list_add_front(app.teams_list, team_data);

    team->list_ai = list_new();
    cr_assert_not_null(team->list_ai);
    ia_t *ia = malloc(sizeof(ia_t));
    cr_assert_not_null(ia);
    ia->position = create_vector2i(1, 1);
    ia->fd = 1;
    ia->direction = 5;
    ia_t *ia2 = malloc(sizeof(ia_t));
    cr_assert_not_null(ia2);
    ia2->position = create_vector2i(1, 1);
    ia2->fd = 2;
    ia2->direction = 5;
    node_data_t ia_data;
    ia_data.ai = ia;
    node_data_t ia_data2;
    ia_data2.ai = ia2;
    list_add_back(team->list_ai, ia_data);
    list_add_back(team->list_ai, ia_data2);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);

    ppo_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "sbp\n");
    free_map(app.game->map, 5);
}

Test(ppo_response, invalid_command)
{
    gui_t gui;
    app_t app;
    char line[] = "ppo2 -3";

    app.game = create_game(5, 5, 1);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    gui.fd = 1;

    ppo_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "suc\n");
    free_map(app.game->map, 5);
}
