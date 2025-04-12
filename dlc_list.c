#include "dlc_list.h"
#include <stdlib.h>

Dlc_list *dlc_list_init(unsigned long id){
    Dlc_list *list = malloc(sizeof(Dlc_list));
    if(!list){
        fprintf(stderr, "Dlc_list memory allocation failure!\n");
        exit(EXIT_FAILURE);
    }

    list->count = 0;
    list->current = NULL;
    list->id = id;

    return list;
}

void dlc_list_free(Dlc_list **list){
    if(!list){
        fprintf(stderr,"List is NULL. It cant be free.\n");
        return;
    }

    if(!(*list)->current){
        free(*list);
        (*list) = NULL;
        return;
    }

    Node* current = (*list)->current;
    Node* start = current;
    Node* temp;

    start->prev->next = NULL;
    current->prev = NULL;

    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != NULL);

    (*list)->current = NULL;
    (*list)->count = 0;

    free(*list);
    (*list) = NULL;

}

Dlc_list *dlc_list_cpy(Dlc_list *src){
    if(src->count == 0){
        return NULL;
    }

    Dlc_list *dst = dlc_list_init(_UI32_MAX);
    dst->count = src->count;

    Node* src_current = src->current;
    Node* first_copy = dst->current;
    Node* prev_copy = NULL;

    do{
        Node* new_node = node_init(src_current->value);

        dlc_list_insertBefore(dst,new_node);

        src_current = src_current->next;

    }while (src_current != src->current);

    if (first_copy) {
        first_copy->prev = prev_copy;
        prev_copy->next = first_copy;
    }

    return dst;
}

void dlc_list_insertAfter(Dlc_list *list, Node *new_node){
    if(!list || !new_node){
        fprintf(stderr, "Dlc_list insertion failure! List is null.\n");
        return;
    }  

    ++list->count;
    if (!list->current) {
        new_node->next = new_node;
        new_node->prev = new_node;
        list->current = new_node;
        return;
    }

    Node *old_next = list->current->next;

    list->current->next = new_node;
    new_node->prev = list->current;

    new_node->next = old_next;
    old_next->prev = new_node;  

    if (old_next == list->current) 
        list->current->prev = new_node;

}

void dlc_list_insertBefore(Dlc_list *list, Node *new_node){
    if(!list || !new_node){
        fprintf(stderr, "Dlc_list insertion failure! List is null.\n");
        return;
    }
    
    ++list->count;
    if (!list->current) {
        new_node->next = new_node;
        new_node->prev = new_node;
        list->current = new_node;
        return;
    }

    Node *old_prev = list->current->prev;

    new_node->next = list->current;
    list->current->prev = new_node;

    new_node->prev = old_prev;
    old_prev->next = new_node;  

    if (old_prev == list->current) 
        list->current->next = new_node;
    
}

void dlc_list_deleteCurrent(Dlc_list *list){
    if(!list || !list->current){
        fprintf(stderr,"List is null. Current cannot be deleted!\n");
        return;
    }

    Node *to_delete = list->current;
    Node *next_node = to_delete->next;
    Node *prev_node = to_delete->prev;

    if(next_node == to_delete && prev_node == to_delete) {
        list->current = NULL;
    }
    else {
        prev_node->next = next_node;
        next_node->prev = prev_node;
        
        list->current = next_node;
    }

    free(to_delete);
    to_delete = NULL;
    --list->count;
}

void dlc_list_print(Dlc_list *list, bool direction){
    Node *cur = list->current;

    printf("DLC list | Id : %lu\n",list->id);
    printf("Elements count: %zu\n",list->count);
    if(list->count > 0){
        do{ 
            printf(cur == list->current ? "value: %d <- current\n" : "value: %d\n", cur->value);
            cur = direction ? cur->next : cur->prev;
        }while(cur != list->current);
    }
    else
        printf("List is empty...\n");

    printf("\n");
}

void dlc_list_moveCurrent_forward(Dlc_list *list){
    list->current = list->current->next;
}

void dlc_list_moveCurrent_backward(Dlc_list *list){
    list->current = list->current->prev;
}