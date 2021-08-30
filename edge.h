#ifndef EDGE_H
#define EDGE_H

#include <stdio.h>

typedef struct edge Edge;

Edge *createEdge(int src, int dest, double weight);

int getEdgeSrc(Edge *edge);

int getEdgeDest(Edge *edge);

double getEdgeWeight(Edge *edge);

void printEdge(Edge* edge);
void printEdgeFile(Edge *edge, FILE* file);

int compareEdges(const void *a, const void *b);

void SortEdgesByWeight(Edge **edges, int num);

void freeEdge(Edge* edge);

#endif