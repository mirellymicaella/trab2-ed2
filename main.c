#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "edge.h"
#include "dijkstra.h"

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
    
    int* servidores = (int*) malloc(sizeof(int) * S);
    int* clientes = (int*) malloc(sizeof(int) * C);;
    int* monitores = (int*) malloc(sizeof(int) * M);;
    
    Graph* graph = initGraph(V);

    //Le e armazena os servidores
    for(int i=0; i<S; i++){
        fscanf(fileIn, "%d", &servidores[i]);
    }

    //Le e armazena os clientes
    for(int i=0; i<C; i++){
        fscanf(fileIn, "%d", &clientes[i]);
    }

    //Le e armazena os monitores
    for(int i=0; i<M; i++){
        fscanf(fileIn, "%d", &monitores[i]);
    }

    Graph* graph2 = initGraph(V);

    int x, y;
    double z;
    //Le, cria e armazena edges no graph
    for(int i=0; i<E; i++){    
        fscanf(fileIn, "%d %d %lf", &x, &y, &z);
        addEdge(x, y, z, graph);
        addEdge2(x, y, z, graph2);
    }

    //1º parte RTT - a,b
    double* distAB;
    double* distBA;
    for(int i=0; i<S; i++){
        int numeroServidor = servidores[i];

        distAB = dijkstra(graph,numeroServidor);
        distBA = dijkstra(graph2,numeroServidor);

        for(int j=0; j<C; j++){
            int numeroCliente=clientes[j];          
            double resultado = distBA[numeroCliente]+distAB[numeroCliente];

            printf("%lf + %lf =  %f \n", distBA[numeroCliente],distAB[numeroCliente], resultado);

            
        }
        printDist(distAB, V);
        printf("\n");
    }
    //RTT∗ (0, 4) = min{RT T(0, 1) + RT T(1, 4), RT T(0, 2) + RT T(2, 4)}
    //RTT* 

    //  for(int i=0; i<S; i++){
    //     int numeroServidor = servidores[i];
    //     //printf("%d nm serv\n", numeroServidor);
    //     distAB = dijkstra(graph,numeroServidor);
    //     distBA = dijkstra(graph2,numeroServidor);
    //     //printDist(distAB,V);
    //     for(int l=0; l<M; l++){
            
        
    //         for(int j=0; j<C; j++){
    //             int numeroCliente=clientes[j];          
    //             double resultado = distBA[numeroCliente]+distAB[numeroCliente];
    //             printf("\033[0;35m");
    //             printf("%lf + %lf =  %f \n", distBA[numeroCliente],distAB[numeroCliente], resultado);
    //             printf("\033[0m");

    //         }
    //     }
    // }
    
    return 0;

}
