#include "menu.h"
#include "dlc_list.h"
#include "dlc_list_list.h"


void menu_setColor(WORD color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

unsigned long menu_get_ul_input(const char *prompt) {
    char buf[32], *end;
    
    while (1) {
        printf("%s", prompt);
        if (!fgets(buf, sizeof(buf), stdin)) { fprintf(stderr, "Input error\n"); exit(EXIT_FAILURE); }
        buf[strcspn(buf, "\n")] = 0;
        
        errno = 0;
        unsigned long val = strtoul(buf, &end, 10);
        
        if (end == buf || *end) printf("Invalid number. Try again.\n");
        else if (errno == ERANGE) printf("Maximum: %lu\n", ULONG_MAX);
        else return val;
    }
}

int menu_get_int_input(const char *prompt) {
    char buf[32], *end;
    long val;
    
    while (1) {
        printf("%s", prompt);
        if (!fgets(buf, sizeof(buf), stdin)) { fprintf(stderr, "Input error\n"); exit(EXIT_FAILURE); }
        buf[strcspn(buf, "\n")] = 0; 
        
        errno = 0;
        val = strtol(buf, &end, 10);
        
        if (end == buf || *end) printf("Invalid number. Try again.\n");
        else if (errno == ERANGE || val < INT_MIN || val > INT_MAX) printf("Range: %d to %d\n", INT_MIN, INT_MAX);
        else return (int)val;
    }
}

int menu_list_render(Dlc_list *list){
     char *menuItems[MENU_MENULIST_ITEMS] = {
        "1. Add element after current",
        "2. Add element before current",
        "3. Show list",
        "4. Delete current element",
        "5. Move current forward",
        "6. Move current backward",
        "7. Return"
    };
    
    int currentSelection = 0;
    int keyPressed = 0;

    while (1) {
        system("cls");  
        
        printf("=== List menu (id list: %lu) ===\n\n", list->id);
        
        for (int i = 0; i < MENU_MENULIST_ITEMS; i++) {
            if (i == currentSelection) {
                menu_setColor(117);  
                printf("> %s <\n", menuItems[i]);
                menu_setColor(7);    
            } else {
                printf("  %s\n", menuItems[i]);
            }
        }
        
        printf("\nUse arrows for choice. Use enter to submit choice.\n");
        
        keyPressed = _getch();
        
        if (keyPressed == 0 || keyPressed == 224) {
            keyPressed = _getch();  
            
            switch (keyPressed) {
                case 72:  
                    currentSelection--;
                    if (currentSelection < 0) currentSelection = MENU_MENULIST_ITEMS - 1;
                    break;
                case 80:  
                    currentSelection++;
                    if (currentSelection >= MENU_MENULIST_ITEMS) currentSelection = 0;
                    break;
            }
        }

        else if (keyPressed == 13) {
            system("cls");
            printf("Choice: %s\n\n", menuItems[currentSelection]);
            int val = 0;
            switch (currentSelection) {
                case 0:
                    ;
                    val = menu_get_int_input("Enter the value of the element: ");
                    dlc_list_insertAfter(list, node_init(val));
                    printf("Element is inserted!\n");
                    break;
                case 1:
                    ;
                    val = menu_get_int_input("Enter the value of the element: ");
                    dlc_list_insertBefore(list, node_init(val));
                    printf("Element is inserted!\n");
                    break;
                case 2:
                    dlc_list_print(list,true);
                    break;
                case 3:
                    if(list->count == 0)
                        printf("List is empty.\n");
                    else{
                        dlc_list_deleteCurrent(list);
                        printf("Current is deleted!\n");
                    }

                    break;
                case 4:
                    if(!list->current)
                        printf("List is empty.\n");
                    else{
                        dlc_list_moveCurrent_forward(list);
                        printf("Current is moved!\n");
                    }
                    break;
                case 5:
                    if(!list->current)
                        printf("List is empty.\n");
                    else{
                        dlc_list_moveCurrent_backward(list);
                        printf("Current is moved!\n");
                    }
                    break;
                case 6:  
                    return 0;
            }
            
            printf("\nPress any key to return to menu.\n");
            _getch();
        }
    }
}

int menu_main_render(){
    char *menuItems[MENU_MAIN_ITEMS] = {
        "1. Create new list",
        "2. Show all lists",
        "3. Delete list",
        "4. Select list by id",
        "5. Copy list",
        "6. Exit"
    };
    
    int currentSelection = 0;
    int keyPressed = 0;
    unsigned long last_index = 0;
    Dlc_list *lists[MENU_MAX_LISTS] = {0};

    while (1) {
        system("cls");  
        
        printf("=== Main menu ===\n\n");
        
        for (int i = 0; i < MENU_MAIN_ITEMS; i++) {
            if (i == currentSelection) {
                menu_setColor(117);  
                printf("> %s <\n", menuItems[i]);
                menu_setColor(7);    
            } else {
                printf("  %s\n", menuItems[i]);
            }
        }
        
        printf("\nUse arrows for choice. Use enter to submit choice.\n");
        
        keyPressed = _getch();
        
        if (keyPressed == 0 || keyPressed == 224) {
            keyPressed = _getch();  
            
            switch (keyPressed) {
                case 72:  
                    currentSelection--;
                    if (currentSelection < 0) currentSelection = MENU_MAIN_ITEMS - 1;
                    break;
                case 80:  
                    currentSelection++;
                    if (currentSelection >= MENU_MAIN_ITEMS) currentSelection = 0;
                    break;
            }
        }

        else if (keyPressed == 13) {
            system("cls");
            printf("Choice: %s\n\n", menuItems[currentSelection]);
            
            unsigned long input_id = 0;
            switch (currentSelection) {
                case 0:
                    ;
                    int res = dlc_ll_add_list(lists, MENU_MAX_LISTS, last_index++, NULL);
                    if(res == 1)
                        printf("New list was added!\n");
                    else if(res == -1)
                        printf("Such id already exists.\n");
                    else
                        printf("List of lists is full!\n");

                    break;
                case 1:
                    dlc_ll_showAll(lists, MENU_MAX_LISTS);
                    break;
                case 2:
                    ;
                    input_id = menu_get_ul_input("Enter the list id for deleting: ");
                    if(dlc_ll_delete_list(lists, MENU_MAX_LISTS, input_id))
                        printf("List was deleted");
                    else
                        printf("Deleting id does not exist.\n");

                    break;
                case 3:
                    ;
                    input_id =  menu_get_ul_input("Enter the list id for selection: ");
                    unsigned long selected_index = (unsigned long)dlc_ll_find_list(lists, MENU_MAX_LISTS, input_id);
                    if(selected_index <= MENU_MAX_LISTS){
                        menu_list_render(lists[selected_index]);
                    }
                    else
                        printf("There isnt list with such id: %lu\n", input_id);

                    break;
                case 4:
                    ;
                    input_id = menu_get_ul_input("Enter the list id for copying: ");
                    if(dlc_ll_copy_list(lists, MENU_MAX_LISTS, input_id, last_index++))
                        printf("List was copied. Copy list id is: %lu", last_index-1);
                    else
                        printf("List with id: %lu does not exist", input_id);

                    break;
                case 5:  
                    return 0;
            }
            
            printf("\nPress any key to return to menu.\n");
            _getch();
        }
    }
}

