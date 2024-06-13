/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI incantation command
*/

#include "app/app.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"
#include "gui/communication.h"

bool incantation_command(app_t *app, ia_t *ai, char *line)
{
    list_t *list_ai = NULL;

    if (strcmp("Incantation", line) == 0) {
        printf("Check incantation begin\n");
        list_ai = check_incantation(app, ai, BEGIN_INCANTATION);
        if (list_ai == NULL) {
            printf("FAILD at begin verification\n");
            return false;
        }
        printf("SUCCESS at begin verification\n");
        update_status(app, ai, BEGIN_INCANTATION);
        pic_command(app, list_ai);
        return true;
    }
    return false;
}
