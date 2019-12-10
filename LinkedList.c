#include <stdio.h>
#include <string.h>
#include "main.c"

// Linked List Node - Used to store the commands
struct node {
    char * data;
    char name;
    struct node * next;
};

typedef struct node *LinkedListNode;

// Create a new Linked List with Default Values
LinkedListNode newLinkedList(void * data, char name) {
    LinkedListNode node;
    node = (LinkedListNode)malloc(sizeof(LinkedListNode));

    node->data = data;
    node->name = name;
    node->next = NULL;

    return node;
}

// Adds a new node with data
void addNode(LinkedListNode head, char * data, char name) {
    LinkedListNode nextNode = newLinkedList(data, name);
    LinkedListNode temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = nextNode;
}

// Returns node based off of index
LinkedListNode getNode(LinkedListNode head, int index) {
    LinkedListNode node = head;
    printf("%s\n", node->data);

    for (int i = 0; i < index; i++) {
        printf("%s\n", node->data);
        node = node->next;
    }

    return node;
}

// Compares strings in the linked list
int searchListString(LinkedListNode head, char * toSearch) {
    LinkedListNode node = head;
    int index = 0;

    while (strcmp(node->data, toSearch) != 0) {
        node = node->next;
        index++;

        if (node == NULL) {
            return -1;
        }
    }

    return index;
}

// Search for things that aren't strings
int searchList(LinkedListNode head, void * toSearch) {
    LinkedListNode node = head;
    int index = 0;

    while (node->data != toSearch) {
        node = node->next;
        index++;

        if (node == NULL) {
            return -1;
        }
    }

    return index;
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

void main(){

    LinkedListNode centralList(data);

}

//Adds value to a new node if cacheTable is full
void addToList(){

    addnode initialNode(centralList, userName);

}

//Search for value in list
void searchLinkedList(){

    if (searchListString(centralList, userName) == true){

        return userName;
    } 

    else{

        printf("Does not exist in LinkedList");
        
    }

}

//Updates list value
void updateList(){

        if (searchListString(centralList, userName) == true){

        return userName;
    } 

    else{

        printf("Does not exist in LinkedList");
        
    }

}

//Removes value from list
void removeFromList{

    if (searchListString(centralList, userName) == true){

        removeNodeString(userName);
    }

    else{

        printf("Does not exist in LinkedList");
        
    }

}