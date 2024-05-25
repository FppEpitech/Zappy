/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** test Network
*/

#include "Network/Network.hpp"

#include <criterion/criterion.h>
#include <criterion/redirect.h>


// Port tests

Test(network, Network_good_port, .timeout = 5)
{
    Gui::Network net(4242, "127.0.0.1");

    cr_assert_eq(net.getPort(), 4242);
}

Test(network, Network_wrong_port, .timeout = 5)
{
    bool test = false;

    try {
        Gui::Network net(0, "127.0.0.1");
    } catch (const std::exception &error) {
        test = true;
    }
    cr_assert(test);
}

// Hostname tests

Test(network, Network_hostname_number, .timeout = 5)
{
    Gui::Network net(4242, "127.0.0.1");

    cr_assert_eq(net.getHostName(), "127.0.0.1");
}

Test(network, Network_hostname_text, .timeout = 5)
{
    Gui::Network net(4242, "hostname");

    cr_assert_eq(net.getHostName(), "hostname");
}

// Connect to server

Test(network, Network_connect_to_wrong_server, .timeout = 5)
{
    std::string test;

    try {
        Gui::Network net(40000, "127.0.0.1");
        net.connectToServer();
    } catch (const std::exception &error) {
        test = error.what();
    }
    cr_assert_str_eq(test.c_str(), "Failed to connect to the server.");
}
