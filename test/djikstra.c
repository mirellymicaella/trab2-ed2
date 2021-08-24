#include "PQ.h"
#include <stdlib.h>
#include <limits.h>
#include "graph.h"

double* djikstra(Graph *graph, int src) {
    int vertex, numEdges, dest;
    float newWeight;
    Edge *edges;

    int V = getVerticesGraph(graph); // Pega o numero de vertices do grafo

    double* dist = (double*) malloc(sizeof(double)*V);

    Heap *heap = PQ_init(V); // inicia a heap

    for (int i = 0; i < V; i++){
        dist[i] = (double)INT_MAX;
        PQ_insert(criaItem(dist[i], i), heap);
    }

    setPeso_PQ(heap, src, 0);
    dist[src] = 0;

        
    while (PQ_empty(heap)) {
        Item* vertex = PQ_delmin(heap);
        int indice = retornaId(vertex);

        edges = getEdgeGraph(graph, indice);

        for (int i = 0; i < numEdges; i++){
            
        }
    }

    PQ_finish(heap);

    return dist;

}