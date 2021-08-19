#include "PQ.h"
#include "graph.h"

void djikstra(Graph *graph) {
    int V = getVerticesGraph(graph);
    int vertex, numEdges, dest;
    float newWeight;
    Edge **edges;

    Heap *heap = PQ_init(V);
    for (int i = 0; i < V; i++)
        PQ_insert(getEdgeGraph(graph, i), heap);

    while (PQ_empty(heap)) {
        vextex = PQ_delmin(heap);
        edges = getEdgesFromVertex(graph, vertex, &numEdges);

        for (int i = 0; i < numEdges; i++){
            dest = getEdgeDest(edges[i]);
            newWeight = getEdgeWeight(edges[i]) + 
        }
    }
}