#ifndef ITEM_H
#define ITEM_H

typedef struct item Item;

// #define id(A)          (A->id)                           // retorna identificador do nó
// #define value(A)        (A->peso)                       // retorna valor do nó
// #define more(A, B)      (value(A) > value(B))           // compara nós, por valor
// #define exch(A, B)      { Item* t = A; A = B; B = t; }   // troca dois nós

void exch(Item* A, Item* B);

int more(Item* A, Item* B);

Item** initItem(int t);

Item* criaItem(double peso, int id);

double retornaPeso(Item* i);

int retornaId(Item* i);
void printItem(Item* i);

void setpeso_Item(Item* i, double peso);

void destroiItem(Item** item, int t);

#endif
