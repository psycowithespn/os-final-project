#include "CRUD.h"

void createVariable(char * name, char * data) {
    if (inCache(name) == 1) {
        printf("Exists in memory");
    } else {
        Node node = {name, data, 1};
        addToCache(node);
        //TODO: Add to LinkedList
    }
}

char * readVariable(char * name) {
    if (inCache(name) == 1) {
        return readCache(name)->data;
    }

    /*TODO:Search LinkedList for variable
    else if(searchLinkedList(userName) == true){
      printf(searchLinkedList(userName)->data);
      addToCache(userName, searchLinkedList(username)->data)
    }
    if (inCache(userName)==0 && searchLinkedList(userName) != true){
      printf("Doesn't exist in memory");
    } */

    return NULL;
}

void updateVariable(char * name, char * data) {
    if (inCache(name) == 1) {
        Node node = {name, data, 1};
        addToCache(node);
    }

    /*TODO:Search LinkedList for variable
    else if(searchLinkedList(userName) == true){
    searchLinkedList(userName)->data = userData;
    addToCache(userName, searchLinkedList(username)->userdata);
    }
    else { printf("Doesn't exist in memory"); } */
}

void deleteVariable(char * userName) {
    if (inCache(userName) == 1) {
        // TODO: Delete from cache
    }
    /*TODO:Search LinkedList for variable
    else if(searchLinkedList(userName) == true){
    LinkedList removeNode(userName);
    }
    else { printf("Doesn't exist in memory"); } */
}