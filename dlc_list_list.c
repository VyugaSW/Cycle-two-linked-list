#include "dlc_list_list.h"

int dlc_ll_add_list(Dlc_list **lists, size_t size, unsigned long id, Dlc_list *adding_list){
    size_t add_i = size+1;
    for(size_t i = 0; i < size; ++i){
        if(!lists[i]){
            add_i = i;
            break;
        }
        else if(lists[i]->id == id) return -1;
    }
    
    if(add_i == size+1)
        return 0;

    if(!adding_list) lists[add_i] = dlc_list_init(id);
    else 
    {
        adding_list->id = id;
        lists[add_i] = adding_list;
    }

    return 1;
}

size_t dlc_ll_find_list(Dlc_list **lists, size_t size, unsigned long id){
    for(size_t j = 0; j < size; ++j)
        if(lists[j]){
            if(lists[j]->id == id)
            return j;
        }
           
    return size+1;
}

int dlc_ll_delete_list(Dlc_list **lists, size_t size, unsigned long id){
    size_t index = dlc_ll_find_list(lists, size, id);
    if(index <= size){
        dlc_list_free(&lists[index]);
        return 1;
    }

    return 0;
}

void dlc_ll_showAll(Dlc_list **lists, size_t size){
    for(size_t i = 0; i < size; ++i){
        if(lists[i]) dlc_list_print(lists[i], true);
    }
}

int dlc_ll_copy_list(Dlc_list **lists, size_t size, unsigned long id, unsigned long new_id){
    size_t index = dlc_ll_find_list(lists, size, id);
    if(index > size)
        return 0;

    Dlc_list *new_list = dlc_list_cpy(lists[index]);
    if(!dlc_ll_add_list(lists, size, new_id, new_list)){
        dlc_list_free(&new_list);
        return 0;
    }

    return 1;
}