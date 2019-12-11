#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string.h>
#include "Cache.h"

struct node {
    Node data;
    char * name;
    struct node * next;
};

typedef struct node *LinkedListNode;

LinkedListNode centralList;

LinkedListNode newLinkedList(Node data, char * name);
void addNode(Node data, char * name);
LinkedListNode getNode(LinkedListNode head, int index);
int searchList(LinkedListNode head, char * toSearch);
LinkedListNode removeNode(LinkedListNode head, char * data);
LinkedListNode searchLinkedList(char * name);
void updateLinkedList(char * name, char * data);
void removeFromLinkedList(char * name);

#endif