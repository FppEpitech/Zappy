/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Network
*/

#include "Config.hpp"
#include "Colors.hpp"
#include "Network/Network.hpp"

#include <unistd.h>
#include <iostream>

Gui::Network::Network(int port, const std::string &hostName) : ANetwork(port, hostName)
{
    _isConnected = false;
}

Gui::Network::~Network()
{
    close(_serverFd);
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
        throw Errors::NetworkException("Failed to connect to the server.");
}

void Gui::Network::selectServer()
{
    FD_ZERO(&_writeFd);
    FD_ZERO(&_readFd);
    FD_SET(_serverFd, &_readFd);
    FD_SET(_serverFd, &_writeFd);

    if (!select(_serverFd + 1, &_readFd, &_writeFd, NULL, NULL))
        throw Errors::NetworkException("Select failed.");
}

Gui::Network::BufferState Gui::Network::listenServer()
{
    selectServer();
    BufferState bufferSate = readInfoServer();
    if (!_isConnected && _buffer == "WELCOME" && bufferSate == READY) {
        sendMessageServer("GRAPHIC\n");
        sendMessageServer("sgt\n");
        sendMessageServer("msz\n");
        sendMessageServer("mct\n");
        sendMessageServer("tna\n");
        _isConnected = true;
        _buffer = "";
        return Gui::Network::NONE;
    }
    return bufferSate;
}

Gui::Network::BufferState Gui::Network::readInfoServer()
{
    char buffer;
    int len;

    if (!FD_ISSET(_serverFd, &_readFd))
        return NONE;
    while ((len = read(_serverFd, &buffer, 1)) > 0) {
        if (buffer == '\n')
            return READY;
        _buffer.append(&buffer, 1);
    }
    if (len == 0)
        return SERVER_ERROR;
    return NONE;
}

void Gui::Network::sendMessageServer(const std::string &message)
{
    if (FD_ISSET(_serverFd, &_writeFd)) {
        write(_serverFd, message.c_str(), message.length());
        std::cerr << STR_VIOLET << "Send: " << STR_CYAN << message << STR_RESET << std::endl;
    }
}
