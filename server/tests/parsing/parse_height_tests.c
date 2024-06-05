/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** parse_height_tests
*/

#include "rules.h"
#include "types.h"
#include "parsing.h"

#include <criterion/criterion.h>

Test(parse_height, no_arg_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-y", NULL};
    int pos = 0;
    int res = parse_height(arg, &pos, parsing);

    cr_assert_eq(res, CODE_ERROR_MISSING_ARG);
    free(parsing);
}

Test(parse_height, invalid_arg_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-y", "test", NULL};
    int pos = 0;
    int res = parse_height(arg, &pos, parsing);

    cr_assert_eq(res, CODE_ERROR_INVALID_ARG);
    free(parsing);
}

Test(parse_height, valid_arg_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-y", "10", NULL};
    int pos = 0;
    int res = parse_height(arg, &pos, parsing);

    cr_assert_eq(res, CODE_SUCCESS);
    cr_assert_eq(parsing->height, 10);
    cr_assert_eq(pos, 2);
    free(parsing);
}

Test(parse_height, invalid_flag_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-t", "10", NULL};
    int pos = 0;
    int res = parse_height(arg, &pos, parsing);

    cr_assert_eq(res, CODE_ERROR_WRONG_FLAG);
    free(parsing);
}
