/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** ai
*/

#include "server/client.h"
#include "gui/communication.h"

static bool command_already_in_buffer(gui_t *gui, char *line)
{
    list_node_t *tmp_cmd = gui->list_command->first;

    while (tmp_cmd) {
        if (strcmp(tmp_cmd->data.command, line) == 0)
            return true;
        tmp_cmd = tmp_cmd->next;
    }
    return false;
}

void add_command_to_gui_list(gui_t *gui, char *line)
{
    node_data_t node;

    if (command_already_in_buffer(gui, line))
        return;
    node.command = line;
    list_add_back(gui->list_command, node);
}

static void launch_gui_cmd(gui_t *gui, app_t *app)
{
    list_node_t *tmp = gui->list_command->first;
    char *command = NULL;

    while (tmp) {
        command = tmp->data.command;
        handle_command_gui(gui, app, command);
        free(command);
        list_remove_front(gui->list_command);
        tmp = gui->list_command->first;
    }
}

void treat_gui_command(app_t *app)
{
    list_node_t *temp_gui = app->gui_list->first;
    gui_t *gui = NULL;

    while (temp_gui) {
        gui = temp_gui->data.gui;
        launch_gui_cmd(gui, app);
        temp_gui = temp_gui->next;
    }
}
