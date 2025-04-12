/**
 * @file dlc_list.h
 * @brief Header for doubly linked circular list implementation
 */

#pragma once

#include <stdio.h>
#include "Node.h"

/**
 * @brief Doubly linked circular list structure
 * 
 * Contains an identifier, pointer to current node, and count of elements
 */
typedef struct Dlc_list {
    unsigned long id;    ///< Unique identifier for the list
    Node *current;      ///< Pointer to current node in the list
    size_t count;       ///< Number of nodes in the list
} Dlc_list;

/**
 * @brief Initialize a new doubly linked circular list
 * @param id Unique identifier for the list
 * @return Pointer to newly created list
 * @note Caller is responsible for freeing the list with dlc_list_free()
 */
Dlc_list *dlc_list_init(unsigned long id);

/**
 * @brief Free all memory allocated for the list
 * @param list Double pointer to the list to free
 * @warning Sets the list pointer to NULL after freeing
 */
void dlc_list_free(Dlc_list **list);

/**
 * @brief Create a deep copy of a list
 * @param src Source list to copy
 * @return Pointer to new copied list
 * @note Returns NULL if source list is empty
 */
Dlc_list *dlc_list_cpy(Dlc_list *src);

/**
 * @brief Insert a new node after current node
 * @param list List to modify
 * @param new_node Node to insert
 * @warning Does nothing if list or new_node is NULL
 */
void dlc_list_insertAfter(Dlc_list *list, Node *new_node);

/**
 * @brief Insert a new node before current node
 * @param list List to modify
 * @param new_node Node to insert
 * @warning Does nothing if list or new_node is NULL
 */
void dlc_list_insertBefore(Dlc_list *list, Node *new_node);

/**
 * @brief Delete the current node from the list
 * @param list List to modify
 * @warning Does nothing if list is NULL or empty
 * @note Moves current pointer to next node after deletion
 */
void dlc_list_deleteCurrent(Dlc_list *list);

/**
 * @brief Print list contents to stdout
 * @param list List to print
 * @param direction Print direction (true=forward, false=backward)
 */
void dlc_list_print(Dlc_list *list, bool direction);

/**
 * @brief Move current pointer forward
 * @param list List to modify
 * @note Current becomes current->next
 */
void dlc_list_moveCurrent_forward(Dlc_list *list);

/**
 * @brief Move current pointer backward
 * @param list List to modify
 * @note Current becomes current->prev
 */
void dlc_list_moveCurrent_backward(Dlc_list *list);