/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI incantation command
*/

#include "app/app.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

bool incantation_command(app_t *app, ia_t *ai, char *line)
{
    char *success = NULL;

    if (strcmp("Incantation", line) == 0) {
        printf("Check incantation begin\n");
        if (check_incantation(app, ai, BEGIN_INCANTATION) == false) {
            printf("FAILD at begin verification\n");
            return false;
        }
        printf("SUCCESS at begin verification\n");
        success = format_string("Elevation underway\n");
        add_message(ai->list_messages, success);
        update_status(app, ai, BEGIN_INCANTATION);
        return true;
    }
    return false;
}
