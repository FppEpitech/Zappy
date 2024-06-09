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
    if (strcmp("Incantation", line) == 0) {
        printf("Check incantation begin\n");
        if (check_incantation(app, ai, BEGIN) == false) {
            printf("FAILD at begin verification\n");
            return false;
        }
        printf("SUCCESS at begin verification\n");
        update_status(app, ai);
        if (check_incantation(app, ai, END) == false) {
            printf("FAILD at end verification\n");
            return false;
        }
        printf("SUCCESS at end verification\n");
        level_up(app, ai);
        printf("Level up succefully\n");
        return true;
    }
    return false;
}
