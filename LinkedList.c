#include "LinkedList.h"

// Create a new Linked List with Default Values
LinkedListNode newLinkedList(Node data, char * name) {
    LinkedListNode node;
    node = (LinkedListNode)malloc(sizeof(LinkedListNode));

    node->data = data;
    node->name = name;
    node->next = NULL;

    return node;
}

// Adds a new node with data
void addNode(Node data, char * name) {
    LinkedListNode nextNode = newLinkedList(data, name);
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

    while (strcmp(node->data->data, toSearch) != 0) {
        node = node->next;
        index++;

        if (node == NULL) {
            return -1;
        }
    }

    return index;
}

// Same but with strings
LinkedListNode removeNode(LinkedListNode head, char * data) {
    LinkedListNode previous;
    LinkedListNode node = head;

    while (strcmp(node->data->name, data) != 0) {
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

//Search for value in list
LinkedListNode searchLinkedList(char * name){
    int index;
    if ((index = searchList(centralList, name)) != -1){
        return getNode(centralList, index);
    } else{
        printf("Does not exist in LinkedList");
    }

}

//Updates list value
void updateLinkedList(char * name, char * data){
    int index;
    if ((index = searchList(centralList, name)) != -1) {
        getNode(centralList, index)->data = data;
    } else{
        printf("Does not exist in LinkedList");
    }
}

//Removes value from list
void removeFromLinkedList(char * name) {
    removeNode(centralList, name);
}