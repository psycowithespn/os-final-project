// #include <iostream>  
#include <stdlib.h>
#include <stdio.h>
#include "server.c"
#define CACHE_DATA_SIZE 256
#define CACHE_TABLE_SIZE 8

// Linked List Node - Used to store the commands
struct node {
    char * data;
    struct node * next;
};

typedef struct Cache *Node;
Node cacheTable[CACHE_TABLE_SIZE];

LinkedListNode listNode;

void * clear(void * run) {
    int myrun = *((int *) run);
    for (int i = 0; i < CACHE_TABLE_SIZE; i++) {
        if (cacheTable[i]->r == 1) {
            cacheTable[i]->r = 0;
        }
    }
    
    temp->next = nextNode;
}
void createVariable(char userName, char userData){
    for (int i = 0; i <CACHE_TABLE_SIZE; ++i) {
        if (isblank((cacheTable[i]->name)) && isblank((cacheTable[i]->data))){
            cacheTable[i]->name = userName
            cacheTable[i]->data = userData;
            break;
        }
        else if (cacheTable[i]->r = 0){
            listNode.addNode(cacheTable[i]->name, cacheTable[i]->data);
            cacheTable[i]->name = userName;
            cacheTable[i]->data = userData;
            break;
        }
        else {}

    return 1;
}

// Search for things that aren't strings
int searchList(LinkedListNode head, void * toSearch) {
    LinkedListNode node = head;

    while (node->data != toSearch) {
        node = node->next;

        if (node == NULL) {
            return 0;
        }
        else if(listNode.searchListString())
    }

    return 1;
}

// Removes a node and sets the 'next' value of the previous node to the 'next' value of the deleted node
LinkedListNode removeNode(LinkedListNode head, void * data) {
    LinkedListNode previous;
    LinkedListNode node = head;

    while (node->data != data) {
        previous = node;
        node = node->next;

        if (node == NULL) {
            return head;
        }
    }

    if (node == head) {
        node = head;
        head = head->next;
        free(node);
        return head;
    }

    previous->next = node->next;
    free(node);
    return head;
}

// Same but with strings
LinkedListNode removeNodeString(LinkedListNode head, char * data) {
    LinkedListNode previous;
    LinkedListNode node = head;

    while (strcmp(node->data, data) != 0) {
        previous = node;
        node = node->next;

        if (node == NULL) {
            return head;
        }
    }

    if (node == head) {
        node = head;
        head = head->next;
        free(node);
        return head;
    }

    previous->next = node->next;
    free(node);
    return head;
}

int main() {

    LinkedListNode cacheList(data);

    for(int i = 0; i < CACHE_TABLE_SIZE; i++){
        Node cache;
        cache = (Node)malloc(sizeof(Node));

        cache->lastUsed = 0;
        cache->data = NULL;
        
        cacheTable[i] = cache;

        if(cacheTable[i] =! cache){

        addNode (cacheList , void* data);

        initialNode = cacheTable[i];

        }
        
    }

    ///Create a hashmap

    startServer();
}

