#include "Cache.h"

int hash(char * primaryKey) {
    int sum = 0;

    for (int i = 0; i < strlen(primaryKey); i++) {
        sum += (int) primaryKey[i];
    }

    return sum % 8;
}

// Reads from the cache table, changes referenced to 1
Node readCache(char * name) {
    int index = hash(name);
    return cacheTable[index];
}

void addToCache(Node data){
    int index = hash(data->name);

    pthread_mutex_lock(&lock);
    cacheTable[index] = data;
    pthread_mutex_unlock(&lock);
}

// Hashes and checks if thing is in cache
int inCache(char * name){
    int index = hash(name);
    if (strcmp(name, (cacheTable[index]->name)) == 0) {
        return 1;
    }
    return 0;
}