#include "dijkstra.h"
#include "edge.h"
#include "graph.h"
#include "rtt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* LePontos(int tam, FILE* arq){
    int *vet = (int *)malloc(sizeof(int) * tam);

    for (int i = 0; i < tam; i++)
        fscanf(arq, "%d", &vet[i]);

    return vet;
}

int main(int argc, char const *argv[]) {

    int V, E, S, C, M;

    // Verifica se todas as infos foram dadas
    if (argc < 3) {
        printf("ERRO: Informações insuficientes.\n");
        return 0;
    }

    FILE *fileIn = fopen(argv[1], "r");
    FILE *fileOut = fopen(argv[2], "w");

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

    fscanf(fileIn, "%d %d", &V, &E);
    fscanf(fileIn, "%d %d %d", &S, &C, &M);

    Graph *graph = initGraph(V);
    Graph *graph2 = initGraph(V);

    int *servidores = LePontos(S, fileIn);
    int *clientes = LePontos(C, fileIn);
    int *monitores = LePontos(M, fileIn);

    int x, y;
    double z;

    // Cria 2 grafos, 1 para cada sentido
    for (int i = 0; i < E; i++) {
        fscanf(fileIn, "%d %d %lf", &x, &y, &z);
        addEdge(x, y, z, graph);
        addEdge2(x, y, z, graph2);
    }

    Rtt **servidorCliente = RTT(servidores, clientes, graph, graph2, S, C);

    Rtt **servidorMonitor = RTT(servidores, monitores, graph, graph2, S, M);

    Rtt **monitorCliente = RTT(monitores, clientes, graph, graph2, M, C);

    // printRTT(servidorCliente, clientes, S);
    // printRTT(servidorMonitor, monitores, S);
    // printRTT(monitorCliente, clientes, M);

    RTTx(servidorMonitor, monitorCliente, S, M, C, clientes, monitores);

    free(servidores);
    free(monitores);
    free(clientes);

    freeRTT(servidorCliente, S);
    freeRTT(servidorMonitor, S);
    freeRTT(monitorCliente, M);

    destroiGraph(graph);
    destroiGraph(graph2);

    fclose(fileIn);
    fclose(fileOut);

    return 0;
}
