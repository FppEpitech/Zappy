/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Network
*/

#include "Network/Network.hpp"

#include <unistd.h>
#include <iostream>

Gui::Network::Network(int port, const std::string& hostName)
{
    setPort(port);
    setHostName(hostName);
    _startNetwork = true;
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

void Gui::Network::connectToServer()
{
    _serverFd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serveraddr;
    int len;

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(_port);
    serveraddr.sin_addr.s_addr = inet_addr(_hostName.c_str());
    len = sizeof(serveraddr);
    if (connect(_serverFd, (struct sockaddr *)&serveraddr, len) != 0)
        throw Errors::Network("Failed to connect to the server.");
}

void Gui::Network::selectServer()
{
    FD_ZERO(&_writeFd);
    FD_ZERO(&_readFd);
    FD_SET(_serverFd, &_readFd);
    FD_SET(_serverFd, &_writeFd);

    if (!select(_serverFd + 1, &_readFd, &_writeFd, NULL, NULL))
        throw Errors::Network("Select failed.");
}
