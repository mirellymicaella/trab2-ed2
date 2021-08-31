#include "graph.h"
#include "item.h"
#include <stdlib.h>

struct graph {
    int V;
    List **adj;
};

Graph *initGraph(int V) {
    Graph *graph = (Graph *)(malloc(sizeof(Graph)));
    graph->V = V;

    graph->adj = (List **)malloc(sizeof(List *) * V);
    for (int i = 0; i < V; i++)
        graph->adj[i] = initList();

    return graph;
}

void addEdge(int u, int v, double w, Graph *g) {
    insertList(g->adj[u], createItem(w, v));
}

void addEdge2(int u, int v, double w, Graph *g) {
    insertList(g->adj[v], createItem(w, u));
}

int getVerticesGraph(Graph *g) { return g->V; }

List* getAdjGraph(Graph* g, int index){
    return g->adj[index];
}

void destroiGraph(Graph* g) {
    for (int i = 0; i < g->V; i++)
        destroiList(g->adj[i]);
    free(g->adj);
    free(g);
}