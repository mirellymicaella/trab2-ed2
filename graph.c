#include "graph.h"
#include <stdlib.h>

struct graph {
    int V, E;
    Edge **edges;
};

Graph *initGraph(int V, int E) {
    Graph *graph = (Graph *)(malloc(sizeof(Graph)));
    graph->V = V;
    graph->E = E;

    graph->edges = (Edge **)malloc(sizeof(Edge *) * E);

    return graph;
}

void insertEdgeGraph(Graph *g, Edge *edge, int i) { g->edges[i] = edge; }

Edge** getEdgesFromVertex(Graph *g, int vertex, int* numEdges) {
    // Conta arestas associadas
    (*numEdges) = 0;
    for (int i = 0; i < g->V; i++)
        if (g->edges[i] == vertex) (*numEdges)++;

    Edge *edges[(*numEdges)];

    // Armazena as arestas associadas
    int indexEdges = 0;
    for (int i = 0; i < (*numEdges); i++)
        if (g->edges[i] == vertex) {
            edges[indexEdges] = g->edges[i];
            indexEdges++;
        }
    
    return edges;
}

Edge *getEdgeGraph(Graph *g, int i) { return g->edges[i]; }

int getVerticesGraph(Graph *g) { return g->V; }

int getEdgesGraph(Graph *g) { return g->E; }