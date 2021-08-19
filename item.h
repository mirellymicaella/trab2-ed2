#ifndef ITEM_H
#define ITEM_H

typedef struct {
  int id;           // identificador do nó
  double peso;     // valor associado ao nó
} Item;

#define id(A)          (A.id)                           // retorna identificador do nó
#define value(A)        (A.peso)                       // retorna valor do nó
#define more(A, B)      ((A) > (B))           // compara nós, por valor
#define exch(A, B)      { Item t = A; A = B; B = t; }   // troca dois nós

Item** initItem(int t);
Item* criaItem(double peso, int id);
double retornaPeso(Item* i);
int retornaId(Item* i);
void destroiItem(Item** item, int t);


#endif
