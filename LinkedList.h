#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node *Node;

/*create new Node object with passed data. return created Node object*/
Node createNode(struct data*);

/*create new Node object with passed data. insert created Node at the start of the list
head points to. return new head (created Node)*/
Node insertAtStart(Node head, struct data*);

/*create copy of list pointed to by input head. return head Node copy*/
Node cloneList(Node head);

/*free all dynamically allocated memory associated with list*/
void destroyList(Node head);



#endif