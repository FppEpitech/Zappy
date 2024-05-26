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

// Command bct

Test(ParseServer, correct_bct_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("bct 1 2 3 4 5 6 7 8 9");

    for (int i = 0; i < 9; i++)
        cr_assert_eq(test[i], std::to_string(i + 1).c_str());
}

Test(ParseServer, correct_bct_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("bct 1 2 3 4 5 6 7 8 9 10");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'bct' command.");
}

Test(ParseServer, correct_bct_wrong, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("bct 1 2 3.7 4 5 6 7 8 9");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'bct' command.");
}

// Command tna

Test(ParseServer, correct_tna_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("tna team");

    cr_assert_eq(test[0], "team");
}

Test(ParseServer, correct_tna_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("tna team team2");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'tna' command.");
}

Test(ParseServer, correct_tna_wrong, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("tna ");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'tna' command.");
}
