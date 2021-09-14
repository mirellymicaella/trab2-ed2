#include "dijkstra.h"
#include "edge.h"
#include "graph.h"
#include "rtt.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * readPoints(int size, FILE *file) {
    int *vet = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        fscanf(file, "%d", &vet[i]);
    return vet;
}

int main(int argc, char const *argv[]) {

    // Verifica se todas as infos foram dadas
    if (argc < 3) {
        printf("ERRO: Informações insuficientes.\n");
        return 0;
    }

    FILE* fileIn = fopen(argv[1], "r");
    FILE* fileOut = fopen(argv[2], "w");

    // Verifica se o arquivo digitado eh um endereco valido
    if (fileIn == NULL) {
        printf("Não foi possivel encontrar o arquivo %s \n", argv[1]);
        return 0;
    }
    // Verifica se o arquivo de said foi gerado corretamente
    if (fileOut == NULL) {
        printf("Não foi possivel criar o arquivo %s \n", argv[2]);
        return 0;
    }

    int V, E, S, C, M;

    // Faz a leitura da entrada para os valores dos tamanhos
    fscanf(fileIn, "%d %d", &V, &E);
    fscanf(fileIn, "%d %d %d", &S, &C, &M);

    // Inicia a estrutura Graph
    Graph *graph = initGraph(V);
    Graph *graph2 = initGraph(V);

    // Faz a leitura da entrada para cada vetor
    int *servers = readPoints(S, fileIn);
    int *clients = readPoints(C, fileIn);
    int *monitors = readPoints(M, fileIn);

    int x, y;
    double z;

    // Cria 2 grafos, 1 para cada sentido
    for (int i = 0; i < E; i++) {
        fscanf(fileIn, "%d %d %lf", &x, &y, &z);
        addEdge(x, y, z, graph);
        addEdge2(x, y, z, graph2);
    }

    // Pega todos os valores de RTT, sendo para S->C, S->M e M->C
    Rtt **serverClient = RTT(servers, clients, graph, graph2, S, C);
    Rtt **serverMonitor = RTT(servers, monitors, graph, graph2, S, M);
    Rtt **monitorClient = RTT(monitors, clients, graph, graph2, M, C);

    // Com os valores dos RTT, faz a divisão e pega os menores valores
    double *weights =
        RTTx(serverMonitor, monitorClient, S, M, C, clients, monitors, serverClient);

    // Inicia a estrutura Edge
    Edge** result = (Edge**) malloc(sizeof(Edge*)*S*C);

    // Cria as Edges com seus tamanhos e ID
    int k = 0;
    for(int i = 0; i < S; i++){
        int id = getIdItemRTT(serverClient[i]);
        Rtt* sc = serverClient[i];
        for(int j=0; j < C; j++, k++)
            result[k] = createEdge(id, clients[j], weights[k]);      
    }

    // Ordena o vetor de Edge do menor peso para o maior
    sortEdgesByWeight(result, S*C);

    // Imprime os resultados e libera a memoria das Edges
    for (int i = 0; i < S * C; i++){
        printEdgeFile(result[i], fileOut);
        freeEdge(result[i]);
    }

    // Faz todos os free's para liberar toda memória alocada
    free(result);

    free(servers);
    free(monitors);
    free(clients);

    free(weights);

    freeRTT(serverClient, S);
    freeRTT(serverMonitor, S);
    freeRTT(monitorClient, M);

    destroiGraph(graph);
    destroiGraph(graph2);

    fclose(fileIn);
    fclose(fileOut);

    return 0;
}
