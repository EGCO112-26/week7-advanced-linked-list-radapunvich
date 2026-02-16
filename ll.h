#ifndef LL_H
#define LL_H

struct Node {
    int id;
    char name[50];
    struct Node *nextPtr;
    struct Node *pPtr;
};

typedef struct Node LLnode;
typedef LLnode *LLPtr;

void instructions(void);
void insert(LLPtr *sPtr, int id, char name[]);
int deletes(LLPtr *sPtr, int id);
int isEmpty(LLPtr sPtr);
void printList(LLPtr sPtr);
void printBackward(LLPtr sPtr);
void freeList(LLPtr *sPtr);

#endif
