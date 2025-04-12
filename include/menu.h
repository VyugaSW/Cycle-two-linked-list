#pragma once

#include <stdio.h>

#include "dlc_list.h"

#define MENU_MAIN_ITEMS 6 ///< Number of items in the main menu.
#define MENU_MENULIST_ITEMS 7 ///< Number of items in the list menu.
#define MENU_MAX_LISTS 20 ///< Maximum number of DLC lists that can be managed.

/**
 * @brief Gets an unsigned long input from the user.
 * 
 * This function prompts the user for an unsigned long integer input, 
 * validates the input, and returns the parsed value.
 * 
 * @param prompt The prompt message to display to the user.
 * @return unsigned long The validated unsigned long input from the user.
 */
unsigned long menu_get_ul_input(const char *prompt);

/**
 * @brief Gets an integer input from the user.
 * 
 * This function prompts the user for an integer input, validates the input, 
 * and returns the parsed value.
 * 
 * @param prompt The prompt message to display to the user.
 * @return int The validated integer input from the user.
 */
int menu_get_int_input(const char *prompt);

/**
 * @brief Renders the list menu for a specific DLC list.
 * 
 * This function displays a menu for interacting with a specific DLC list, allowing 
 * the user to add, delete, or move elements within the list.
 * 
 * @param list Pointer to the DLC list to operate on.
 * @return int Returns 0 when the user chooses to return to the main menu.
 */
int menu_list_render(Dlc_list *list);

/**
 * @brief Renders the main menu for managing DLC lists.
 * 
 * This function displays the main menu, allowing the user to create, show, delete, 
 * select, or copy DLC lists.
 * 
 * @return int Returns 0 when the user chooses to exit the program.
 */
int menu_main_render();