#include "edge.h"
#include <stdio.h>
#include <stdlib.h>

struct edge {
    int src;
    int dest;
    double weight; 
};

Edge *createEdge(int src, int dest, double weight) {
    Edge *edge = (Edge *)malloc(sizeof(Edge));
    edge->src = src;
    edge->dest = dest;
    edge->weight = weight;

    return edge;
}


void printEdge(Edge *edge) {
    printf("%d --> %d  (%.16lf) \n", edge->src, edge->dest, edge->weight);
}

void printEdgeFile(Edge *edge, FILE* file) {
    fprintf(file,"%d %d %.16lf\n", edge->src, edge->dest, edge->weight);
}

int compareEdges(const void *a, const void *b) {
    double a1 = (*(Edge **)a)->weight;
    double b1 = (*(Edge **)b)->weight;

    if (a1 > b1) return 1;
    if (a1 < b1) return -1;
    return 0;
}

void sortEdgesByWeight(Edge **edges, int num) { qsort(edges, num, sizeof(Edge *), compareEdges); }

void freeEdge(Edge* edge){
    free(edge);
}