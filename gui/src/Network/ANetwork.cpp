/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ANetwork
*/

#include "Network/ANetwork.hpp"

Gui::ANetwork::ANetwork(int port, const std::string &hostName)
{
    this->setPort(port);
    this->setHostName(hostName);
}

void Gui::ANetwork::setPort(int port)
{
    if (port < MIN_PORT || port > MAX_PORT)
        throw Errors::NetworkException("Port should be in range 1 to 65535.");
    _port = port;
}

void Gui::ANetwork::setHostName(const std::string &hostName)
{
    this->_hostName = hostName;
}

int Gui::ANetwork::getPort() const
{
    return this->_port;
}

std::string Gui::ANetwork::getHostName() const
{
    return this->_hostName;
}

std::string Gui::ANetwork::getBuffer()
{
    std::string command = _buffer;
    _buffer = "";
    return command;
}
