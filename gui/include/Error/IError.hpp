/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** IError
*/

#pragma once

#include <exception>

namespace Gui {
    namespace Errors {
        /**
         * @brief The base class for all error types in the application.
         * This class inherits from std::exception and provides a common interface for all error types.
         * It declares a pure virtual function `what()` that must be implemented by derived classes.
         */
        class IError;
    };
};

class Gui::Errors::IError : public std::exception {

    public:

        /**
         * @brief Destructor for IError.
         */
        virtual ~IError() = default;

        /**
         * @brief Returns a C-style string describing the error.
         * This function must be implemented by derived classes to provide a description of the error.
         * The returned string should be null-terminated.
         *
         * @return const char* A C-style string describing the error.
         */
        virtual const char *what() const noexcept = 0;
};
