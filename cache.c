#include <stdlib.h>
#include <ctype.h>

#define CACHE_DATA_SIZE 256
#define CACHE_TABLE_SIZE 8

struct Cache {
    char * name;
    char * data;
    int referenced;
};
typedef struct Cache *Node;

Node cacheTable[CACHE_TABLE_SIZE];

int hash(char * primaryKey) {
    int sum = 0;
    for (int i = 0; primaryKey[i] != 0; i++) {
        sum += sprintf("%d", primaryKey[i]);
    }

    return sum % 8;
}

// Reads from the cache table, changes referenced to 1
Node readCache(Node data) {
    int index = hash(data->data);

    cacheTable[index]->referenced = 1;
    return cacheTable[index]->data;;
}

void addToCache(Node data){
    int index = hash(data->name);
    cacheTable[index] = data;
}

// Hashes and checks if thing is in cache
int inCache(Node data){
    int index = hash(data->name);

    if (strcmp(data->name, cacheTable[index]) == 0) {
        return 1;
    }

    return 0;
}