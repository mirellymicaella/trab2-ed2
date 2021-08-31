#include "list.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    void **items;
    int size;
};

List *initList() {
    List *list = (List *)malloc(sizeof(List));
    list->items = (void **)malloc(sizeof(void *));
    list->size = 0;
    return list;
}

void insertList(List *list, void *item) {
    void **temp = list->items;
    int i;

    // realoca primeiro
    temp = realloc(temp, (list->size + 1) * sizeof(void *)); 
    if (temp != NULL) 
        list->items = temp;
     else {
        fputs("Realloc falhou!", stderr);
        free(temp); //libera a memoria alocada
        exit(-1);  // finaliza o porgrama
    }
    list->items[list->size] = item;
    list->size++;
}

void *getItemList(List *list, int index) { return list->items[index]; }

int getSizeList(List *list) { return list->size; }

void destroiList(List *list) {
    for(int i=0; i< list->size; i++)
        free(list->items[i]);
    
    free(list->items);
    free(list);
}

void freeList(List *list) {
    free(list->items);
    free(list);
}
