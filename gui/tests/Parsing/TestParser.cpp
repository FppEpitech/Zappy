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

// Command pex

Test(ParseServer, correct_pex_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("pex #1");

    cr_assert_eq(test[0], "1");
}

Test(ParseServer, pex_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pex #1 2");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'pex' command.");
}

Test(ParseServer, pex_wrong_hashtag, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pex 1");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'pex' command.");
}

Test(ParseServer, pex_wrong, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pex #wrong");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'pex' command.");
}

// Command pfk

Test(ParseServer, correct_pfk_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("pfk #1");

    cr_assert_eq(test[0], "1");
}

Test(ParseServer, pfk_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pfk #1 2");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'pfk' command.");
}

Test(ParseServer, pfk_wrong_hashtag, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pfk 1");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'pfk' command.");
}

Test(ParseServer, pfk_wrong, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pfk #wrong");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'pfk' command.");
}

// Command pdr

Test(ParseServer, correct_pdr_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("pdr #1 2");

    cr_assert_eq(test[0], "1");
    cr_assert_eq(test[1], "2");
}

Test(ParseServer, pdr_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pdr #1 2 3");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'pdr' command.");
}

Test(ParseServer, pdr_wrong_hashtag, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pdr 1 2");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'pdr' command.");
}

Test(ParseServer, pdr_wrong, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pdr #1 a");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'pdr' command.");
}

// Command pgt

Test(ParseServer, correct_pgt_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("pgt #1 2");

    cr_assert_eq(test[0], "1");
    cr_assert_eq(test[1], "2");
}

Test(ParseServer, pgt_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pgt #1 2 3");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'pgt' command.");
}

Test(ParseServer, pgt_wrong_hashtag, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pgt 1 2");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'pgt' command.");
}

Test(ParseServer, pgt_wrong, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pgt #1 a");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'pgt' command.");
}

// Command pdi

Test(ParseServer, correct_pdi_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("pdi #1");

    cr_assert_eq(test[0], "1");
}

Test(ParseServer, pdi_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pdi #1 2");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'pdi' command.");
}

Test(ParseServer, pdi_wrong_hashtag, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pdi 1");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'pdi' command.");
}

Test(ParseServer, pdi_wrong, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pdi #wrong");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'pdi' command.");
}

// Command enw

Test(ParseServer, correct_enw_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("enw #1 #2 3 4");

    cr_assert_eq(test[0], "1");
    cr_assert_eq(test[1], "2");
    cr_assert_eq(test[2], "3");
    cr_assert_eq(test[3], "4");
}

Test(ParseServer, enw_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("enw #1 #2 3 4 5");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'enw' command.");
}

Test(ParseServer, enw_wrong_hashtag_egg, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("enw 1 #2 3 4");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'enw' command.");
}

Test(ParseServer, enw_wrong_hashtag_player, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("enw #1 2 3 4");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'enw' command.");
}

Test(ParseServer, enw_wrong, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("enw #1 #2 wrong 4");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'enw' command.");
}

// Command ebo

Test(ParseServer, correct_ebo_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("ebo #1");

    cr_assert_eq(test[0], "1");
}

Test(ParseServer, ebo_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("ebo #1 2");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'ebo' command.");
}

Test(ParseServer, ebo_wrong_hashtag, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("ebo 1");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'ebo' command.");
}

Test(ParseServer, ebo_wrong, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("ebo #wrong");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'ebo' command.");
}

// Command edi

Test(ParseServer, correct_edi_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("edi #1");

    cr_assert_eq(test[0], "1");
}

Test(ParseServer, edi_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("edi #1 2");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'edi' command.");
}

Test(ParseServer, edi_wrong_hashtag, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("edi 1");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'edi' command.");
}

Test(ParseServer, edi_wrong, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("edi #wrong");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'edi' command.");
}

// Command sgt

Test(ParseServer, correct_sgt_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("sgt 1");

    cr_assert_eq(test[0], "1");
}

Test(ParseServer, sgt_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("sgt 1 2");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'sgt' command.");
}

Test(ParseServer, sgt_wrong, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("sgt wrong");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'sgt' command.");
}

// Command sst

Test(ParseServer, correct_sst_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("sst 1");

    cr_assert_eq(test[0], "1");
}

Test(ParseServer, sst_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("sst 1 2");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'sst' command.");
}

Test(ParseServer, sst_wrong, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("sst wrong");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'sst' command.");
}

// Command seg

Test(ParseServer, correct_seg_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("seg team");

    cr_assert_eq(test[0], "team");
}

Test(ParseServer, seg_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("seg team team2");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'seg' command.");
}

Test(ParseServer, seg_wrong, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("seg ");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'seg' command.");
}

// Command suc

Test(ParseServer, correct_suc_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("suc");

    cr_assert_eq(test.size(), 0);
}

Test(ParseServer, suc_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("suc long");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'suc' command.");
}


// Command sbp

Test(ParseServer, correct_sbp_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("sbp");

    cr_assert_eq(test.size(), 0);
}

Test(ParseServer, sbp_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("sbp long");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'sbp' command.");
}

// command pie

Test(ParseServer, correct_pie_command, .timeout = 5)
{
    Gui::ServerParser parser;
    std::vector<std::string> test;

    test = parser.parse("pie 1 2 0");

    cr_assert_eq(test[0], "1");
    cr_assert_eq(test[1], "2");
    cr_assert_eq(test[2], "0");
}

Test(ParseServer, pie_too_long, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pie 1 2 3 4");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Too many parameters for 'pie' command.");
}

Test(ParseServer, pie_wrong, .timeout = 5)
{
    Gui::ServerParser parser;
    std::string test;

    try {
        parser.parse("pie 1 wrong 0");
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Wrong parameters for 'pie' command.");
}
