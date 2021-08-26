#include "dijkstra.h"
#include "edge.h"
#include "graph.h"
#include "rtt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    int *servidores = (int *)malloc(sizeof(int) * S);
    int *clientes = (int *)malloc(sizeof(int) * C);
    int *monitores = (int *)malloc(sizeof(int) * M);

    Graph *graph = initGraph(V);

    // Le e armazena os servidores
    for (int i = 0; i < S; i++)
        fscanf(fileIn, "%d", &servidores[i]);

    // Le e armazena os clientes
    for (int i = 0; i < C; i++)
        fscanf(fileIn, "%d", &clientes[i]);

    // Le e armazena os monitores
    for (int i = 0; i < M; i++)
        fscanf(fileIn, "%d", &monitores[i]);

    Graph *graph2 = initGraph(V);

    int x, y;
    double z;

    // Cria 2 grafos, 1 para cada sentido
    for (int i = 0; i < E; i++) {
        fscanf(fileIn, "%d %d %lf", &x, &y, &z);
        //printf("%.16lf\n", z);
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

    //! SERVIDOR PARA CLIENTE
    //! SERVIDOR PARA MONITOR
    //! MONITOR PARA CLIENTE

    return 0;
}
