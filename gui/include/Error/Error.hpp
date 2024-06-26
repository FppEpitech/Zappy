/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Error
*/

#pragma once

#include "Error/AError.hpp"

namespace Gui {
    namespace Errors {

        /**
         * @class Error
         * @brief Base class for argument-related errors.
         */
        class Error : public AError {};

        /**
         * @class NetworkException
         * @brief Error class for network errors.
         */
        class NetworkException : public Error {

            public:
                /**
                 * @brief Constructor for NetworkException.
                 *
                 * @param message The error message.
                 */
                NetworkException(std::string message);
        };

        /**
         * @class ServerParserException
         * @brief Error class for network errors.
         */
        class ServerParserException : public Error {

            public:
                /**
                 * @brief Constructor for ServerParserException.
                 *
                 * @param message The error message.
                 */
                ServerParserException(std::string message);
        };

        /**
         * @class ParseCommandLineException
         * @brief Error class for parseCommandLine errors.
         */
        class ParseCommandLineException : public Error {

            public:
                /**
                 * @brief Constructor for ParseCommandLineException.
                 *
                 * @param message The error message.
                 */
                ParseCommandLineException(std::string message);
        };

        /**
         * @class GuiGameDataException
         * @brief Error class for GameData errors.
         */
        class GuiGameDataException : public Error {

            public:
                /**
                 * @brief Constructor for GuiGameDataException.
                 *
                 * @param message The error message.
                 */
                GuiGameDataException(std::string message);
        };

        /**
         * @class GuiUpdaterException
         * @brief Error class for GUIUpdater errors.
         */
        class GuiUpdaterException : public Error {

            public:
                /**
                 * @brief Constructor for GuiUpdaterException.
                 *
                 * @param message The error message.
                 */
                GuiUpdaterException(std::string message);
        };
    };
};
