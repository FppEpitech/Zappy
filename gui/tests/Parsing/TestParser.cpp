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

Test(ParseServer, msz_too_long, .timeout = 5)
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

Test(ParseServer, msz_wrong, .timeout = 5)
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

Test(ParseServer, bct_too_long, .timeout = 5)
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

Test(ParseServer, bct_wrong, .timeout = 5)
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

Test(ParseServer, tna_too_long, .timeout = 5)
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

Test(ParseServer, tna_wrong, .timeout = 5)
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

// Command pnw

Test(ParseServer, correct_pnw_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("pnw #1 2 3 4 5 team");

    cr_assert_eq(test[0], "1");
    cr_assert_eq(test[1], "2");
    cr_assert_eq(test[2], "3");
    cr_assert_eq(test[3], "4");
    cr_assert_eq(test[4], "5");
    cr_assert_eq(test[5], "team");
}

Test(ParseServer, pnw_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pnw #1 2 3 4 5 team team2");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'pnw' command.");
}

Test(ParseServer, pnw_wrong_hashtag, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pnw 1 2 3 4 5 team");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'pnw' command.");
}

Test(ParseServer, pnw_wrong, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pnw #1 2 wrong 4 5 team");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'pnw' command.");
}

// Command ppo

Test(ParseServer, correct_ppo_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("ppo #1 2 3 4");

    cr_assert_eq(test[0], "1");
    cr_assert_eq(test[1], "2");
    cr_assert_eq(test[2], "3");
    cr_assert_eq(test[3], "4");
}

Test(ParseServer, ppo_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("ppo #1 2 3 4 5");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'ppo' command.");
}

Test(ParseServer, ppo_wrong_hashtag, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("ppo 1 2 3 4");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'ppo' command.");
}

Test(ParseServer, ppo_wrong, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("ppo #1 2 wrong 4");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'ppo' command.");
}

// Command plv

Test(ParseServer, correct_plv_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("plv #1 2");

    cr_assert_eq(test[0], "1");
    cr_assert_eq(test[1], "2");
}

Test(ParseServer, plv_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("plv #1 2 3");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'plv' command.");
}

Test(ParseServer, plv_wrong_hashtag, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("plv 1 2");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'plv' command.");
}

Test(ParseServer, plv_wrong, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("plv #1 wrong");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'plv' command.");
}

// Command pin

Test(ParseServer, correct_pin_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("pin #1 2 3 0 1 2 3 4 5 6");

    cr_assert_eq(test[0], "1");
    cr_assert_eq(test[1], "2");
    cr_assert_eq(test[2], "3");
    for (int i = 0; i < 7; i++)
        cr_assert_eq(test[i + 3], std::to_string(i).c_str());
}

Test(ParseServer, pin_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pin #1 2 3 0 1 2 3 4 5 6 7");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'pin' command.");
}

Test(ParseServer, pin_wrong_hashtag, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pin 1 2 3 0 1 2 3 4 5 6");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'pin' command.");
}

Test(ParseServer, pin_wrong, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pin #1 2 3 0 1 2 wrong 4 5 6");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'pin' command.");
}