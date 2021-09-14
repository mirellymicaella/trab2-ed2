#include "PQ.h"
#include "list.h"
#include "dijkstra.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

double *dijkstra(Graph *graph, int src) {

    // Pega o numero de vertices do grafo
    int V = getVerticesGraph(graph); 

    // Inicia a heap
    Heap *heap = initPQ(V); 

    // Inicia um vetor de distâncias auxiliares
    double *dist = (double *)malloc(sizeof(double) * V);

    //Loop responsável por preencher o vetor e a heap
    for (int i = 0; i < V; i++) {
        //Preenche com valores máximos
        dist[i] = (double)INT_MAX;
        Item *item = createItem(dist[i], i);
        insertPQ(item, heap);
    }

    //Seta o peso da origin para 0
    setWeightPQ(heap, src, 0.0);
    dist[src] = 0.0;

    //Realiza o algoritmo enquanto a heap não tiver vazia
    while (!isEmptyPQ(heap)) {
        //Retira o menor valor da heap e pega o seu index
        Item *vertex = delMinPQ(heap);
        int index = getIdItem(vertex);

        //Recupera a lista que está presente o valor acima
        List *list = getAdjGraph(graph, index);
        int tam = getSizeList(list);

        for (int i = 0; i < tam; i++) {
            Item *item = (Item *)getItemList(list, i);

            int v = getIdItem(item);
            double weight = getWeightItem(item);

            // Verifica se existe uma distância menor
            if (dist[index] != (double)INT_MAX && dist[v] > dist[index] + weight) {
                // Atualiza o valor da distância em v
                dist[v] = dist[index] + weight;
                // Seta o peso em v na heap também
                setWeightPQ(heap, v, dist[v]);
            }
        }
    }

    destroyPQ(heap, V+1);
    //Retorna o vetor de distâncias auxiliares
    return dist;
}
