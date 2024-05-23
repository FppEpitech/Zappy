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
         * @class ArgumentNumber
         * @brief Error class for network errors.
         */
        class Network : public Error {
            public:
                /**
                 * @brief Constructor for Network.
                 * @param message The error message.
                 */
                Network(std::string message) { _message = message; }
        };
    };
};
