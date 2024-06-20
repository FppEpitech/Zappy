/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Network
*/

#pragma once

#include "Network/ANetwork.hpp"

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

class Gui::Network : public Gui::ANetwork {

    public:

        /**
         * @brief Construct a new Network object.
         *
         * @param port Port of the server.
         * @param hostName Host of the server.
         */
        Network(int port, const std::string &hostName);

        /**
         * @brief Destroy the Network object.
         *
         */
        ~Network();

        /**
         * @brief Connect the Gui network with the server.
         *
         * @throw NetworkException If the connection failed.
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

        int             _serverFd;      // server file descriptor
        fd_set          _writeFd;       // file descriptor for write access
        fd_set          _readFd;        // file descriptor for read access
        bool            _isConnected;   // is true if the gui is connected to the server
};
