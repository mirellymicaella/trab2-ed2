#ifndef LIST_H
#define LIST_H
#include <stdio.h>

typedef struct list List;

List *initList();

void insertList(List *list, void *item);
void *getItemList(List *list, int index);
void printListFile(List *list, FILE *fileOut);
void destroiList(List *list);
void freeList(List *list);
int getSizeList(List *list);
int compareLists(const void *a, const void *b);

#endif