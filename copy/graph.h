#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"

typedef struct graph Graph;

Graph* initGraph(int V, int E);

void insertEdgeGraph(Graph* g, Edge* edge, int i);

Edge* getEdgeGraph(Graph* g,  int i);

Edge** getEdgesFromVertex(Graph *g, int vertex, int* numEdges);

int getVerticesGraph(Graph* g);

int getEdgesGraph(Graph* g);
#endif