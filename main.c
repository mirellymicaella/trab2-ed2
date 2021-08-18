#include <stdio.h>
#include <string.h>
#include "edge.h"

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

    int servidores[S];
    int clientes[C];
    int monitores[M];
    Edge* edges[E];

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

    //Le, cria e armazena as arestas 
    for(int i=0; i<E; i++){
        int x, y;
        float z;
        fscanf(fileIn, "%d %d %f", &x, &y, &z);
        edges[i] = createEdge(x,y,z);
    }

    //print
    for(int i=0; i<E; i++){
        //printf("%d %d %f \n", getEdgeSrc(edges[i], getEdgeDest(edges[i]), getEdgeWeight(edges[i])));
        printEdge(edges[i]);
    }

    
    
    return 0;

}