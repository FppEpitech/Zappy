/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** parse_client_tests
*/

#include "types.h"
#include "parsing.h"
#include "rules.h"

#include <criterion/criterion.h>

Test(parse_client, no_arg_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-c", NULL};
    int pos = 0;
    int res = parse_client(arg, &pos, parsing);

    cr_assert_eq(res, CODE_ERROR_MISSING_ARG);
    free(parsing);
}

Test(parse_client, invalid_arg_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-c", "test", NULL};
    int pos = 0;
    int res = parse_client(arg, &pos, parsing);

    cr_assert_eq(res, CODE_ERROR_INVALID_ARG);
    free(parsing);
}

Test(parse_client, valid_arg_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-c", "10", NULL};
    int pos = 0;
    int res = parse_client(arg, &pos, parsing);

    cr_assert_eq(res, 0);
    cr_assert_eq(parsing->clientsNb, 10);
    cr_assert_eq(pos, 2);
    free(parsing);
}

Test(parse_client, invalid_flag_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-t", "10", NULL};
    int pos = 0;
    int res = parse_client(arg, &pos, parsing);

    cr_assert_eq(res, CODE_ERROR_WRONG_FLAG);
    free(parsing);
}
