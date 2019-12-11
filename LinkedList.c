#include "LinkedList.h"

// Create a new Linked List with Default Values
LinkedListNode newLinkedList(char * data, char * name) {
    LinkedListNode node;
    node = (LinkedListNode)malloc(sizeof(LinkedListNode));

    node->name = name;
    node->data = data;
    node->next = NULL;

    return node;
}

// Adds a new node with data
void addNode(char * data, char * name) {
    char nameCopy[strlen(name)];
    char dataCopy[strlen(data)];

    strcpy(nameCopy, name);
    strcpy(dataCopy, data);

    LinkedListNode nextNode = newLinkedList(dataCopy, nameCopy);
    LinkedListNode temp = centralList;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = nextNode;
}

// Returns node based off of index
LinkedListNode getNode(LinkedListNode head, int index) {
    LinkedListNode node = head;

    for (int i = 0; i < index; i++) {
        node = node->next;
    }

    return node;
}

// Compares strings in the linked list
int searchList(LinkedListNode head, char * toSearch) {
    LinkedListNode node = head;
    int index = 0;

    while (strcmp(node->name, toSearch) != 0) {
        node = node->next;
        index++;

        if (node == NULL) {
            return -1;
        }
    }

    return index;
}

// Same but with strings
void removeNode(LinkedListNode head, char * data) {
    LinkedListNode previous;
    LinkedListNode node = head;

    while (strcmp(node->name, data) != 0) {
        previous = node;
        node = node->next;

        if (node == NULL) {
            break;
        }
    }

    previous->next = node->next;
    free(node);
}

//Search for value in list
Node searchLinkedList(char * name){
    int index;
    pthread_mutex_lock(&lock);

    if ((index = searchList(centralList, name)) != -1){
        pthread_mutex_unlock(&lock);
        return getNode(centralList, index);
    } else{
        printf("Does not exist in LinkedList");
    }

    pthread_mutex_unlock(&lock);
}

//Updates list value
void updateLinkedList(char * name, char * data){
    int index;

    char dataCopy[strlen(data)];
    strcpy(dataCopy, data);

    pthread_mutex_lock(&lock);

    if ((index = searchList(centralList, name)) != -1) {
        getNode(centralList, index)->data = dataCopy;
    } else{
        printf("Does not exist in LinkedList");
    }

    pthread_mutex_unlock(&lock);
}

//Removes value from list
void removeFromLinkedList(char * name) {
    pthread_mutex_lock(&lock);
    removeNode(centralList, name);
    pthread_mutex_unlock(&lock);
}