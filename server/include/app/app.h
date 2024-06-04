/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** App struct
*/

#pragma once

#include <string.h>

#include "ia/ia.h"
#include "ia/team.h"
#include "gui/gui.h"
#include "list/list.h"
#include "server/server.h"

typedef struct s_app {
    list_t *gui_list;
    list_t *teams_list;
    list_t *clients_list;
    server_t *server;
} app_t;

/**
 * @brief Create application struct.
 *
 * @param port Port on witch create server.
 * @return app_t* Return app initialized.
 */
app_t *create_app(size_t port);

/**
 * @brief Destroy application struct.
 *
 * @param app App to destroy.
 */
void destroy_app(app_t *app);
