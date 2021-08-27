// Program to find Dijkstra's shortest path using
// priority_queue in STL
#include "PQ.h"
#include "list.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define INF 9999

// This class represents a directed graph using
// adjacency list representation
struct graph {
    int V; // No. of vertices

    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    List** adj;
};

typedef struct graph Graph;

Graph *initGraph(int V) {
    Graph *graph = (Graph *)(malloc(sizeof(Graph)));
    graph->V = V;

    // graph->adj = (Item **)malloc(sizeof(Item *) * V);
    graph->adj = (List**)malloc(sizeof(List *) * V);
    for(int i=0; i < V; i++)
        graph->adj[i] = InitList(ITEM);
    	
    return graph;
}

void printGraph(Graph* g){
     for (int i = 0; i < g->V; i++)
	    PrintList(g->adj[i], "Graph");
}

void printDist(double* dist, int size){
    printf("------ DIST -------\n");

    for (int i = 0; i < size; i++)
    printf("%lf\n", dist[i]);

}
// function to add an edge to graph
void addEdge(int u, int v, int w, Graph *g) {
	InsertList(g->adj[u],criaItem(w, v));
	InsertList(g->adj[v],criaItem(w, u));
}

// Prints shortest paths from src to all other vertices
void shortestPath(Graph *graph, int src) {

    int V = graph->V; // Pega o numero de vertices do grafo

    Heap *heap = PQ_init(V); // inicia a heap

    double *dist = (double *)malloc(sizeof(double) * V);

    for (int i = 0; i < V; i++) {
        dist[i] = (double)INT_MAX;
        Item* item = criaItem(dist[i], i);
        PQ_insert(item, heap);
    }

    PQ_setPeso(heap, src, 0);
    dist[src] = 0;
    
    while (!PQ_empty(heap)) {
        Item *vertex = PQ_delmin(heap);
        int indice = retornaId(vertex);
        
        List* list = graph->adj[indice];

		int tam = GetSize(list);
        for (int i = 0; i < tam; i++) {
	 		Item* item = (Item*)GetItemList(list, i);
            
            int v = retornaId(item);
            int weight = retornaPeso(item);

             // If there is shorted path to v through u.
             if (dist[indice] != (double)INT_MAX  && dist[v] > dist[indice] + weight) { 
                 // Updating distance of v
                dist[v] = dist[indice] + weight;
                
                PQ_setPeso(heap, v ,dist[v]);
             }
         }
    }

    // Print shortest distances stored in dist[]
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %f\n", i, dist[i]);
}

// Driver program to test methods of graph class
int main() {
    // create the graph given in above fugure
    int V = 9;
    Graph *graph = initGraph(V);

    // making above shown graph
    addEdge(0, 1, 4, graph);
    addEdge(0, 7, 8, graph);
    addEdge(1, 2, 8, graph);
    addEdge(1, 7, 11, graph);
    addEdge(2, 3, 7, graph);
    addEdge(2, 8, 2, graph);
    addEdge(2, 5, 4, graph);
    addEdge(3, 4, 9, graph);
    addEdge(3, 5, 14, graph);
    addEdge(4, 5, 10, graph);
    addEdge(5, 6, 2, graph);
    addEdge(6, 7, 1, graph);
    addEdge(6, 8, 6, graph);
    addEdge(7, 8, 7, graph);

    shortestPath(graph, 0);

    return 0;
}