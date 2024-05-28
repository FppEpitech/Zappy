/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** test parseCommandLine
*/

#include "Parsing/ParseCommandLine.hpp"

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>

Test(ParseCommandLine, command_correct, .timeout = 5)
{
    char *av[6];
    int ac = 5;

    av[0] = strdup("./zappy_gui");
    av[1] = strdup("-p");
    av[2] = strdup("4242");
    av[3] = strdup("-h");
    av[4] = strdup("hostname");
    av[5] = NULL;

    Gui::ParseCommandLine parser(ac, av);

    cr_assert_eq(parser.getPort(), 4242);
    cr_assert_str_eq(parser.getHostName().c_str(), "hostname");
}

Test(ParseCommandLine, command_correct_inverse, .timeout = 5)
{
    char *av[6];
    int ac = 5;

    av[0] = strdup("./zappy_gui");
    av[1] = strdup("-h");
    av[2] = strdup("hostname");
    av[3] = strdup("-p");
    av[4] = strdup("4242");
    av[5] = NULL;

    Gui::ParseCommandLine parser(ac, av);

    cr_assert_eq(parser.getPort(), 4242);
    cr_assert_str_eq(parser.getHostName().c_str(), "hostname");
}

Test(ParseCommandLine, command_too_long, .timeout = 5)
{
    char *av[7];
    int ac = 6;

    av[0] = strdup("./zappy_gui");
    av[1] = strdup("-h");
    av[2] = strdup("hostname");
    av[3] = strdup("-p");
    av[4] = strdup("4242");
    av[4] = strdup("4242");
    av[5] = NULL;

    bool test = false;
    try {
        Gui::ParseCommandLine parser(ac, av);
    } catch (const std::exception &error) {
        test = true;
    }
    cr_assert_eq(test, true);
}

Test(ParseCommandLine, no_hostname, .timeout = 5)
{
    char *av[7];
    int ac = 5;

    av[0] = strdup("./zappy_gui");
    av[1] = strdup("-p");
    av[2] = strdup("4242");
    av[3] = strdup("-p");
    av[4] = strdup("4242");
    av[5] = NULL;

    bool test = false;
    try {
        Gui::ParseCommandLine parser(ac, av);
    } catch (const std::exception &error) {
        test = true;
    }
    cr_assert_eq(test, true);
}

Test(ParseCommandLine, no_port, .timeout = 5)
{
    char *av[7];
    int ac = 5;

    av[0] = strdup("./zappy_gui");
    av[1] = strdup("-h");
    av[2] = strdup("hostname");
    av[3] = strdup("-h");
    av[4] = strdup("hostname");
    av[5] = NULL;

    bool test = false;
    try {
        Gui::ParseCommandLine parser(ac, av);
    } catch (const std::exception &error) {
        test = true;
    }
    cr_assert_eq(test, true);
}

Test(ParseCommandLine, wrong_flag, .timeout = 5)
{
    char *av[7];
    int ac = 5;

    av[0] = strdup("./zappy_gui");
    av[1] = strdup("-g");
    av[2] = strdup("hostname");
    av[3] = strdup("-h");
    av[4] = strdup("hostname");
    av[5] = NULL;

    bool test = false;
    try {
        Gui::ParseCommandLine parser(ac, av);
    } catch (const std::exception &error) {
        test = true;
    }
    cr_assert_eq(test, true);
}

Test(ParseCommandLine, wrong_port, .timeout = 5)
{
    char *av[7];
    int ac = 5;

    av[0] = strdup("./zappy_gui");
    av[1] = strdup("-p");
    av[2] = strdup("hostname");
    av[3] = strdup("-h");
    av[4] = strdup("hostname");
    av[5] = NULL;

    bool test = false;
    try {
        Gui::ParseCommandLine parser(ac, av);
    } catch (const std::exception &error) {
        test = true;
    }
    cr_assert_eq(test, true);
}