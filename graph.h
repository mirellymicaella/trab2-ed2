#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"
#include "list.h"

typedef struct graph Graph;

/*
*  Ira inicializar a estrutura grafo
*  inputs: Um inteiro para o tamanho do grafo
*  output: Ponteiro para o grafo
*  pre-condicao: -
*  pos-condicao: O grafo deve estar criado
*/
Graph *initGraph(int V);

void printGraph(Graph *g);

/*
*  Ira adicionar uma aresta ao grafo 
*  inputs: inteiros representando a origem e destino, double do peso e o Grafo
*  output: -
*  pre-condicao: Grafo deve existir
*  pos-condicao: O grafo deve estar com uma nova aresta
*/
void addEdge(int u, int v, double w, Graph *g);

void addEdge2(int u, int v, double w, Graph *g);

int getVerticesGraph(Graph *g);

List* getAdj(Graph* g, int index);

#endif