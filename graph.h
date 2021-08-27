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

/*
*  Ira imprimir um grafo
*  inputs: Ponteiro para grafo
*  output: -
*  pre-condicao: Grafo deve existir
*  pos-condicao: O grafo será impresso no terminal
*/
void printGraph(Graph *g);

/*
*  Ira adicionar uma aresta ao grafo no sentido de ida
*  inputs: inteiros representando a origem e destino, double do peso e o Grafo
*  output: -
*  pre-condicao: Grafo deve existir
*  pos-condicao: O grafo deve estar com uma nova aresta
*/
void addEdge(int u, int v, double w, Graph *g);

/*
*  Ira adicionar uma aresta ao grafo no sentido de volta
*  inputs: inteiros representando a origem e destino, double do peso e o Grafo
*  output: -
*  pre-condicao: Grafo deve existir
*  pos-condicao: O grafo deve estar com uma nova aresta
*/
void addEdge2(int u, int v, double w, Graph *g);

/*
*  Recupera o numero de vertices do grafo
*  inputs: Ponteiro para o grafo
*  output: Número de vértices do grafo
*  pre-condicao: Grafo deve existir
*  pos-condicao: O grafo não é alterado
*/
int getVerticesGraph(Graph *g);

/*
*  Recupera uma lista do grafo de acordo com o index
*  inputs: Ponteiro para o grafo e posição que deseja a lista
*  output: Um ponteiro para lista desejada
*  pre-condicao: Grafo deve existir e a lista deve existir na posição passada
*  pos-condicao: O grafo não é alterado
*/
List* getAdj(Graph* g, int index);

/*
*  Liberará a memória do grafo
*  inputs: Um ponteiro para o grafo
*  output: -
*  pre-condicao: O Grafo deve existir
*  pos-condicao: O Grafo não deve existir mais
*/
void destroiGraph(Graph* g);

#endif