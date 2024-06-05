/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Types for the server
*/

#pragma once

/**
 * @brief Struct for parsing the arguments.
 *
 */
typedef struct s_parsing {
    int port;
    int width;
    int height;
    int clientsNb;
    int freq;
    char **names;
} parsing_t;
