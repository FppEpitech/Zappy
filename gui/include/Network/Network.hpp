/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Network
*/

#pragma once

#include "Error/Error.hpp"

#include <string>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

namespace Gui {

    /**
     * @brief Network class to connect to the server.
     *
     */
    class Network;
};

class Gui::Network {

    public:

        /**
         * @brief Construct a new Network object.
         *
         * @param port of the server
         * @param hostName of the server
         */
        Network(int port, const std::string& hostName);

        /**
         * @brief Destroy the Network object.
         *
         */
        ~Network() = default;

        /**
         * @brief Set the port object.
         *
         * @param port of the server
         */
        void setPort(int port);

        /**
         * @brief Set the host name object.
         *
         * @param hostName of the server
         */
        void setHostName(const std::string& hostName);

        /**
         * @brief Get the port object.
         *
         * @return const int - port of the server
         */
        int getPort() const;

        /**
         * @brief Get the host name object.
         *
         * @return const std::string - host name of the server
         */
        std::string getHostName() const;

        /**
         * @brief Connect the Gui network with the server.
         *
         */
        void connectToServer();

        /**
         * @brief Listen the server and return it message.
         *
         * @return std::string - message of the server.
         */
        const std::string listenServer();

    private:
        void selectServer();
        const std::string readInfoServer();

        void sendMessageServer(const std::string& message);

        int             _port;
        std::string     _hostName;
        int             _serverFd;
        fd_set          _writeFd;
        fd_set          _readFd;
        bool            _isConnected;
};
