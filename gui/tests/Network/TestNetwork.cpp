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

Test(Network_good_port, socket, .timeout = 5)
{
    Gui::Network net(4242, "127.0.0.1");

    cr_assert_eq(net.getPort(), 4242);
}

Test(Network_wrong_port, socket, .timeout = 5)
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

Test(Network_hostname_number, socket, .timeout = 5)
{
    Gui::Network net(4242, "127.0.0.1");

    cr_assert_eq(net.getHostName(), "127.0.0.1");
}

Test(Network_hostname_text, socket, .timeout = 5)
{
    Gui::Network net(4242, "hostname");

    cr_assert_eq(net.getHostName(), "hostname");
}
