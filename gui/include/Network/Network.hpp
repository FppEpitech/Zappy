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

#define MAX_PORT 65535
#define MIN_PORT 1

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
         * @param port Port of the server.
         * @param hostName Host of the server.
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
         * @param port Port of the server.
         */
        void setPort(int port);

        /**
         * @brief Set the host name object.
         *
         * @param hostName Host of the server.
         */
        void setHostName(const std::string& hostName);

        /**
         * @brief Get the port object.
         *
         * @return const int - Port of the server.
         */
        int getPort() const;

        /**
         * @brief Get the host name object.
         *
         * @return const std::string - Host name of the server.
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
         * @return std::string - Message of the server.
         */
        const std::string listenServer();

        /**
         * @brief Send a message to the Server.
         *
         * @param message Message to send to the server.
         */
        void sendMessageServer(const std::string& message);

    private:

        /**
         * @brief Listen if there is a server event.
         *
         */
        void selectServer();

        /**
         * @brief Read the server output.
         *
         * @return const std::string - Server message.
         */
        const std::string readInfoServer();

        int             _port;          // server port
        std::string     _hostName;      // server hostname
        int             _serverFd;      // server file descriptor
        fd_set          _writeFd;       // file descriptor for write access
        fd_set          _readFd;        // file descriptor for read access
        bool            _isConnected;   // is true if the gui is connected to the server
};
