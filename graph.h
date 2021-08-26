#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"
#include "list.h"

typedef struct graph Graph;

Graph *initGraph(int V);

void printGraph(Graph *g);

void addEdge(int u, int v, double w, Graph *g);

void addEdge2(int u, int v, double w, Graph *g);

int getVerticesGraph(Graph *g);

List* getAdj(Graph* g, int index);

#endif