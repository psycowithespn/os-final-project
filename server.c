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
#include "CRUD.c"

#define RESOURCE_SERVER_PORT 1080
#define BUF_SIZE 256

// We make this a global so that we can refer to it in our signal handler
int serverSocket;

/*
 We need to make sure we close the connection on signal received, otherwise we have to wait
 for server to timeout.
 */
void closeConnection() {
    printf("\nClosing Connection with file descriptor: %d \n", serverSocket);
    close(serverSocket);
    exit(1);
}

// String Parser
char ** parse(char * toParse) {
    char * token;
    int i = 0;
    char * toReturn[3];

    while ((token = strsep(&toParse, " ")) != NULL) {
        toReturn[i] = token;
        i++;
    }
    return toReturn;
}

// Thread function which processes the actual data
void * processClientRequest(void * request) {
    int connectionToClient = *(int *)request;
    char receiveLine[BUF_SIZE];
    char sendLine[BUF_SIZE];
    
    int bytesReadFromClient = 0;
    // Read the request that the client has
    while ( (bytesReadFromClient = read(connectionToClient, receiveLine, BUF_SIZE)) > 0) {
        // Put a NULL string terminator at end
        receiveLine[bytesReadFromClient] = 0;

        // Show what client sent
        printf("Received: %s\n", receiveLine);

        // Default success value to 0 (false) in case invalid command is sent and switch statement fails
        int success = 0;
        char * parsedString[3] = parse(receiveLine);
        char * command = parsedString[0];

        if (strcmp(command, "create") == 0) {
            createVariable(parsedString[1], parsedString[2]);
        
        } else if (strcmp(command, "read") == 0) {
            char * value = readVariable(parsedString[1]);
            
            // Send value to client
            snprintf(sendLine, sizeof(sendLine), value);
            write(connectionToClient, sendLine, strlen(sendLine));
        
        } else if (strcmp(command, "update") == 0) {
            updateVariable(parsedString[1], parsedString[2]);

        } else if (strcmp(command, "delete") == 0) {
            deleteVariable(parsedString);
        }
        
        // Zero out the receive line so we do not get artifacts from before
        bzero(&receiveLine, sizeof(receiveLine));
        close(connectionToClient);
    }
}

int startServer() {
    int connectionToClient, bytesReadFromClient;
  
    // Create a server socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddress;
    bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family      = AF_INET;
    
    // INADDR_ANY means we will listen to any address
    // htonl and htons converts address/ports to network formats
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port        = htons(RESOURCE_SERVER_PORT);
    
    // Bind to port
    if (bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        printf("Unable to bind to port just yet, perhaps the connection has to be timed out\n");
        exit(-1);
    }
    
    // Before we listen, register for Ctrl+C being sent so we can close our connection
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = closeConnection;
    sigIntHandler.sa_flags = 0;
    
    sigaction(SIGINT, &sigIntHandler, NULL);
    
    // Listen and queue up to 10 connections
    listen(serverSocket, 10);
    
    while (1) {
        /*
         Accept connection (this is blocking)
         2nd parameter you can specify connection
         3rd parameter is for socket length
         */
        connectionToClient = accept(serverSocket, (struct sockaddr *) NULL, NULL);
        
        // Kick off a thread to process request
        pthread_t someThread;
        pthread_create(&someThread, NULL, processClientRequest, (void *)&connectionToClient);
        
    }
}
