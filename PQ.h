#ifndef PQ_H
#define PQ_H

#include <stdbool.h>
#include "item.h"

typedef struct heap Heap;

/*
*  Ira inicializar a estrutura Heap
*  inputs: Tamanho máximo da Heap
*  output: Ponteiro pra uma Heap
*  pre-condicao: -
*  pos-condicao: A Heap deverá estar criada
*/
Heap* PQ_init(int maxN); 

/*
*  Ira inserir um item na estrutura Heap
*  Sendo a maior prioridade o Item com menor campo de peso
*  inputs: Um ponteiro para um Item e um para a Heap
*  output: -
*  pre-condicao: A Heap e o Item devem existir
*  pos-condicao: A Heap foi alterada
*/
void PQ_insert(Item* v, Heap* heap);

/*
*  Removerá o Item com o menor peso da Heap
*  inputs: Um ponteiro para a Heap
*  output: O ponteiro para o Item retirado
*  pre-condicao: A Heap deve existir
*  pos-condicao: A Heap foi alterada
*/
Item* PQ_delmin(Heap* heap);

/*
*  Mudará a prioridade do nó com identificador 'id' para 'value'
*  inputs: Um Id, um Value e um ponteiro para a Heap
*  output: -
*  pre-condicao: A Heap deve existir
*  pos-condicao: A Heap foi alterada
*/
void PQ_decrease_key(int id, double value, Heap* heap); 

/*
*  Retornará um Item com menor peso da PQ e irá retira-lo
*  inputs: Um ponteiro para a Heap
*  output: Um ponteiro para o Item
*  pre-condicao: A Heap deve existir
*  pos-condicao: A Heap foi alterada
*/
Item* PQ_min(Heap* heap);

/*
*  Retornará True caso a PQ esteja vazia
*  inputs: Um ponteiro para a Heap
*  output: Um tipo bool
*  pre-condicao: A Heap deve existir
*  pos-condicao: A Heap não deve ser alterada
*/
bool PQ_empty(Heap* heap);        

/*
*  Retornará o numero de elementos da PQ
*  inputs: Um ponteiro para a Heap
*  output: O número de elentos
*  pre-condicao: A Heap deve existir
*  pos-condicao: A Heap não deve ser alterada
*/
int  PQ_size(Heap* heap);        

/*
*  Altera o peso de um elemento da heap
*  inputs: Um ponteiro para a Heap, a posicação que será alterada e o peso
*  output: -
*  pre-condicao: A Heap deve existir
*  pos-condicao: A Heap na posição 'pos' será alterada
*/
void PQ_setPeso(Heap* heap, int pos, double peso);

/*
*  Liberará a memória da heap
*  inputs: Um ponteiro para a Heap
*  output: -
*  pre-condicao: A Heap deve existir
*  pos-condicao: A Heap não deve existir mais
*/
void PQ_finish(Heap* heap);

/*
*  Imprime a Heap
*  inputs: Um ponteiro para a Heap
*  output: -
*  pre-condicao: A Heap deve existir
*  pos-condicao: -
*/
void PQ_print(Heap* heap);

#endif
