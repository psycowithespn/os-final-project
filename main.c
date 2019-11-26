// #include <iostream>  
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.c"
#define CACHE_DATA_SIZE 256
#define CACHE_TABLE_SIZE 8

struct Cache {
    char *data;
    int lastUsed;
};

typedef struct Cache *Node;
Node cacheTable[CACHE_TABLE_SIZE];

int main() {
    for(int i = 0; i < CACHE_TABLE_SIZE; i++){
        Node cache;
        cache = (Node)malloc(sizeof(Node));

        cache->lastUsed = 0;
        cache->data = NULL;
        
        cacheTable[i] = cache;
    }
    ///Create variable method
    ///Read variable method
    ///Delete variable method
    ///Update variable method
    ///Create a hashmap

}