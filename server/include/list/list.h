/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Function about list
*/

#pragma once

#include <stdbool.h>

#include "type.h"

/**
 * @brief Create a new list.
 *
 * @return list_t * List initialized.
 */
list_t *list_new(void);

/**
 * @brief Free/Destruct the list.
 *
 * @param list List to free.
 */
void list_free(list_t *list);

/**
 * @brief Delete the node of the list.
 *
 * @param list List where delete the node.
 * @param node Node to delete.
 */
void list_delete(list_t *list, list_node_t *node);

/**
 * @brief Remove the first node of the list.
 *
 * @param list List where remove the first node.
 */
void list_remove_front(list_t *list);

/**
 * @brief Remove the last node of the list.
 *
 * @param list List where remove the last node.
 */
void list_remove_back(list_t *list);

/**
 * @brief Add a node a the back of the list.
 *
 * @param list List where add the new node.
 * @param data Node to add at the back.
 * @return bool true if succes else false.
 */
bool list_add_back(list_t *list, node_data_t data);

/**
 * @brief Add a node a the front of the list.
 *
 * @param list List where add the new node.
 * @param data Node to add at the front.
 * @return bool true if succes else false.
 */
bool list_add_front(list_t *list, node_data_t data);
