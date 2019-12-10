#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.c"
#define CACHE_DATA_SIZE 256
#define CACHE_TABLE_SIZE 8
#include "ctype.h"

struct Cache {
    char name;
    char data;
    int r;
    int lastUsed;
};

typedef struct Cache *Node;
Node cacheTable[CACHE_TABLE_SIZE];
void * clear(void * run) {
    int myrun = *((int *) run);
    for (int i = 0; i < CACHE_TABLE_SIZE; i++) {
        if (cacheTable[i]->r == 1) {
            cacheTable[i]->r = 0;
        }
    }
}
void createVariable(char userName, char userData){
    for (int i = 0; i <CACHE_TABLE_SIZE; ++i) {
        if (isblank((cacheTable[i]->name)) && isblank((cacheTable[i]->data))){
            cacheTable[i]->name = userName;
            cacheTable[i]->data = userData;
            break;
        }
        else if (cacheTable[i]->r = 0){
            cacheTable[i]->name = userName;
            cacheTable[i]->data = userData;
            break;
        }
        else {}

    }
}
void readVariable(char userName){
    for (int i = 0; i <CACHE_TABLE_SIZE; ++i) {
        if(cacheTable[i]->name = userName){
            printf(cacheTable[i]->name+ ": "+cacheTable[i]->data);
            cacheTable[i]->r = 1;
        }
    }
}
void updateVariable(char userName, char userData){
    for (int i = 0; i <CACHE_TABLE_SIZE; ++i) {
        if (cacheTable[i]->name = userName){
            cacheTable[i]->data = userData;
            cacheTable[i]->r = 1;
        }
    }
}
void deleteVariable(char userName){
    for (int i = 0; i <CACHE_TABLE_SIZE; ++i) {
        if (cacheTable[i]->name=userName){
            cacheTable[i]->name = NULL;
            cacheTable[i]->data = NULL;
        }

    }
}


int main() {
    for(int i = 0; i < CACHE_TABLE_SIZE; i++){
        Node cache;
        cache = (Node)malloc(sizeof(Node));

        cache->lastUsed = 0;
        cache->name = NULL;
        cache->data = NULL;
        cache->r = 0;

        cacheTable[i] = cache;
    }
    ///Read variable method
    ///Delete variable method
    ///Update variable method
    ///Create a hashmap

}