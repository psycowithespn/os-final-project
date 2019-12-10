#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.c"
#include "server.c"
#define CACHE_DATA_SIZE 256
#define CACHE_TABLE_SIZE 8

typedef struct Cache *Node;
Node cacheTable[CACHE_TABLE_SIZE];


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

    startServer();

    ///Create a hashmap
    return EXIT_SUCCESS;
}