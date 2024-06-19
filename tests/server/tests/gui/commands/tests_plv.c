/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_plv
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "types.h"
#include "app/app.h"
#include "gui/gui.h"
#include "gui/communication.h"

Test(plv_response, basic_test)
{
    gui_t gui;
    app_t app;
    char line[] = "plv 2";

    app.game = create_game(5, 5, 1);
    app.game->map[3][2].food = 1;
    app.game->map[3][2].linemate = 2;
    app.game->map[3][2].deraumere = 3;
    app.game->map[3][2].sibur = 4;
    app.game->map[3][2].mendiane = 5;
    app.game->map[3][2].phiras = 6;
    app.game->map[3][2].thystame = 7;
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
    ia->level = 1;
    ia->inventory = malloc(sizeof(inventory_t));
    cr_assert_not_null(ia->inventory);
    ia->inventory->deraumere = 0;
    ia->inventory->food = 0;
    ia->inventory->linemate = 0;
    ia->inventory->mendiane = 0;
    ia->inventory->phiras = 0;
    ia->inventory->sibur = 0;
    ia->inventory->thystame = 0;
    ia_t *ia2 = malloc(sizeof(ia_t));
    cr_assert_not_null(ia2);
    ia2->position = create_vector2i(1, 1);
    ia2->fd = 2;
    ia2->level = 1;
    ia2->inventory = malloc(sizeof(inventory_t));
    cr_assert_not_null(ia2->inventory);
    ia2->inventory->deraumere = 0;
    ia2->inventory->food = 0;
    ia2->inventory->linemate = 0;
    ia2->inventory->mendiane = 0;
    ia2->inventory->phiras = 0;
    ia2->inventory->sibur = 0;
    ia2->inventory->thystame = 0;
    node_data_t ia_data;
    ia_data.ai = ia;
    node_data_t ia_data2;
    ia_data2.ai = ia2;
    list_add_back(team->list_ai, ia_data);
    list_add_back(team->list_ai, ia_data2);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);

    plv_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "plv 2 1\n");
    free_map(app.game->map, 5);
}

Test(plv_response, basic_test_2)
{
    gui_t gui;
    app_t app;
    char line[] = "plv 1";

    app.game = create_game(5, 5, 1);
    app.game->map[3][2].food = 1;
    app.game->map[3][2].linemate = 2;
    app.game->map[3][2].deraumere = 3;
    app.game->map[3][2].sibur = 4;
    app.game->map[3][2].mendiane = 5;
    app.game->map[3][2].phiras = 6;
    app.game->map[3][2].thystame = 7;
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
    ia->level = 1;
    ia->inventory = malloc(sizeof(inventory_t));
    cr_assert_not_null(ia->inventory);
    ia->inventory->deraumere = 0;
    ia->inventory->food = 0;
    ia->inventory->linemate = 0;
    ia->inventory->mendiane = 0;
    ia->inventory->phiras = 0;
    ia->inventory->sibur = 0;
    ia->inventory->thystame = 0;
    ia_t *ia2 = malloc(sizeof(ia_t));
    cr_assert_not_null(ia2);
    ia2->position = create_vector2i(1, 1);
    ia2->fd = 2;
    ia2->level = 1;
    ia2->inventory = malloc(sizeof(inventory_t));
    cr_assert_not_null(ia2->inventory);
    ia2->inventory->deraumere = 0;
    ia2->inventory->food = 0;
    ia2->inventory->linemate = 0;
    ia2->inventory->mendiane = 0;
    ia2->inventory->phiras = 0;
    ia2->inventory->sibur = 0;
    ia2->inventory->thystame = 0;
    node_data_t ia_data;
    ia_data.ai = ia;
    node_data_t ia_data2;
    ia_data2.ai = ia2;
    list_add_back(team->list_ai, ia_data);
    list_add_back(team->list_ai, ia_data2);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);

    plv_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "plv 1 1\n");
    free_map(app.game->map, 5);
}

