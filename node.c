#include "node.h"

#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <assert.h>

Node *node_init(int value){
    Node *node = malloc(sizeof(Node));
    if(!node){
        fprintf(stderr, "Node memory allocation failure!\n");
        assert(false && "Node memory allocation failure!\n");
    }

    node->value = value;

    return node;
}


void node_free(Node *node){
    if(!node){
        fprintf(stderr, "Node free memory failure! Node is null.\n");
        assert(false && "Node free memory failure! Node is null.\n");
    }

    free(node);
    node = NULL;
}