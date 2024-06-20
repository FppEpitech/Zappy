/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** INetwork
*/

#pragma once

#include "Error/Error.hpp"

#include <string>

namespace Gui {

    /**
     * @brief Interface for the Network class.
     *
     */
    class INetwork;
};

class Gui::INetwork {

    public:

        /**
         * @brief Destroy the INetwork object.
         *
         */
        virtual ~INetwork() = default;

        /**
         * @brief Set the port object.
         *
         * @param port Port of the server.
         * @throw NetworkException If the port is not in range 1 to 65535.
         */
        virtual void setPort(int port) = 0;

        /**
         * @brief Set the host name object.
         *
         * @param hostName Host of the server.
         */
        virtual void setHostName(const std::string &hostName) = 0;

        /**
         * @brief Get the host name object.
         *
         * @return std::string Host of the server.
         */
        virtual int getPort() const = 0;

        /**
         * @brief Get the host name object.
         *
         * @return std::string Host of the server.
         */
        virtual std::string getHostName() const = 0;

        /**
         * @brief Connect to the server.
         *
         * @throw Error::NetworkError If the connection failed.
         */
        virtual void connectToServer() = 0;

        /**
         * @brief Listen to the server.
         *
         * @return std::string Message from the server.
         */
        virtual const std::string listenServer() = 0;

        /**
         * @brief Send a message to the server.
         *
         * @param message Message to send.
         */
        virtual void sendMessageServer(const std::string &message) = 0;
};
