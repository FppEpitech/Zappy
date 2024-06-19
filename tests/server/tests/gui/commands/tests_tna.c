/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_tna
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "types.h"
#include "app/app.h"
#include "gui/gui.h"
#include "gui/communication.h"

Test(tna_response, basic_test)
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

Test(tna_response, invalid_command)
{
    gui_t gui;
    app_t app;
    char line[] = "tna2";

    app.game = create_game(5, 5, 1);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    gui.fd = 1;

    app.teams_list = list_new();

    tna_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "suc\n");
    free_map(app.game->map, 5);
}
