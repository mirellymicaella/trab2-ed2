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
  return A->peso > B->peso;          // compara nós, por valor
}  

void exch(Item* A, Item* B){
  Item* t = A; 
  A = B; 
  B = t;
}

void destroiItem(Item** item, int t){
    for (int i = 1; i < t; ++i) {
        free(item[i]);
    }
    free(item);
}