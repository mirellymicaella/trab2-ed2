#include "item.h"
#include <stdlib.h>
#include <stdio.h>

struct item{
  int id;           // identificador do nó
  double weight;     // valor associado ao nó
};

Item** initItem(int t){
    Item ** item = (Item**) malloc(sizeof(Item*) * t);
    return item;
}

Item* createItem(double weight, int id){
    Item * item = (Item*) malloc(sizeof(Item));
    item->id = id;
    item->weight = weight;
    return item;
}

double getWeightItem(Item* i){
    return i->weight;
}

int getIdItem(Item* i){
    return i->id;
}

void setWeightItem(Item* i, double weight){
    i->weight = weight;
}

void printItem(Item* i){
	printf("%d -  %lf\n",i->id, i->weight);
}

int moreItem(Item* A, Item* B){
    return  A->weight > B->weight;
}  

void destroyItem(Item** item, int t){
    for (int i = 1; i < t; ++i) 
        free(item[i]);
    
    free(item);
}