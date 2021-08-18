#include "edge.h"
#include <stdio.h>
#include <stdlib.h>

struct edge {
    int src;
    int dest;
    float weight;
};

Edge *createEdge(int src, int dest, float weight) {
    Edge *edge = (Edge *)malloc(sizeof(Edge));
    edge->src = src;
    edge->dest = dest;
    edge->weight = weight;

    return edge;
}

int getEdgeSrc(Edge *edge) { return edge->src; }

int getEdgeDest(Edge *edge) { return edge->dest; }

float getEdgeWeight(Edge *edge) { return edge->weight; }

void printEdge(Edge* edge){
    printf("%d --> %d  (%.17f) \n", edge->src, edge->dest, edge->weight );
}