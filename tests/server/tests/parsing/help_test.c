/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** help_test
*/

#include "../include/parsing.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#define USAGE "USAGE:\t./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n\nDescription:\n\t-p port\tis the port number\n\t-x width\tis the width of the world\n\t-y height\tis the height of the world\n\t-n name1 name2 ...\tis the name of the teams\n\t-c clientsNb\tis the number of authorized clients per team\n\t-f freq\tis the reciprocal of time unit for execution of actions\n"

Test(help_test, test_help_label)
{
    char **av = malloc(sizeof(char *) * 3);
    av[0] = strdup("./zappy_server");
    av[1] = strdup("--help");
    av[2] = NULL;

    cr_redirect_stdout();
    cr_assert_eq(handle_help(2, av), 1, "The help flag is not detected");
    cr_assert_stdout_eq_str(USAGE, "The output of stdout is wrong exepted: '%s', got: '%s'", USAGE, cr_get_redirected_stdout());
    free(av);
}

Test(help_test, test_help_flag)
{
    char **av = malloc(sizeof(char *) * 3);
    av[0] = strdup("./zappy_server");
    av[1] = strdup("-h");
    av[2] = NULL;

    cr_redirect_stdout();
    cr_assert_eq(handle_help(2, av), 1, "The help flag is not detected");
    cr_assert_stdout_eq_str(USAGE, "The output of stdout is wrong exepted: '%s', got: '%s'", USAGE, cr_get_redirected_stdout());
    free(av);
}

Test(help_test, test_help_no_flag)
{
    char **av = malloc(sizeof(char *) * 3);
    av[0] = strdup("./zappy_server");
    av[1] = strdup("test");
    av[2] = NULL;

    cr_assert_eq(handle_help(2, av), 0, "The help flag is detected");
    free(av);
}

Test(help_test, test_too_many_argument)
{
    char **av = malloc(sizeof(char *) * 4);
    av[0] = strdup("./zappy_server");
    av[1] = strdup("--help");
    av[2] = strdup("test");
    av[3] = NULL;

    cr_assert_eq(handle_help(3, av), 0, "The function return 1 when it should return 0");
    free(av);
}

Test(help_test, test_not_enough_argument)
{
    char **av = malloc(sizeof(char *) * 2);
    av[0] = strdup("./zappy_server");
    av[1] = NULL;

    cr_assert_eq(handle_help(1, av), 0, "The function return 1 when it should return 0");
    free(av);
}
