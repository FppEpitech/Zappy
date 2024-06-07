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

Gui::Errors::NetworkException::NetworkException(std::string message)
{
    _message = message;
}

Gui::Errors::ServerParserException::ServerParserException(std::string message)
{
    _message = message;
}

Gui::Errors::ParseCommandLineException::ParseCommandLineException(std::string message)
{
    _message = message;
}

Gui::Errors::GuiGameDataException::GuiGameDataException(std::string message)
{
    _message = message;
}

Gui::Errors::GuiUpdaterException::GuiUpdaterException(std::string message)
{
    _message = message;
}
