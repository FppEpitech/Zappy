/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Write data
*/

#include <string.h>

#include "app/app.h"
#include "list/list.h"

char *format_string(const char *format, ...)
{
    char *result;
    va_list args;
    int length;

    va_start(args, format);
    length = vsnprintf(NULL, 0, format, args);
    va_end(args);
    result = malloc(length + 1);
    if (result == NULL)
        return NULL;
    va_start(args, format);
    vsnprintf(result, length + 1, format, args);
    va_end(args);
    return result;
}

void add_message(list_t *list, char *message)
{
    node_data_t message_team;

    message_team.message = message;
    list_add_back(list, message_team);
}

static void check_died_ai(app_t *app, size_t fd)
{
    ia_t *ai = find_ia(app, fd);

    if (ai != NULL && ai->dead == true)
        free_ai(app, ai);
}

bool write_message(app_t *app, list_t *list_messages, size_t fd)
{
    list_node_t *tmp = NULL;
    ssize_t bytes_writted = 0;

    if (list_messages->len == 0)
        return true;
    tmp = list_messages->first;
    bytes_writted = write(fd, tmp->data.message,
    strlen(tmp->data.message));
    if (bytes_writted == -1)
        return false;
    free(tmp->data.message);
    list_remove_front(list_messages);
    check_died_ai(app, fd);
    return true;
}
