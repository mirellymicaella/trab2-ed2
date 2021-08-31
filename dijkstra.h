#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"


/*
*  Ira encontrar o menor caminho de uma determinada origin para um destination
*  inputs: Ponteiro do grafo e o indice da origin
*  output: Ponteiro do vetor de distancias
*  pre-condicao: Grafo deve existir e a origin ser válida
*  pos-condicao: O vetor de distancia não é nulo
*/
double *dijkstra(Graph *graph, int src);

#endif