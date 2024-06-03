/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** main
*/

#include <stdio.h>

#include "server/server.h"

int main(void)
{
    printf("Welcome to Server\n");
    server_t *server = create_server(4444);

    server_run(server);
    // int client_fd = 0;
    // while (true) {
    //     FD_ZERO(&server->read_fds);
    //     FD_ZERO(&server->write_fds);
    //     FD_SET(server->server_fd, &server->read_fds);
    //     FD_SET(client_fd, &server->read_fds);
    //     FD_SET(client_fd, &server->write_fds);
    //     if (select(FD_SETSIZE, &server->read_fds,
    //     &server->write_fds, NULL, NULL) < 0) {
    //         return 84;
    //     }
    //     for (int fd = 0; fd < FD_SETSIZE; fd++) {
    //         if (FD_ISSET(fd, &server->read_fds)) {
    //             if (fd == server->server_fd) {
    //                 socklen_t addr_len = sizeof(struct sockaddr_in);
    //                 struct sockaddr_in addr;
    //                 client_fd = accept(fd, (struct sockaddr *)&addr, &addr_len);
    //                 printf("NEW CONNECTION !\n");
    //             } else {
    //                 printf("New data\n");
    //                 char buffer[1024 + 1] = {0};
    //                 ssize_t bytes_read = 0;

    //                 bytes_read = read(fd, buffer, 1024);
    //                 if (bytes_read <= 0)
    //                     return 84;
    //                 buffer[bytes_read] = '\0';
    //                 printf("DATA: [%s]\n", buffer);
    //             }
    //         }
    //     }
    // }
    return 0;
}
