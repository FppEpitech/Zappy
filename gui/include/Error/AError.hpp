/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** AError
*/


#pragma once

#include "IError.hpp"
#include <string>

namespace Gui {
    namespace Errors {
        /**
         * @class AError
         * @brief Base class for custom error types.
         * This class is derived from the `IError` interface and provides a common base for custom error types.
         * It contains a protected member `_message` to store the error message.
         */
        class AError;
    };
};

class Gui::Errors::AError : public IError {

    public:

        /**
         * @brief Destructor.
         */
        ~AError() override = default;

        /**
         * @brief Returns the error message.
         * @return A pointer to a constant character string representing the error message.
         */
        const char *what() const noexcept override { return _message.c_str(); }

    protected:

        std::string _message; /**< The error message. */
};
