/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** tests_loop
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "gui/communication.h"

Test(handle_command_gui, basic_msz)
{
    gui_t gui;
    app_t app;
    char line[] = "msz";

    app.game = create_game(5, 5, 1);
    app.teams_list = list_new();

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);

    handle_command_gui(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "msz 5 5\n");
}

Test(handle_command_gui, basic_bct)
{
    gui_t gui;
    app_t app;
    char line[] = "bct 2 2";

    app.game = create_game(5, 5, 1);
    app.game->map[2][2].food = 1;
    app.game->map[2][2].linemate = 2;
    app.game->map[2][2].deraumere = 3;
    app.game->map[2][2].sibur = 4;
    app.game->map[2][2].mendiane = 5;
    app.game->map[2][2].phiras = 6;
    app.game->map[2][2].thystame = 7;
    app.teams_list = list_new();

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);

    handle_command_gui(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "bct 2 2 1 2 3 4 5 6 7\n");
}

Test(handle_command_gui, basic_mct)
{
    gui_t gui;
    app_t app;
    char line[] = "mct";

    app.game = create_game(2, 2, 1);
    app.game->map[0][0].food = 1;
    app.game->map[0][0].linemate = 2;
    app.game->map[0][0].deraumere = 3;
    app.game->map[0][0].sibur = 4;
    app.game->map[0][0].mendiane = 5;
    app.game->map[0][0].phiras = 6;
    app.game->map[0][0].thystame = 7;
    app.game->map[0][1].food = 0;
    app.game->map[0][1].linemate = 0;
    app.game->map[0][1].deraumere = 0;
    app.game->map[0][1].sibur = 0;
    app.game->map[0][1].mendiane = 0;
    app.game->map[0][1].phiras = 0;
    app.game->map[0][1].thystame = 0;
    app.game->map[1][0].food = 5;
    app.game->map[1][0].linemate = 1;
    app.game->map[1][0].deraumere = 1;
    app.game->map[1][0].sibur = 1;
    app.game->map[1][0].mendiane = 1;
    app.game->map[1][0].phiras = 1;
    app.game->map[1][0].thystame = 1;
    app.game->map[1][1].food = 3;
    app.game->map[1][1].linemate = 3;
    app.game->map[1][1].deraumere = 3;
    app.game->map[1][1].sibur = 3;
    app.game->map[1][1].mendiane = 3;
    app.game->map[1][1].phiras = 3;
    app.game->map[1][1].thystame = 3;

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);

    handle_command_gui(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "bct 0 0 1 2 3 4 5 6 7\nbct 1 0 0 0 0 0 0 0 0\nbct 0 1 5 1 1 1 1 1 1\nbct 1 1 3 3 3 3 3 3 3\n");
}

Test(handle_command_gui, basic_tna)
{
    gui_t gui;
    app_t app;
    char line[] = "tna";

    app.game = create_game(5, 5, 1);
    app.teams_list = list_new();

    team_t *team = create_team(&app, "kiki", 3);
    cr_assert_not_null(team);
    node_data_t team_data;
    team_data.team = team;
    list_add_front(app.teams_list, team_data);
    team_t *team1 = create_team(&app, "valgrind", 3);
    cr_assert_not_null(team1);
    node_data_t team_data1;
    team_data1.team = team1;
    list_add_front(app.teams_list, team_data1);
    team_t *team2 = create_team(&app, "alice", 3);
    cr_assert_not_null(team2);
    node_data_t team_data2;
    team_data2.team = team2;
    list_add_front(app.teams_list, team_data2);
    team_t *team3 = create_team(&app, "leo", 3);
    cr_assert_not_null(team3);
    node_data_t team_data3;
    team_data3.team = team3;
    list_add_front(app.teams_list, team_data3);
    team_t *team4 = create_team(&app, "bob", 3);
    cr_assert_not_null(team4);
    node_data_t team_data4;
    team_data4.team = team4;
    list_add_front(app.teams_list, team_data4);
    team_t *team5 = create_team(&app, "lemon", 3);
    cr_assert_not_null(team5);
    node_data_t team_data5;
    team_data5.team = team5;
    list_add_front(app.teams_list, team_data5);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);

    tna_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "tna lemon\n");
    cr_assert_str_eq(gui.list_messages->first->next->data.message, "tna bob\n");
    cr_assert_str_eq(gui.list_messages->first->next->next->data.message, "tna leo\n");
    cr_assert_str_eq(gui.list_messages->first->next->next->next->data.message, "tna alice\n");
    cr_assert_str_eq(gui.list_messages->first->next->next->next->next->data.message, "tna valgrind\n");
    cr_assert_str_eq(gui.list_messages->first->next->next->next->next->next->data.message, "tna kiki\n");
    free_map(app.game->map, 5);
}

Test(handle_command_gui, basic_ppo)
{
    gui_t gui;
    app_t app;
    char line[] = "ppo 1";

    app.game = create_game(5, 5, 1);
    app.teams_list = list_new();

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);

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

    node_data_t ia_data;
    ia_data.ai = ia;
    list_add_back(team->list_ai, ia_data);

    ppo_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "ppo 1 1 1 1\n");
    free_map(app.game->map, 5);
}

Test(handle_command_gui, basic_plv)
{
    gui_t gui;
    app_t app;
    char line[] = "plv 1";

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
    node_data_t ia_data;
    ia_data.ai = ia;
    list_add_back(team->list_ai, ia_data);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);

    plv_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "plv 1 1\n");
    free_map(app.game->map, 5);
}

Test(handle_command_gui, basic_pin)
{
    gui_t gui;
    app_t app;
    char line[] = "pin 1";

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
    node_data_t ia_data;
    ia_data.ai = ia;
    list_add_back(team->list_ai, ia_data);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);

    pin_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "pin 1 1 1 0 0 0 0 0 0 0\n");
    free_map(app.game->map, 5);
}

Test(handle_command_gui, basic_sgt)
{
    gui_t gui;
    app_t app;
    char line[] = "sgt";

    app.game = create_game(5, 5, 1);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    gui.fd = 1;

    sgt_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "sgt 1\n");
    free_map(app.game->map, 5);
}

Test(handle_command_gui, basic_sst)
{
    gui_t gui;
    app_t app;
    char line[] = "sst 1";

    app.game = create_game(5, 5, 0);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    gui.fd = 0;

    sgt_response(&gui, &app, "sgt");
    cr_assert_str_eq(gui.list_messages->first->data.message, "sgt 0\n");
    sst_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->next->data.message, "sst 1\n");
    sgt_response(&gui, &app, "sgt");
    cr_assert_str_eq(gui.list_messages->first->next->next->data.message, "sgt 1\n");
    free_map(app.game->map, 5);
}

Test(handle_command_gui, unknow_command)
{
    gui_t gui;
    app_t app;
    char line[] = "unknow";

    app.game = create_game(5, 5, 1);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);

    handle_command_gui(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "suc\n");
}
