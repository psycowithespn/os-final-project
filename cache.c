#include "Cache.h"

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
    return cacheTable[index];
}

void addToCache(Node data){
    int index = hash(data->name);

    pthread_mutex_lock(&lock);
    cacheTable[index] = data;
    pthread_mutex_unlock(&lock);
}

// Hashes and checks if thing is in cache
int inCache(Node data){
    int index = hash(data->name);

    if (strcmp(data->name, cacheTable[index]->name) == 0) {
        return 1;
    }

    return 0;
}