/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Server struct
*/

#pragma once

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/select.h>
#include <netinet/in.h>

#include "list/list.h"

#define LISTEN_NUMBER 100
#define WELCOME_MESSAGE "WELCOME\n"
#define WELCOME_MESSAGE_LEN 8
#define SELECT_TIMEOUT_SECONDS 1

typedef struct s_app app_t;

typedef struct s_server {
    fd_set read_fds;
    fd_set write_fds;
    int fd;
    socklen_t addrlen;
    struct sockaddr_in addr;
} server_t;

/**
 * @brief Destroy the server.
 *
 * @param server The server to destroy.
 */
void destroy_server(server_t *server);

/**
 * @brief Create a server object.
 *
 * @param port Port on witch bind server.
 * @return server_t* Server init.
 */
server_t *create_server(size_t port);

/**
 * @brief Run the server.
 *
 * @param app App struct with all necessary information (server, gui, client).
 * @return bool True if success else false.
 */
bool server_run(app_t *app);

/**
 * @brief Handler of server connection.
 *
 * @param app App struct with all necessary information (server, gui, client).
 * @param fd File Descriptor of th client who try to connect.
 * @return bool True if success else false.
 */
bool server_connection_handler(app_t *app, size_t fd);

/**
 * @brief Handler of server data reception.
 *
 * @param app App struct with all necessary information (server, gui, client).
 * @param fd File Descriptor of th client who try to connect.
 * @return bool True if success else false.
 */
bool server_data_handler(app_t *app, size_t fd);

/**
 * @brief Read a line from a file descriptor.
 *
 * @param fd File descriptor where read the line.
 * @return char* The line readed.
 */
char *read_line(int fd);

/**
 * @brief Handler to delete client/gui/ai who quit the server.
 *
 * @param app Application with all lists.
 * @param fd File descriptor of personn who quit.
 */
void server_quit_handler(app_t *app, size_t fd);

/**
 * @brief Write message to the correspondinf fd.
 *
 * @param list_messages List of all messages.
 * @param fd File descriptor where send message.
 * @param app Application with all necessary information.
 * @return true If message was well send.
 * @return false If message wasn't well send.
 */
bool write_message(app_t *app, list_t *list_messages, size_t fd);

/**
 * @brief Add a message to write.
 *
 * @param list List in witch add the message.
 * @param message Message to add in the list.
 */
void add_message(list_t *list, char *message);

/**
 * @brief Format a string with parameters.
 *
 * @param format Format of string.
 * @param ... All args to format in the string.
 * @return char* The string formated.
 */
char *format_string(const char *format, ...);

/**
 * @brief Reset fd on write and read list.
 *
 * @param app Application with list of read and write fd.
 */
void server_reset_fd(app_t *app);

/**
 * @brief Handle request of command from GUI or AI.
 *
 * @param app Application with list of AI and GUI.
 * @param fd File descriptor who do a request.
 * @param line Request.
 */
void handle_request(app_t *app, size_t fd, char *line);

/**
 * @brief Append a char to a string.
 *
 * @param line String where append a char.
 * @param current_char Char to append.
 * @return char* String with char append.
 */
char *append_char(char *line, char current_char);

/**
 * @brief Handler to write to the corresponding fd.
 *
 * @param app Application with all informations.
 * @param fd File descriptor to write.
 */
void handle_client_read(app_t *app, int fd);

/**
 * @brief Handler to read the corresponding fd.
 *
 * @param app Application with all informations.
 * @param fd File descriptor to read.
 */
void handle_client_write(app_t *app, int fd);

/**
 * @brief Create new vector2i object.
 *
 * @param x Coord x of new vector.
 * @param y Coord y of new vector.
 * @return vector2i_t* New vector.
 */
vector2i_t *create_vector2i(int x, int y);

/**
 * @brief Concat two string.
 *
 * @param str1 First strings.
 * @param str2 Second string to concat to the first.
 */
void concatenate_strings(char **str1, char *str2);

/**
 * @brief Destroy list of messages.
 *
 * @param message_list List of message to destroy.
 */
void destroy_message_list(list_t *message_list);


/**
 * @brief Destroy list of command.
 *
 * @param message_list List of command to destroy.
 */
void destroy_command_list(list_t *command_list);
