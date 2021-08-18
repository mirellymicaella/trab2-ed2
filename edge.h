#ifndef EDGE_H
#define EDGE_H

#include <stdio.h>

typedef struct edge Edge;


Edge *createEdge(int src, int dest, float weight);

int getEdgeSrc(Edge *edge);

int getEdgeDest(Edge *edge);

float getEdgeWeight(Edge *edge);

void printEdge(Edge* edge);

#endif