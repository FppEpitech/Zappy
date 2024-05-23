/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Network
*/

#include "Network/Network.hpp"

Gui::Network::Network(int port, const std::string& hostName)
{
    setPort(port);
    setHostName(hostName);
}

void Gui::Network::setPort(int port)
{
    if (port == 0)
        throw Errors::Network("Port should not be equal to 0.");
    _port = port;
}

void Gui::Network::setHostName(const std::string& hostName)
{
    _hostName = hostName;
}

int Gui::Network::getPort() const
{
    return _port;
}

std::string Gui::Network::getHostName() const
{
    return _hostName;
}
