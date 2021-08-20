#include "PQ.h"
#include <limits.h>
#include "graph.h"

void djikstra(Graph *graph) {
    int V = getVerticesGraph(graph); // Pega o numero de vertices do grafo
    int vertex, numEdges, dest;
    float newWeight;
    Edge **edges;

    Heap *heap = PQ_init(V); // inicia a heap
    for (int i = 0; i < V; i++){
        PQ_insert(criaItem((double)INT_MAX, i), heap);
    }

    //!Setar o valor de origem (vou deixar 0 mas deve ser o cliente)
    setPeso_PQ(heap, 0, 0);
        

    while (PQ_empty(heap)) {
        vextex = PQ_delmin(heap);
        edges = getEdgesFromVertex(graph, vertex, &numEdges);

        for (int i = 0; i < numEdges; i++){
            dest = getEdgeDest(edges[i]);
            newWeight = getEdgeWeight(edges[i]) + 
        }
    }
}