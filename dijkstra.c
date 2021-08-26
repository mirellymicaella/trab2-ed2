#include "PQ.h"
#include "list.h"
#include "dijkstra.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void printDist(double *dist, int size) {
    printf("------ DIST -------\n");

    for (int i = 0; i < size; i++)
        printf("%d - %lf\n", i, dist[i]);
}

double *dijkstra(Graph *graph, int src) {

    int V = getVerticesGraph(graph); // Pega o numero de vertices do grafo
    Heap *heap = PQ_init(V); // inicia a heap
    double *dist = (double *)malloc(sizeof(double) * V);

    for (int i = 0; i < V; i++) {
        dist[i] = (double)INT_MAX;
        Item *item = criaItem(dist[i], i);
        PQ_insert(item, heap);
    }

    PQ_setPeso(heap, src, 0.0);
    dist[src] = 0.0;

    while (!PQ_empty(heap)) {
        Item *vertex = PQ_delmin(heap);
        int indice = retornaId(vertex);

        List *list = getAdj(graph, indice);

        int tam = GetSize(list);
        for (int i = 0; i < tam; i++) {
            Item *item = (Item *)GetItemList(list, i);

            int v = retornaId(item);
            double weight = retornaPeso(item);

            // If there is shorted path to v through u.
            if (dist[indice] != (double)INT_MAX && dist[v] > dist[indice] + weight) {
                // Updating distance of v
                dist[v] = dist[indice] + weight;
                PQ_setPeso(heap, v, dist[v]);
            }
        }
    }
    return dist;
}
