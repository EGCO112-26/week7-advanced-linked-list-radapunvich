#include <stdio.h>
#include "ll.h"

int main(void)
{
    LLPtr startPtr = NULL;
    unsigned int choice;
    int id;
    char name[50];

    instructions();
    printf("? ");
    scanf("%u", &choice);

    while (choice != 3) {

        switch (choice) {

            case 1:
                printf("Enter a number: ");
                scanf("%d %s", &id, name);
                

                insert(&startPtr, id, name);
                printList(startPtr);
                printBackward(startPtr);
                break;

            case 2:
                printf("Enter id to delete: ");
                scanf("%d", &id);

                if (!deletes(&startPtr, id))
                    printf("ID not found.\n");

                printList(startPtr);
                printBackward(startPtr);
                break;
        }

        printf("? ");
        scanf("%u", &choice);
    }

    if (!isEmpty(startPtr)) {
    printf("Clear all nodes\n");
    freeList(&startPtr);
}

printf("End of run.\n");
return 0;

}
