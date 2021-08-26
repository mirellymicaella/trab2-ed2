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
        graph->adj[i] = InitList(ITEM);

    return graph;
}

void printGraph(Graph *g) {
    for (int i = 0; i < g->V; i++)
        PrintList(g->adj[i], "Graph");
}

void addEdge(int u, int v, double w, Graph *g) {
    InsertList(g->adj[u], criaItem(w, v));
}

void addEdge2(int u, int v, double w, Graph *g) {
    InsertList(g->adj[v], criaItem(w, u));
}

int getVerticesGraph(Graph *g) { return g->V; }

List* getAdj(Graph* g, int index){
    return g->adj[index];
}