Test(plv_response, basic_test_3)
{
    gui_t gui;
    app_t app;
    char line[] = "plv 1";

    app.game = create_game(5, 5, 1);
    app.game->map[3][2].food = 1;
    app.game->map[3][2].linemate = 2;
    app.game->map[3][2].deraumere = 3;
    app.game->map[3][2].sibur = 4;
    app.game->map[3][2].mendiane = 5;
    app.game->map[3][2].phiras = 6;
    app.game->map[3][2].thystame = 7;
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
    ia->level = 1;
    ia->inventory = malloc(sizeof(inventory_t));
    cr_assert_not_null(ia->inventory);
    ia->inventory->deraumere = 5;
    ia->inventory->food = 4;
    ia->inventory->linemate = 2;
    ia->inventory->mendiane = 0;
    ia->inventory->phiras = 1;
    ia->inventory->sibur = 0;
    ia->inventory->thystame = 7;
    ia_t *ia2 = malloc(sizeof(ia_t));
    cr_assert_not_null(ia2);
    ia2->position = create_vector2i(1, 1);
    ia2->fd = 2;
    ia2->level = 5;
    ia2->inventory = malloc(sizeof(inventory_t));
    cr_assert_not_null(ia2->inventory);
    ia2->inventory->deraumere = 10;
    ia2->inventory->food = 0;
    ia2->inventory->linemate = 74;
    ia2->inventory->mendiane = 0;
    ia2->inventory->phiras = 100;
    ia2->inventory->sibur = 0;
    ia2->inventory->thystame = 23;
    node_data_t ia_data;
    ia_data.ai = ia;
    node_data_t ia_data2;
    ia_data2.ai = ia2;
    list_add_back(team->list_ai, ia_data);
    list_add_back(team->list_ai, ia_data2);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);

    plv_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "plv 1 1\n");
    plv_response(&gui, &app, "plv 2");
    cr_assert_str_eq(gui.list_messages->first->next->data.message, "plv 2 5\n");
    free_map(app.game->map, 5);
}

Test(plv_response, unknow_id)
{
    gui_t gui;
    app_t app;
    char line[] = "plv 15";

    app.game = create_game(5, 5, 1);
    app.game->map[3][2].food = 1;
    app.game->map[3][2].linemate = 2;
    app.game->map[3][2].deraumere = 3;
    app.game->map[3][2].sibur = 4;
    app.game->map[3][2].mendiane = 5;
    app.game->map[3][2].phiras = 6;
    app.game->map[3][2].thystame = 7;
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
    ia->level = 5;
    ia->inventory = malloc(sizeof(inventory_t));
    cr_assert_not_null(ia->inventory);
    ia->inventory->deraumere = 0;
    ia->inventory->food = 0;
    ia->inventory->linemate = 0;
    ia->inventory->mendiane = 0;
    ia->inventory->phiras = 0;
    ia->inventory->sibur = 0;
    ia->inventory->thystame = 0;
    ia_t *ia2 = malloc(sizeof(ia_t));
    cr_assert_not_null(ia2);
    ia2->position = create_vector2i(1, 1);
    ia2->fd = 2;
    ia2->level = 5;
    ia2->inventory = malloc(sizeof(inventory_t));
    cr_assert_not_null(ia2->inventory);
    ia2->inventory->deraumere = 0;
    ia2->inventory->food = 0;
    ia2->inventory->linemate = 0;
    ia2->inventory->mendiane = 0;
    ia2->inventory->phiras = 0;
    ia2->inventory->sibur = 0;
    ia2->inventory->thystame = 0;
    node_data_t ia_data;
    ia_data.ai = ia;
    node_data_t ia_data2;
    ia_data2.ai = ia2;
    list_add_back(team->list_ai, ia_data);
    list_add_back(team->list_ai, ia_data2);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);

    plv_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "sbp\n");
    free_map(app.game->map, 5);
}

Test(plv_response, invalid_command)
{
    gui_t gui;
    app_t app;
    char line[] = "plv2 -3";

    app.game = create_game(5, 5, 1);
    app.game->map[3][2].food = 1;
    app.game->map[3][2].linemate = 2;
    app.game->map[3][2].deraumere = 3;
    app.game->map[3][2].sibur = 4;
    app.game->map[3][2].mendiane = 5;
    app.game->map[3][2].phiras = 6;
    app.game->map[3][2].thystame = 7;

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    gui.fd = 1;

    plv_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "suc\n");
    free_map(app.game->map, 5);
}
