#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.c"
#define CACHE_DATA_SIZE 256
#define CACHE_TABLE_SIZE 8
#include "ctype.h"

struct Cache {
    char * name;
    char * data;
    int r;
    int lastUsed;
};

typedef struct Cache *Node;
Node cacheTable[CACHE_TABLE_SIZE];

void clear(void * run) {
    //TODO: Fix paging Algorithm
    int myrun = *((int *) run);
    for (int i = 0; i < CACHE_TABLE_SIZE; i++) {
        if (cacheTable[i]->r == 1) {
            cacheTable[i]->r = 0;
        }
    }
}

int inCache(char * userName){
    for (int i = 0; i <CACHE_TABLE_SIZE ; ++i) {
        if (cacheTable[i]->name == userName){return 1;}
        else{ return 0;}
    }
}
void addToCache(char * userName, char * userData){
    for (int i = 0; i < CACHE_TABLE_SIZE; ++i) {
        if (isblank(cacheTable[i]->name) && isblank(cacheTable[i]->data)) {
            cacheTable[i]->name = userName;
            cacheTable[i]->data = userData;
            break;
        } else if (cacheTable[i]->r == 0) {
            cacheTable[i]->name = userName;
            cacheTable[i]->data = userData;
            break;
        } else {
            //TODO:Paging Algorithm
        }
    }
}

void createVariable(char * userName, char * userData) {
    if (inCache(userName) == 1) { printf("Exists in memory"); }
    else {
        addToCache(userName, userData);
        //TODO: Add to LinkedList
    }
}
char * readVariable(char * userName){
    if (inCache(userName)==1) {
        for (int i = 0; i < CACHE_TABLE_SIZE; ++i) {
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
void updateVariable(char * userName, char * userData){
    if (inCache(userName)==1) {
        for (int i = 0; i < CACHE_TABLE_SIZE; ++i) {
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
void deleteVariable(char * userName){
    if (inCache(userName)==1) {
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





