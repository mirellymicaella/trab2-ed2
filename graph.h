#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"

typedef struct graph Graph;

Graph* initGraph(int V, int E);

void insereEdges(Graph* g, Edge* edge, int i);

int retornaVerticesGraph(Graph* g);

int retornaEdgesGraph(Graph* g);

#endif