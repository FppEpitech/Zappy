/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** AError
*/

#include "Error/Error.hpp"

const char *Gui::Errors::AError::what() const noexcept
{
    return _message.c_str();
}

Gui::Errors::Network::Network(std::string message)
{
    _message = message;
}

Gui::Errors::ServerParser::ServerParser(std::string message)
{
    _message = message;
}
