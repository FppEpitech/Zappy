/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Network
*/

#include "Network/Network.hpp"

#include <unistd.h>
#include <iostream>

#define MAX_PORT 65535
#define MIN_PORT 1

Gui::Network::Network(int port, const std::string& hostName)
{
    setPort(port);
    setHostName(hostName);
    _isConnected = false;
}

void Gui::Network::setPort(int port)
{
    if (port < MIN_PORT || port > MAX_PORT)
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

const std::string Gui::Network::listenServer()
{
    selectServer();
    std::string data = readInfoServer();
    if (!_isConnected && data == "WELCOME\n") {
        sendMessageServer("GRAPHIC\n");
        _isConnected = true;
        return "";
    }
    return data;
}

const std::string Gui::Network::readInfoServer()
{
    std::string data;
    char buffer;
    int len;

    if (!FD_ISSET(_serverFd, &_readFd))
        return "";
    while ((len = read(_serverFd, &buffer, 1)) > 0) {
        data.append(&buffer, 1);
        if (buffer == '\n')
            break;
    }
    return data;
}

void Gui::Network::sendMessageServer(const std::string& message)
{
    if (FD_ISSET(_serverFd, &_writeFd))
        write(_serverFd, message.c_str(), message.length());
}
