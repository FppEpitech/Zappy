/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** AError
*/

#include "Error/AError.hpp"

const char *Gui::Errors::AError::what() const noexcept
{
    return _message.c_str();
}
