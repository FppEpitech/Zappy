/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Read data
*/

#include <string.h>

#include "ia/ia.h"
#include "app/app.h"
#include "server/client.h"

static char *append_char(char *line, char current_char)
{
    int len_line = 0;

    len_line = strlen(line);
    line = realloc(line, len_line + 2);
    line[len_line] = current_char;
    line[len_line + 1] = '\0';
    return line;
}

char *read_line(int fd)
{
    char buffer[1024];
    ssize_t bytes_received;
    char *line = malloc(sizeof(char) * 1);

    line[0] = '\0';
    memset(buffer, 0, sizeof(buffer));
    bytes_received = read(fd, buffer, 1);
    if (bytes_received <= 0)
        return NULL;
    while (bytes_received > 0) {
        if (buffer[0] == '\n')
            break;
        line = append_char(line, buffer[0]);
        memset(buffer, 0, sizeof(buffer));
        bytes_received = read(fd, buffer, 1);
    }
    return line;
}

bool server_data_handler(app_t *app, size_t fd)
{
    char *line = read_line(fd);

    if (line == NULL) {
        server_quit_handler(app, fd);
        printf("QUIT\n");
        return true;
    }
    if (its_client(app, fd)) {
        if (strcmp(line, "GRAPHIC\r") == 0) {
            add_gui(app, fd);
        } else {
            add_ia(app, fd, line);
        }
    } else {
        printf("DATA: [%s]\n", line);
        free(line);
    }
    return true;
}
