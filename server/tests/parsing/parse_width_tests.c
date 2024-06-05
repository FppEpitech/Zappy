/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** parse_width_tests
*/

#include <criterion/criterion.h>

#include "parsing.h"
#include "types.h"

Test(parse_width, no_arg_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-x", NULL};
    int pos = 0;
    int res = parse_width(arg, &pos, parsing);

    cr_assert_eq(res, CODE_ERROR_MISSING_ARG);
    free(parsing);
}

Test(parse_width, invalid_arg_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-x", "test", NULL};
    int pos = 0;
    int res = parse_width(arg, &pos, parsing);

    cr_assert_eq(res, CODE_ERROR_INVALID_ARG);
    free(parsing);
}

Test(parse_width, valid_arg_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-x", "10", NULL};
    int pos = 0;
    int res = parse_width(arg, &pos, parsing);

    cr_assert_eq(res, 0);
    cr_assert_eq(parsing->width, 10);
    cr_assert_eq(pos, 2);
    free(parsing);
}

Test(parse_width, invalid_flag_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-t", "10", NULL};
    int pos = 0;
    int res = parse_width(arg, &pos, parsing);

    cr_assert_eq(res, CODE_ERROR_WRONG_FLAG);
    free(parsing);
}
