#pragma once

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Node structure for a doubly linked list
 * 
 * This structure represents a single node in a doubly linked list.
 * It contains an integer value and pointers to the next and previous nodes.
 */
typedef struct Node {
    int value;          ///< Integer value stored in the node
    struct Node *next;  ///< Pointer to the next node in the list
    struct Node *prev;  ///< Pointer to the previous node in the list
} Node;

/**
 * @brief Initialize a new node with given value
 * 
 * Allocates memory for a new node and initializes it with the specified value.
 * The next and prev pointers are set to NULL.
 * 
 * @param value The integer value to store in the new node
 * @return Pointer to the newly created node
 * @note The caller is responsible for freeing the node using node_free()
 */
Node *node_init(int value);

/**
 * @brief Free memory allocated for a node
 * 
 * Deallocates the memory used by a node structure.
 * 
 * @param node Pointer to the node to be freed
 * @warning Does not handle freeing of connected nodes (next/prev pointers)
 */
void node_free(Node *node);