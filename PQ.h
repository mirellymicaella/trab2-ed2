#ifndef PQ_H
#define PQ_H

#include <stdbool.h>
#include "item.h"

typedef struct heap Heap;

Heap* PQ_init(int maxN); // cria uma min PQ com capacidade maxN
void PQ_insert(Item* v, Heap* heap);   // Insere Item na PQ. A maior prioridade é a do Item com menor campo 'value'
Item PQ_delmin(Heap* heap);       // Remove Item com menor campo 'value' da PQ
void PQ_decrease_key(int id, double value, Heap* heap); // Muda a prioridade do nó com identificador 'id' para 'value'
Item PQ_min(Heap* heap);          // Retorna Item com menor campo 'value' da PQ
bool PQ_empty(Heap* heap);        // Retorna True se a PQ não tem elementos
int  PQ_size(Heap* heap);         // Número de elementos na PQ
void PQ_finish(Heap* heap);       // Libera memória

#endif
