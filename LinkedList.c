#include <stdlib.h>
#include "LinkedList.h"

struct node {
    dataType data;
    struct node* next;
};

Node createNode(dataType data) {
    Node newNode = malloc(sizeof(*newNode));
    if (newNode == NULL) {
        return NULL; // ALLOC FAIL
    }
    newNode->data = data;
    newNode->next = NULL;
}

Node insertAtStart(Node head, dataType data) {
    Node newNode = createNode(data);
    if (newNode == NULL) {
        return NULL; // ALLOC FAIL
    }
    newNode->next = head;
}

// I tried a recursive alg for this one idk if it works. looks sexy tho
Node cloneList(Node head) {
    if (head == NULL) {
        return NULL;
    }
    Node clonedHead = createNode(head->data);
    if (clonedHead == NULL) {
        return NULL; // ALLOC FAIL
    }
    Node rest = cloneList(head->next);
    clonedHead->next = rest;
    return clonedHead;
}

// ** if dataType ends up being an object that needs dynamic memory alloc
// then we might need to also free each data object** or we free those seperately
void destroyList(Node head) {
    while(head) {
        Node nodeToDelete = head;
        head = head->next;
        free(nodeToDelete);
    }
}

