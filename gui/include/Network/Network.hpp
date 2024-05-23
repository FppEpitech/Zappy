/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Network
*/

#pragma once

#include "Error/Error.hpp"

#include <string>

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

    private:

        int             _port;
        std::string     _hostName;
};
