/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** main
*/

#include <iostream>
#include "Network/Network.hpp"
#include "Parsing/ServerParser.hpp"

int main()
{
    // std::cout << "Welcome to GUI" << std::endl;

    // Gui::ServerParser p;

    // std::vector<std::string>a =  p.parse("msz 1 2");

    // for (size_t i = 0; i < a.size(); i++)
    //     std::cout << a[i] << std::endl;

    Gui::Network net(8888, "127.0.0.1");
    net.connectToServer();

    while (1) {
        std::cout << net.listenServer();
    }

    return 0;
}
