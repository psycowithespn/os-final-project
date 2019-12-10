#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.c"
#include "cache.c"

void createVariable(char * userName, char * userData) {
    if (inCache(userName) == 1) {
        printf("Exists in memory");
        }
    else {
        addToCache(userName, userData);
        //TODO: Add to LinkedList
    }
}

char * readVariable(char * userName) {
    if (inCache(userName) == 1) {
        for (int i = 0; i < CACHE_TABLE_SIZE; i++) {
            if (strcmp(cacheTable[i]->name, userName) == 0) {
                printf("%s: %s", cacheTable[i]->name, cacheTable[i]->data);
                cacheTable[i]->r = 1;
                return cacheTable[i]->data;
            }
        }
    }
    /*TODO:Search LinkedList for variable
    else if(searchLinkedList(userName) == true){
      printf(searchLinkedList(userName)->data);
      addToCache(userName, searchLinkedList(username)->data)
    }
    if (inCache(userName)==0 && searchLinkedList(userName) != true){
      printf("Doesn't exist in memory");
    } */
}

void updateVariable(char * userName, char * userData) {
    if (inCache(userName) == 1) {
        for (int i = 0; i < CACHE_TABLE_SIZE; i++) {
            if (strcmp(cacheTable[i]->name, userName) == 0) {
                cacheTable[i]->data = userData;
                cacheTable[i]->r = 1;
            }
        }
    }
    /*TODO:Search LinkedList for variable
    else if(searchLinkedList(userName) == true){
    searchLinkedList(userName)->data = userData;
    addToCache(userName, searchLinkedList(username)->userdata);
    }
    else { printf("Doesn't exist in memory"); } */
}

void deleteVariable(char * userName) {
    if (inCache(userName) == 1) {
        for (int i = 0; i < CACHE_TABLE_SIZE; ++i) {
            if (strcmp(cacheTable[i]->name, userName) == 0) {
                cacheTable[i]->name = NULL;
                cacheTable[i]->data = NULL;
            }

        }
    }
    /*TODO:Search LinkedList for variable
    else if(searchLinkedList(userName) == true){
    LinkedList removeNode(userName);
    }
    else { printf("Doesn't exist in memory"); } */
}