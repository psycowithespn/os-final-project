#include "CRUD.h"

void createVariable(char * name, char * data) {
    if (inCache(name) == 1) {
        printf("Exists in memory");
    } else {
        Node node = {name, data};
        addToCache(node);
        addNode(data, name);
    }
}

char * readVariable(char * name) {
    if (inCache(name) == 1) {
        return readCache(name)->data;
    } else if(searchList(centralList, name) != -1){
        Node node = searchLinkedList(name);
        addToCache(node);
        return node;
    } else{
        printf("Doesn't exist in memory");
        return NULL;
    }
}

void updateVariable(char * name, char * data) {
    if (inCache(name) == 1) {
        Node node = {name, data, 1};
        addToCache(node);
        if (searchList(centralList, name) != -1) {
            searchLinkedList(name)->data = data;
        }
    } else if(searchList(centralList, name) != -1){
      searchLinkedList(name)->data = data;
      addToCache(searchLinkedList(name)->data);
    } else {
        printf("Doesn't exist in memory");
    }
}

void deleteVariable(char * name) {
    if (inCache(name) == 1) {
        cacheTable[hash(name)]->name = NULL;
        cacheTable[hash(name)]->data = NULL;
    } else if(searchList(centralList, name) != -1){
        removeFromLinkedList(searchLinkedList(name)->name);
    } else {
        printf("Doesn't exist in memory");
    }
}