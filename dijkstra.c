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

    // Pega o numero de vertices do grafo
    int V = getVerticesGraph(graph); 

    // Inicia a heap
    Heap *heap = PQ_init(V); 

    // Inicia um vetor de distâncias auxiliares
    double *dist = (double *)malloc(sizeof(double) * V);

    //Loop responsável por preencher o vetor e a heap
    for (int i = 0; i < V; i++) {
        //Preenche com valores máximos
        dist[i] = (double)INT_MAX;
        Item *item = criaItem(dist[i], i);
        PQ_insert(item, heap);
    }

    //Seta o peso da origem para 0
    PQ_setPeso(heap, src, 0.0);
    dist[src] = 0.0;

    //Realiza o algoritmo enquanto a heap não tiver vazia
    while (!PQ_empty(heap)) {
        //Retira o menor valor da heap e pega o seu indice
        Item *vertex = PQ_delmin(heap);
        int indice = retornaId(vertex);

        //Recupera a lista que está presente o valor acima
        List *list = getAdj(graph, indice);
        int tam = GetSize(list);

        for (int i = 0; i < tam; i++) {
            Item *item = (Item *)GetItemList(list, i);

            int v = retornaId(item);
            double weight = retornaPeso(item);

            // Verifica se existe uma distância menor
            if (dist[indice] != (double)INT_MAX && dist[v] > dist[indice] + weight) {
                // Atualiza o valor da distância em v
                dist[v] = dist[indice] + weight;
                // Seta o peso em v na heap também
                PQ_setPeso(heap, v, dist[v]);
            }
        }
    }

    PQ_finish(heap, V+1);
    //Retorna o vetor de distâncias auxiliares
    return dist;
}
