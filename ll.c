#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h"

void instructions(void)
{
    puts("Enter your choice:");
    puts("1 - Insert");
    puts("2 - Delete");
    puts("3 - End");
}

void insert(LLPtr *sPtr, int id, char name[])
{
    LLPtr newPtr = malloc(sizeof(LLnode));
    if (newPtr == NULL) {
        printf("No memory available.\n");
        return;
    }

    newPtr->id = id;
    strcpy(newPtr->name, name);
    newPtr->nextPtr = NULL;
    newPtr->pPtr = NULL;

    LLPtr current = *sPtr;
    LLPtr previous = NULL;

    while (current != NULL && id > current->id) {
        previous = current;
        current = current->nextPtr;
    }

    if (previous == NULL) {
        newPtr->nextPtr = *sPtr;
        if (*sPtr != NULL)
            (*sPtr)->pPtr = newPtr;
        *sPtr = newPtr;
    }
    else {
        newPtr->nextPtr = current;
        newPtr->pPtr = previous;
        previous->nextPtr = newPtr;

        if (current != NULL)
            current->pPtr = newPtr;
    }
}

int deletes(LLPtr *sPtr, int id)
{
    if (*sPtr == NULL)
        return 0;

    LLPtr current = *sPtr;

    while (current != NULL && current->id != id)
        current = current->nextPtr;

    if (current == NULL)
        return 0;

    if (current->pPtr == NULL) {
        *sPtr = current->nextPtr;
        if (*sPtr != NULL)
            (*sPtr)->pPtr = NULL;
    }
    else {
        current->pPtr->nextPtr = current->nextPtr;
        if (current->nextPtr != NULL)
            current->nextPtr->pPtr = current->pPtr;
    }

    free(current);
    return 1;
}

int isEmpty(LLPtr sPtr)
{
    return sPtr == NULL;
}

void printList(LLPtr sPtr)
{
    if (sPtr == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("The list is:\n");

    LLPtr temp = sPtr;
    while (temp != NULL) {
        printf("%d %s -->", temp->id, temp->name);
        temp = temp->nextPtr;
    }
    printf("NULL\n");
}

void printBackward(LLPtr sPtr)
{
    if (sPtr == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (sPtr->nextPtr != NULL)
        sPtr = sPtr->nextPtr;

    

    while (sPtr != NULL) {
        printf("%d %s -->", sPtr->id, sPtr->name);
        sPtr = sPtr->pPtr;
    }
    printf("NULL\n");
}

void freeList(LLPtr *sPtr)
{
    LLPtr temp;

    while (*sPtr != NULL) {
        temp = *sPtr;
        printf("delete %d\n", temp->id);
        *sPtr = (*sPtr)->nextPtr;   

        free(temp);
    }
}


