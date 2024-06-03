/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Read data
*/

#include <string.h>

#include "server/server.h"

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
    while (bytes_received > 0) {
        if (buffer[0] == '\n') {
            line = append_char(line, buffer[0]);
            break;
        }
        line = append_char(line, buffer[0]);
        memset(buffer, 0, sizeof(buffer));
        bytes_received = read(fd, buffer, 1);
    }
    return line;
}

bool server_data_handler(app_t *app, size_t fd)
{
    (void) app;
    char buffer[1024 + 1] = {0};
    ssize_t bytes_read = 0;

    bytes_read = read(fd, buffer, 1024);
    if (bytes_read <= 0)
        return false;
    buffer[bytes_read] = '\0';
    printf("DATA: [%s]\n", buffer);
    return true;
}
