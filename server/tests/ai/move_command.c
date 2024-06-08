/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Test on AI command move
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "ai/cmd/command_ai.h"
#include "server/client.h"

Test(ai_command_move, forward_command_y_border_north, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4472;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = "team 1";
    parsing->names[1] = "team 2";
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    add_ia(app, 1, "team 2");

    ia_t *ai = find_ia(app, 1);

    command_ai_handler(app, ai, "Forward");
    cr_assert_eq(ai->y, parsing->height - 1);
}

Test(ai_command_move, forward_command_y_not_border_north, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4473;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = "team 1";
    parsing->names[1] = "team 2";
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    add_ia(app, 1, "team 2");

    ia_t *ai = find_ia(app, 1);
    ai->y = 1;

    command_ai_handler(app, ai, "Forward");
    cr_assert_eq(ai->y, 0);
}

Test(ai_command_move, forward_command_y_border_south, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4474;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = "team 1";
    parsing->names[1] = "team 2";
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    add_ia(app, 1, "team 2");

    ia_t *ai = find_ia(app, 1);
    ai->y = 9;
    ai->direction = SOUTH;

    command_ai_handler(app, ai, "Forward");
    cr_assert_eq(ai->y, 0);
}

Test(ai_command_move, forward_command_y_not_border_south, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4475;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = "team 1";
    parsing->names[1] = "team 2";
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    add_ia(app, 1, "team 2");

    ia_t *ai = find_ia(app, 1);
    ai->y = 13;
    ai->direction = SOUTH;

    command_ai_handler(app, ai, "Forward");
    cr_assert_eq(ai->y, 14);
}

Test(ai_command_move, forward_command_y_border_east, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4476;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = "team 1";
    parsing->names[1] = "team 2";
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    add_ia(app, 1, "team 2");

    ia_t *ai = find_ia(app, 1);
    ai->x = 14;
    ai->direction = EAST;

    command_ai_handler(app, ai, "Forward");
    cr_assert_eq(ai->x, 0);
}

Test(ai_command_move, forward_command_y_not_border_east, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4477;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = "team 1";
    parsing->names[1] = "team 2";
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    add_ia(app, 1, "team 2");

    ia_t *ai = find_ia(app, 1);
    ai->x = 8;
    ai->direction = EAST;

    command_ai_handler(app, ai, "Forward");
    cr_assert_eq(ai->x, 9);
}

Test(ai_command_move, forward_command_y_border_west, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4478;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = "team 1";
    parsing->names[1] = "team 2";
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    add_ia(app, 1, "team 2");

    ia_t *ai = find_ia(app, 1);
    ai->x = 0;
    ai->direction = WEST;

    command_ai_handler(app, ai, "Forward");
    cr_assert_eq(ai->x, parsing->width - 1);
}

Test(ai_command_move, forward_command_y_not_border_west, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4479;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = "team 1";
    parsing->names[1] = "team 2";
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    add_ia(app, 1, "team 2");

    ia_t *ai = find_ia(app, 1);
    ai->x = 1;
    ai->direction = WEST;

    command_ai_handler(app, ai, "Forward");
    cr_assert_eq(ai->x, 0);
}

Test(ai_command_move, left_command_when_north, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4480;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = "team 1";
    parsing->names[1] = "team 2";
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    add_ia(app, 1, "team 2");

    ia_t *ai = find_ia(app, 1);

    command_ai_handler(app, ai, "Left");
    cr_assert_eq(ai->direction, WEST);
}

Test(ai_command_move, left_command_when_west, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4481;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = "team 1";
    parsing->names[1] = "team 2";
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    add_ia(app, 1, "team 2");

    ia_t *ai = find_ia(app, 1);

    command_ai_handler(app, ai, "Left");
    command_ai_handler(app, ai, "Left");
    cr_assert_eq(ai->direction, SOUTH);
}

Test(ai_command_move, left_command_when_south, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4482;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = "team 1";
    parsing->names[1] = "team 2";
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    add_ia(app, 1, "team 2");

    ia_t *ai = find_ia(app, 1);

    command_ai_handler(app, ai, "Left");
    command_ai_handler(app, ai, "Left");
    command_ai_handler(app, ai, "Left");
    cr_assert_eq(ai->direction, EAST);
}

Test(ai_command_move, left_command_when_east, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4483;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = "team 1";
    parsing->names[1] = "team 2";
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    add_ia(app, 1, "team 2");

    ia_t *ai = find_ia(app, 1);

    command_ai_handler(app, ai, "Left");
    command_ai_handler(app, ai, "Left");
    command_ai_handler(app, ai, "Left");
    command_ai_handler(app, ai, "Left");
    cr_assert_eq(ai->direction, NORTH);
}

Test(ai_command_move, right_command_when_north, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4484;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = "team 1";
    parsing->names[1] = "team 2";
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    add_ia(app, 1, "team 2");

    ia_t *ai = find_ia(app, 1);

    command_ai_handler(app, ai, "Right");
    cr_assert_eq(ai->direction, EAST);
}

Test(ai_command_move, right_command_when_west, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4485;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = "team 1";
    parsing->names[1] = "team 2";
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    add_ia(app, 1, "team 2");

    ia_t *ai = find_ia(app, 1);

    command_ai_handler(app, ai, "Right");
    command_ai_handler(app, ai, "Right");
    cr_assert_eq(ai->direction, SOUTH);
}

Test(ai_command_move, right_command_when_south, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4486;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = "team 1";
    parsing->names[1] = "team 2";
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    add_ia(app, 1, "team 2");

    ia_t *ai = find_ia(app, 1);

    command_ai_handler(app, ai, "Right");
    command_ai_handler(app, ai, "Right");
    command_ai_handler(app, ai, "Right");
    cr_assert_eq(ai->direction, WEST);
}

Test(ai_command_move, right_command_when_east, .timeout = 5)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));
    parsing->port = 4487;
    parsing->height = 10;
    parsing->width = 15;
    parsing->clientsNb = 3;
    parsing->names = malloc(sizeof(char *) * 3);
    parsing->names[0] = "team 1";
    parsing->names[1] = "team 2";
    parsing->names[2] = NULL;
    app_t *app = create_app(parsing);
    cr_assert_not_null(app);

    add_ia(app, 1, "team 2");

    ia_t *ai = find_ia(app, 1);

    command_ai_handler(app, ai, "Right");
    command_ai_handler(app, ai, "Right");
    command_ai_handler(app, ai, "Right");
    command_ai_handler(app, ai, "Right");
    cr_assert_eq(ai->direction, NORTH);
}
