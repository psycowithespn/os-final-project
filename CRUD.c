#include "CRUD.h"

void createVariable(char * name, char * data) {

    if (inCache(name) == 1) {
        printf("Exists in memory");
    } else {
        Node node = (Node)malloc(sizeof(Node));
        node->name = name;
        node->data = data;

        addToCache(node);
        printf("Exists in memory");
        addNode(data, name);
    }
}

char * readVariable(char * name) {
    if (inCache(name) == 1) {
        return readCache(name)->data;
    } else if(searchList(centralList, name) != -1){
        Node node = searchLinkedList(name);
        addToCache(node);
        return node->data;
    } else{
        printf("Doesn't exist in memory");
        return NULL;
    }
}

void updateVariable(char * name, char * data) {
    if (inCache(name) == 1) {
        Node node = (Node)malloc(sizeof(Node));

        node->name = name;
        node->data = data;

        addToCache(node);
    } 
    
    if(searchList(centralList, name) != -1){
        updateLinkedList(name, data);
    } else {
        printf("Doesn't exist in memory");
    }
}

void deleteVariable(char * name) {
    if (inCache(name) == 1) {
        cacheTable[hash(name)]->name = NULL;
        cacheTable[hash(name)]->data = NULL;
    } 
    
    if(searchList(centralList, name) != -1){
        removeFromLinkedList(name);
    } else {
        printf("Doesn't exist in memory");
    }
}