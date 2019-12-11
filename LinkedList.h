#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string.h>
#include "Cache.h"

struct node {
    char * name;
    char * data;
    struct node * next;
};

typedef struct node *LinkedListNode;

LinkedListNode centralList;

LinkedListNode newLinkedList(char * data, char * name);
void addNode(char * data, char * name);
LinkedListNode getNode(LinkedListNode head, int index);
int searchList(LinkedListNode head, char * toSearch);
void removeNode(LinkedListNode head, char * data);
Node searchLinkedList(char * name);
void updateLinkedList(char * name, char * data);
void removeFromLinkedList(char * name);

#endif