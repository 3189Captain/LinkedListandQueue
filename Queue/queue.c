#include<stdio.h>
#include<stdlib.h>

typedef struct listItem{
    char data;
    struct listItem *next;
} LISTITEM;

void insert(LISTITEM **end);
void removeFromQueue(LISTITEM **end);

int main() {
    LISTITEM *end = NULL;
    LISTITEM *trvPtr;
    char controlChar;
    while(1) {
        printf("Enter i to insert, r to remove, or q to quit: ");
        controlChar = getc(stdin);
        getc(stdin);
        if(controlChar == 'q') {
            break;
        } else if(controlChar == 'i') {
            insert(&end);
        } else if(controlChar == 'r') {
            removeFromQueue(&end);
        }
    }
    return 0;
}

void insert(LISTITEM **end) {
    char dataToInsert;
    LISTITEM *newItem = malloc(sizeof(LISTITEM));
    
    printf("Enter the data to be inserted: ");
    dataToInsert = getc(stdin);
    getc(stdin);
    newItem->data = dataToInsert;
    
    if(*end == NULL) {
        newItem->next = newItem;
        *end = newItem;
    } else if((*end)->next == *end) {
        newItem->next = *end;
        (*end)->next = newItem;
        *end = (*end)->next;
    } else {
        newItem->next = (*end)->next;
        (*end)->next = newItem;
        *end = (*end)->next;
    }
}

void removeFromQueue(LISTITEM **end){
    LISTITEM *itemToRemove;
    if(*end == NULL) {
        printf("the list is empty\n");
        return;
    }
    itemToRemove = (*end)->next;
    if(itemToRemove->next == itemToRemove){
        printf("The item removed was: %c\n", itemToRemove->data);
        free(itemToRemove);
        *end = NULL;
    } else {
        (*end)->next = (*end)->next->next;
        printf("The item removed was: %c\n", itemToRemove->data);
        free(itemToRemove);
    }
    
}