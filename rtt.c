#include "rtt.h"
#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 9999999.0

struct rtt {
    int id;
    double *weights;
    int tam;
};


Rtt *initRTT(int id, int tam) {

    Rtt *rtt = (Rtt *)malloc(sizeof(Rtt));
    rtt->id = id;
    rtt->tam = tam;
    rtt->weights = (double *)malloc(sizeof(double) * tam);

    return rtt;
}

static void addPeso(Rtt *rtt, double weight, int index) { rtt->weights[index] = weight; }

int getIdItemRTT(Rtt *rtt){
    return rtt->id;
}

double getWeightItemRTT(Rtt* rtt, int index){
    return rtt->weights[index];
}

void printRTT(Rtt **rtt, int *points, int tam) {
    for (int j = 0; j < tam; j++) {

        printf("---- RTT %d ----\n", rtt[j]->id);

        for (int i = 0; i < rtt[j]->tam; i++)
            printf("%d ( %lf )\n", points[i], rtt[j]->weights[i]);
        printf("\n");
    }
}

Rtt **RTT(int *origin, int *destination, Graph *g1, Graph *g2, int limitOrigin, int limitDestination) {
    double *distAB;
    double *distBA;

    Rtt **rtts = (Rtt **)malloc(sizeof(Rtt *) * limitOrigin);

    for (int i = 0; i < limitOrigin; i++) {
        int numeroServidor = origin[i];
        rtts[i] = initRTT(numeroServidor, limitDestination);

        distAB = dijkstra(g1, numeroServidor);
        distBA = dijkstra(g2, numeroServidor);

        for (int j = 0; j < limitDestination; j++) {
            int numeroCliente = destination[j];
            double resultado = distBA[numeroCliente] + distAB[numeroCliente];
            addPeso(rtts[i], resultado, j);
        }
        free(distAB);
        free(distBA);
    }

    return rtts;
}

double* RTTx(Rtt **servidorMonitor, Rtt **monitorClient, int S, int M, int C, int *clientes,
          int *monitores, Rtt **serverClient) {
    double *vetorSM = (double *)malloc(sizeof(double) * S * M);
    double *vetorMC = (double *)malloc(sizeof(double) * M * C);
    double *result = (double *)malloc(sizeof(double) * S * C);

    int aux = 0;

    // Armazena todas as distancias de servidor --> monitor
    for (int i = 0; i < S; i++) 
        for (int j = 0; j < M; j++,aux++) 
            vetorSM[aux] = servidorMonitor[i]->weights[j];

    aux = 0;

    // Armazena todas as distancias de monitor --> cliente
    for (int i = 0; i < C; i++) 
        for (int j = 0; j < M; j++, aux++) 
            vetorMC[aux] = monitorClient[j]->weights[i];

    aux = 0;
    int c = 0, m = 0, s = 0;
    
    double min = MAX;

    int auxVet1 = 0, auxVet2 = 0;
    int auxVet0=0, auxVet02=0;

    int K=0;


    for(int i=0; i<S*C; i++){
        for(int j=0+auxVet1; j<M+auxVet1; j++, auxVet2++){
            double weight = vetorSM[j] + vetorMC[auxVet2];
            if(weight < min) min = weight;
        }

        result[K] = min/serverClient[auxVet0]->weights[auxVet02];
        K++;
        auxVet02++;
        min = MAX;
        if(auxVet2==C*M){
            auxVet02 = 0;
            auxVet0++;
            auxVet1 += M;
            auxVet2=0;
            min = MAX;
        }

    }

    free(vetorSM);
    free(vetorMC);
    
    return result;
}

void freeRTT(Rtt **rtt, int tam) {
    for (int i = 0; i < tam; i++) {
        free(rtt[i]->weights);
        free(rtt[i]);
    }
    free(rtt);
}