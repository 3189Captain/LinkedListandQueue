#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct listItem {
    int someInteger;
    struct listItem *next;
} LIST_ITEM;

void insertionSort(LIST_ITEM** startPtr);
void sortedInsert(LIST_ITEM** startPtr, LIST_ITEM* newItem);
void deleteVal(LIST_ITEM** startPtr, int valueTBD);
void listTraverse(LIST_ITEM** startPtr);

int main() {
    LIST_ITEM *start = NULL, *temp;
    int valueTBD;

    while(1){
        temp = malloc(sizeof(LIST_ITEM));
        printf("Enter an Integer, or 0 to quit: ");
        scanf("%d", &(temp->someInteger));
        if(temp->someInteger == 0){
            break;
        } else {
            temp->next = start;
            start = temp;
        }
        insertionSort(&start);
        listTraverse(&start);
    }
    
    
    
    while(1){
        printf("Enter a value to be deleted, or 0 to quit: ");
        scanf("%d", &valueTBD);
        if(valueTBD == 0){
            break;
        } else {
            deleteVal(&start, valueTBD);
            listTraverse(&start);
        }
    }
    
    return 0;
}

void insertionSort(LIST_ITEM** startPtr){
    LIST_ITEM *sortedPtr = NULL, *current = *startPtr, *next;
    
    while(current != NULL){
        next = current->next;
        sortedInsert(&sortedPtr, current);
        current = next;
    }
    *startPtr = sortedPtr;
}

void sortedInsert(LIST_ITEM** startPtr, LIST_ITEM* newItem){
    LIST_ITEM *current;
    
    if(*startPtr == NULL || (*startPtr)->someInteger >= newItem->someInteger) {
        newItem->next = *startPtr;
        *startPtr = newItem;
    } else {
        current = *startPtr;
        while(current->next != NULL && current->next->someInteger < newItem->someInteger) {
            current = current->next;
        }
        newItem->next = current->next;
        current->next = newItem;
    }
}

void deleteVal(LIST_ITEM** startPtr, int valueTBD){
    LIST_ITEM *current;
    LIST_ITEM *follow;
    
    if(*startPtr == NULL){
        printf("list is empty\n");
    }if((*startPtr)->someInteger == valueTBD) {
        *startPtr = (*startPtr)->next;
    } else {
        current = *startPtr;
        while(current->someInteger != valueTBD && current->next != NULL){
            follow = current;
            current = current->next;
        }
        if(current->next == NULL && current->someInteger != valueTBD){
            printf("Value is not on the list\n");
        } else if(current->someInteger != valueTBD) {
            free(current);
        } else {
            follow->next = current->next;
            free(current);  
        }
    }
}

void listTraverse(LIST_ITEM** startPtr){
    LIST_ITEM *trvPtr = *startPtr;
    printf("The list is: ");
    while(trvPtr != NULL) {
        printf("%d->", trvPtr->someInteger);
        trvPtr = trvPtr->next;
    }
    printf("\n");
}