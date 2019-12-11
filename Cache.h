#ifndef CACHE_H
#define CACHE_H

#include <stdlib.h>
#include <pthread.h>
#include <ctype.h>

#define CACHE_DATA_SIZE 256
#define CACHE_TABLE_SIZE 8

struct Cache {
    char * name;
    char * data;
};
typedef struct Cache *Node;

Node cacheTable[CACHE_TABLE_SIZE];
pthread_mutex_t lock;

int hash(char * primaryKey);
Node readCache(Node data);
void addToCache(Node data);
int inCache(Node data);

#endif