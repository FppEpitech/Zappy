/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ANetwork
*/

#pragma once

#include "Network/INetwork.hpp"

#define MIN_PORT 1
#define MAX_PORT 65535

namespace Gui {

    /**
     * @brief Abstract class for the Network class.
     *
     */
    class ANetwork;
};

class Gui::ANetwork : public Gui::INetwork {
    public:

        /**
         * @brief Construct a new ANetwork object.
         *
         * @param port Port of the server.
         * @param hostName Host of the server.
         */
        ANetwork(int port, const std::string &hostName);

        /**
         * @brief Destroy the ANetwork object.
         *
         */
        ~ANetwork() = default;

        /**
         * @brief Set the port object.
         *
         * @param port Port of the server.
         * @throw NetworkException If the port is not in range 1 to 65535.
         */
        void setPort(int port) final;

        /**
         * @brief Set the host name object.
         *
         * @param hostName Host of the server.
         */
        void setHostName(const std::string &hostName) final;

        /**
         * @brief Get the host name object.
         *
         * @return std::string Host of the server.
         */
        int getPort() const final;

        /**
         * @brief Get the host name object.
         *
         * @return std::string Host of the server.
         */
        std::string getHostName() const final;

        /**
         * @brief Connect to the server.
         *
         * @throw NetworkException If the connection failed.
         */
        virtual void connectToServer() = 0;

        /**
         * @brief Listen the server and return it message.
         *
         * @return BufferState - Buffer state.
         */
        virtual BufferState listenServer() = 0;

        /**
         * @brief Send a message to the Server.
         *
         * @param message Message to send to the server.
         */
        virtual void sendMessageServer(const std::string& message) = 0;

        /**
         * @brief Get the Buffer object.
         * Be careful, this method will
         * delete the current buffer.
         *
         * @return std::string - Buffer message.
         */
        std::string getBuffer();

    protected:
        int             _port;          //!< Port of the server.
        std::string     _hostName;      //!< Host name of the server.
        std::string     _buffer;        //!< Buffer to receive server message.
};
