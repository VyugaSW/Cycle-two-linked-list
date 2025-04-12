#include "node.h"
#include <stdlib.h>

Node *node_init(int value){
    Node *node = malloc(sizeof(Node));
    if(!node){
        fprintf(stderr, "Node memory allocation failure!\n");
        exit(EXIT_FAILURE);
    }

    node->value = value;

    return node;
}


void node_free(Node *node){
    if(!node){
        fprintf(stderr, "Node free memory failure! Node is null.\n");
        exit(EXIT_FAILURE);
    }

    free(node);
    node = NULL;
}