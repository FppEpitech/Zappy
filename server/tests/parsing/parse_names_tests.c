/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** parse_names_tests
*/

#include "rules.h"
#include "parsing.h"

#include <criterion/criterion.h>

Test(parse_names, no_arg_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-n", NULL};
    int pos = 0;
    int res = parse_names(arg, &pos, parsing);

    cr_assert_eq(res, CODE_ERROR_MISSING_ARG);
    free(parsing);
}

Test(parse_names, one_arg_test)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-n", "test", NULL};
    int pos = 0;
    int res = parse_names(arg, &pos, parsing);

    cr_assert_eq(res, CODE_SUCCESS);
    free(parsing);
}

Test(parse_names, many_arg_test)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-n", "test", "kiki", "valgrind", "alice", "bob", NULL};
    int pos = 0;
    int res = parse_names(arg, &pos, parsing);

    cr_assert_eq(res, CODE_SUCCESS);
    free(parsing);
}

Test(parse_names, wrong_flag)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-f", "test", NULL};
    int pos = 0;
    int res = parse_names(arg, &pos, parsing);

    cr_assert_eq(res, CODE_ERROR_WRONG_FLAG);
    free(parsing);
}

Test(parse_names, other_arg_after)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-n", "test", "-c", NULL};
    int pos = 0;
    int res = parse_names(arg, &pos, parsing);

    cr_assert_eq(res, CODE_SUCCESS);
    free(parsing);
}
