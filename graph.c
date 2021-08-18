#include <stdlib.h>
#include "graph.h"

struct graph {
    int V, E;
    Edge** edges;
};

Graph* initGraph(int V, int E){
    Graph* graph = (Graph*)(malloc(sizeof(Graph)));
    graph->V = V;
    graph->E = E;
 
    graph->edges = (Edge**)malloc(sizeof(Edge*)*E);

 
    return graph;
}

void insereEdges(Graph* g, Edge* edge, int i){
    g->edges[i] = edge;
}

int retornaVerticesGraph(Graph* g){
    return g->V;
}

int retornaEdgesGraph(Graph* g){
    return g->E;
}