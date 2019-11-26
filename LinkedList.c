#include <stdio.h>
#include <stdbool.h>

// Linked List Node - Used to store the commands
struct node {
    char * data;
    struct node * next;
};

typedef struct node *LinkedListNode;

// Create a new Linked List with Default Values
LinkedListNode newLinkedList(void * data) {
    LinkedListNode node;
    node = (LinkedListNode)malloc(sizeof(LinkedListNode));

    node->data = data;
    node->next = NULL;

    return node;
}

// Adds a new node with data
void addNode(LinkedListNode head, void * data) {
    LinkedListNode nextNode = newLinkedList(data);
    LinkedListNode temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = nextNode;
}

// Compares strings in the linked list
int searchListString(LinkedListNode head, char * toSearch) {
    LinkedListNode node = head;

    while (strcmp(node->data, toSearch) != 0) {
        node = node->next;

        if (node == NULL) {
            return 0;
        }
    }

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