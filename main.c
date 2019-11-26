#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define CACHE_DATA_SIZE 256
#define CACHE_TABLE_SIZE 8

struct Cache {
    char *data;
    int lastUsed;
};
struct Cache cacheTable[CACHE_TABLE_SIZE];
int main() {
    for(int i = 0; i < CACHE_TABLE_SIZE; i++){
        struct Cache cache[CACHE_TABLE_SIZE];
        cache->lastUsed = i;
        cache->data = malloc(CACHE_DATA_SIZE);
        cacheTable[i] = cache;
    }
    ///Create variable method
    ///Read variable method
    ///Delete variable method
    ///Update variable method
    ///Create a hashmap

}