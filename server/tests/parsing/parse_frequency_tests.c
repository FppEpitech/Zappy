/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** parse_frequency_tests
*/

#include "types.h"
#include "parsing.h"
#include "rules.h"

#include <criterion/criterion.h>

Test(parse_frequency, no_arg_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-f", NULL};
    int pos = 0;
    int res = parse_frequency(arg, &pos, parsing);

    cr_assert_eq(res, CODE_ERROR_MISSING_ARG);
    free(parsing);
}

Test(parse_frequency, invalid_arg_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-f", "test", NULL};
    int pos = 0;
    int res = parse_frequency(arg, &pos, parsing);

    cr_assert_eq(res, CODE_ERROR_INVALID_ARG);
    free(parsing);
}

Test(parse_frequency, valid_arg_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-f", "10", NULL};
    int pos = 0;
    int res = parse_frequency(arg, &pos, parsing);

    cr_assert_eq(res, 0);
    cr_assert_eq(parsing->freq, 10);
    cr_assert_eq(pos, 2);
    free(parsing);
}

Test(parse_frequency, invalid_flag_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-t", "10", NULL};
    int pos = 0;
    int res = parse_frequency(arg, &pos, parsing);

    cr_assert_eq(res, CODE_ERROR_WRONG_FLAG);
    free(parsing);
}
