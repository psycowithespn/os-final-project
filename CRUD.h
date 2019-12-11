#ifndef CRUD_H
#define CRUD_H

#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
#include "Cache.h"

void createVariable(char * name, char * data);
char * readVariable(char * name);
void updateVariable(char * name, char * data);
void deleteVariable(char * userName);

#endif