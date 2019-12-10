#include <stdlib.h>

#define CACHE_DATA_SIZE 256
#define CACHE_TABLE_SIZE 8

struct Cache {
    char * name;
    char * data;
    int r;
    int lastUsed;
};

typedef struct Cache *Node;
Node cacheTable[CACHE_TABLE_SIZE];

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