#include "item.h"

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

void destroiItem(Item** item, int t){
    for (int i = 1; i < t; ++i) {
        free(item[i]);
    }
    free(item);
}