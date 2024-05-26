/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** test Msz command
*/

#include "Parsing/ServerParser.hpp"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(ParseServer, unknown_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("unknown command");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Server's command didn't exist.");
}

// command msz

Test(ParseServer, correct_msz_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("msz 1 2");

    cr_assert_eq(test[0], "1");
    cr_assert_eq(test[1], "2");
}

Test(ParseServer, correct_msz_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("msz 1 2 3");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'msz' command.");
}

Test(ParseServer, correct_msz_wrong, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("msz 1 wrong");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'msz' command.");
}
