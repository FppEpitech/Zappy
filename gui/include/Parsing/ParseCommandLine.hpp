/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** ParseCommandLine
*/

#pragma once

#include <string>

namespace Gui {

    /**
     * @brief Main GUI class.
     *
     */
    class ParseCommandLine;
};

class Gui::ParseCommandLine {

    public:

        /**
         * @brief Construct a new Parse Command Line object.
         *
         * @param argc Number of arguments in command line.
         * @param argv Array with command line arguments.
         */
        ParseCommandLine(int argc, char **argv);

        /**
         * @brief Destroy the Parse Command Line object.
         *
         */
        ~ParseCommandLine() = default;

        /**
         * @brief Get the port object.
         *
         * @return int - port
         */
        int getPort();

        /**
         * @brief Get the hostName object.
         *
         * @return std::string - hostName
         */
        std::string getHostName();

    private:

        int             _port;      // port server
        std::string     _hostName;  // host name server
};
