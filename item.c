#include "item.h"
#include <stdlib.h>
#include <stdio.h>

struct item{
  int id;           // identificador do nó
  double peso;     // valor associado ao nó
};

Item** initItem(int t){
    Item ** item = (Item**) malloc(sizeof(Item*) * t);
    return item;
}

Item* criaItem(double peso, int id){
    Item * item = (Item*) malloc(sizeof(Item));
    item->id = id;
    item->peso = peso;
    return item;
}

double retornaPeso(Item* i){
    return i->peso;
}

int retornaId(Item* i){
    return i->id;
}

void setpeso_Item(Item* i, double peso){
    i->peso = peso;
}

void printItem(Item* i){
		printf("%d -  %lf\n",i->id, i->peso);
}

int more(Item* A, Item* B){
    if(A->peso > B->peso){
        return 1;
    }else{
        return 0;
    }
}  

void destroiItem(Item** item, int t){
    for (int i = 1; i < t; ++i) {
        free(item[i]);
    }
    free(item);
}