/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** ParseCommandLine
*/

#pragma once

#include <string>

#define GUI_USAGE "USAGE:\t./zappy_gui -p port -h machine"

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
         * @brief Parse flags in command line.
         *
         * @param argc Number of arguments in command line.
         * @param argv Array with command line arguments.
         */
        void parseFlags(int argc, char **argv);

        /**
         * @brief Get the port object.
         *
         * @return int - port
         */
        int getPort(void);

        /**
         * @brief Get the hostName object.
         *
         * @return std::string - hostName
         */
        std::string getHostName(void);

    private:

        int             _port;      // port server
        std::string     _hostName;  // host name server
};
