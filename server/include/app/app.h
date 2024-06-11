/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** App
*/

#pragma once

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <signal.h>

#include "ai/ai.h"
#include "ai/team.h"
#include "gui/gui.h"
#include "parsing.h"
#include "ai/stuck.h"
#include "list/list.h"
#include "game/game.h"
#include "server/server.h"

typedef struct s_app {
    list_t *gui_list;
    list_t *teams_list;
    list_t *clients_list;
    server_t *server;
    game_t *game;
} app_t;

/**
 * @brief Create application struct.
 *
 * @param parsing Parsing struct with all necessary information.
 * @return app_t* Return app initialized.
 */
app_t *create_app(parsing_t *parsing);

/**
 * @brief Destroy application struct.
 *
 * @param app App to destroy.
 */
void destroy_app(app_t *app);
