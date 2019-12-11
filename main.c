#include "Memory.h"

int main() {
    for(int i = 0; i < CACHE_TABLE_SIZE; i++){
        Node cache;
        cache = (Node)malloc(sizeof(Node));

        cache->name = NULL;
        cache->data = NULL;

        cacheTable[i] = cache;
    }

    pthread_mutex_init(&lock, NULL);
    centralList = newLinkedList(NULL, "Yay");
    startServer();

    return EXIT_SUCCESS;
}