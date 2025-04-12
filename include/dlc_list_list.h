#pragma once

#include "dlc_list.h"

/**
 * @brief Adds a new list to the DLC list array.
 * 
 * This function adds a new DLC list to the provided array of lists. 
 * If the list with the same ID already exists, the function returns an error.
 * 
 * @param lists Pointer to the array of DLC lists.
 * @param size The current size of the lists array.
 * @param id The ID for the new list being added.
 * @param adding_list Pointer to an existing DLC list to be added, or NULL to create a new one.
 * @return int Returns 1 on success, -1 if the list with the same ID already exists, or 0 if there is no space to add a new list.
 */
int dlc_ll_add_list(Dlc_list **lists, size_t size, unsigned long id, Dlc_list *adding_list);

/**
 * @brief Finds the index of a list by its ID in the DLC list array.
 * 
 * This function searches for a DLC list with the specified ID and returns its index.
 * 
 * @param lists Pointer to the array of DLC lists.
 * @param size The current size of the lists array.
 * @param id The ID of the list to find.
 * @return size_t Returns the index of the list if found, or size + 1 if not found.
 */
size_t dlc_ll_find_list(Dlc_list **lists, size_t size, unsigned long id);

/**
 * @brief Deletes a list from the DLC list array by its ID.
 * 
 * This function removes a DLC list with the specified ID from the array and frees its memory.
 * 
 * @param lists Pointer to the array of DLC lists.
 * @param size The current size of the lists array.
 * @param id The ID of the list to delete.
 * @return int Returns 1 on successful deletion, or 0 if the list was not found.
 */
int dlc_ll_delete_list(Dlc_list **lists, size_t size, unsigned long id);

/**
 * @brief Displays all lists in the DLC list array.
 * 
 * This function iterates through the array of DLC lists and prints each list that is not NULL.
 * 
 * @param lists Pointer to the array of DLC lists.
 * @param size The current size of the lists array.
 */
void dlc_ll_showAll(Dlc_list **lists, size_t size);

/**
 * @brief Copies a list from the DLC list array to a new ID.
 * 
 * This function creates a copy of the DLC list with the specified ID and assigns it a new ID.
 * 
 * @param lists Pointer to the array of DLC lists.
 * @param size The current size of the lists array.
 * @param id The ID of the list to copy.
 * @param new_id The ID to assign to the copied list.
 * @return int Returns 1 on success, or 0 if the original list was not found or if the addition failed.
 */
int dlc_ll_copy_list(Dlc_list **lists, size_t size, unsigned long id, unsigned long new_id);
