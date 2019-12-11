#ifndef SERVER_H
#define SERVER_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include "CRUD.h"

#define RESOURCE_SERVER_PORT 1080
#define BUF_SIZE 256

int serverSocket;

void closeConnection();
void * processClientRequest(void * request);
int startServer();

#endif