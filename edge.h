#ifndef EDGE_H
#define EDGE_H

#include <stdio.h>

typedef struct edge Edge;

/*
*  Ira inicializar e criar uma Edge (Que liga servidor ao cliente)
*  inputs: A origem, o destino e o peso deles
*  output: Ponteiro para uma Edge
*  pre-condicao: -
*  pos-condicao: A Heap deverá estar criada
*/
Edge *createEdge(int src, int dest, double weight);

/*
*  Imprime uma estrutura Edge
*  inputs: Um ponteiro para Edge
*  output: -
*  pre-condicao: O Edge deve existir
*  pos-condicao: O Edge não é alterado
*/
void printEdge(Edge* edge);

/*
*  Imprime uma estrutura Edge em um arquivo passado
*  inputs: Um ponteiro para Edge e um Arquivo
*  output: -
*  pre-condicao: O Edge deve existir
*  pos-condicao: O Edge não é alterado
*/
void printEdgeFile(Edge *edge, FILE* file);


int compareEdges(const void *a, const void *b);

/*
*  Ordena um vetor de Edges
*  inputs: Um ponteiro para um vetor de Edge e um inteiro com seu tamanho
*  output: -
*  pre-condicao: O vetor de Edges deve existir
*  pos-condicao: O Edge estará ordenado do menor para o maior tamanho
*/
void sortEdgesByWeight(Edge **edges, int num);

/*
*  Libera a memória das Edges
*  inputs: Um ponteiro para Edge
*  output: -
*  pre-condicao: O Edge deve existir
*  pos-condicao: O Edge não deve existir mais
*/
void freeEdge(Edge* edge);

#endif