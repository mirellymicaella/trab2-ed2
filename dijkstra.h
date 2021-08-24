#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"

void printDist(double *dist, int size);

double *dijkstra(Graph *graph, int src);

#endif