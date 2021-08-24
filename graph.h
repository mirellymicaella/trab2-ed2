#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"
#include "list.h"

typedef struct graph Graph;

Graph *initGraph(int V);

void printGraph(Graph *g);

void addEdge(int u, int v, int w, Graph *g);

int getVerticesGraph(Graph *g);

List* getAdj(Graph* g, int index);

#endif