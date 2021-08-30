#include "rtt.h"
#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>

struct rtt {
    int id;
    double *pesos;
    int tam;
};

Rtt *initRTT(int id, int tam) {

    Rtt *rtt = (Rtt *)malloc(sizeof(Rtt));
    rtt->id = id;
    rtt->tam = tam;
    rtt->pesos = (double *)malloc(sizeof(double) * tam);

    return rtt;
}

static void addPeso(Rtt *rtt, double peso, int index) { rtt->pesos[index] = peso; }

int getIdRTT(Rtt *rtt){
    return rtt->id;
}

double getWeightRTT(Rtt* rtt, int index){
    return rtt->pesos[index];
}

void printRTT(Rtt **rtt, int *points, int tam) {
    for (int j = 0; j < tam; j++) {

        printf("---- RTT %d ----\n", rtt[j]->id);

        for (int i = 0; i < rtt[j]->tam; i++)
            printf("%d ( %lf )\n", points[i], rtt[j]->pesos[i]);
        printf("\n");
    }
}

Rtt **RTT(int *origem, int *destino, Graph *g1, Graph *g2, int limiteOrigem, int limiteDestino) {
    double *distAB;
    double *distBA;

    Rtt **rtts = (Rtt **)malloc(sizeof(Rtt *) * limiteOrigem);

    for (int i = 0; i < limiteOrigem; i++) {
        int numeroServidor = origem[i];
        rtts[i] = initRTT(numeroServidor, limiteDestino);

        distAB = dijkstra(g1, numeroServidor);
        distBA = dijkstra(g2, numeroServidor);

        for (int j = 0; j < limiteDestino; j++) {
            int numeroCliente = destino[j];
            double resultado = distBA[numeroCliente] + distAB[numeroCliente];
            addPeso(rtts[i], resultado, j);
        }
        free(distAB);
        free(distBA);
    }

    return rtts;
}

double* RTTx(Rtt **servidorMonitor, Rtt **monitorCliente, int S, int M, int C, int *clientes,
          int *monitores, Rtt **servidorCliente) {
    double *vetorSM = (double *)malloc(sizeof(double) * S * M);
    double *vetorMC = (double *)malloc(sizeof(double) * M * C);
    //double *vetorSMC = (double *)malloc(sizeof(double) * S * M * M * C);
    double *result = (double *)malloc(sizeof(double) * S * C);

    int aux = 0;

    // Armazena todas as distancias de servidor --> monitor
    for (int i = 0; i < S; i++) {
        for (int j = 0; j < M; j++) {
            //printf("(%d) --> (%d) = %.16lf\n", servidorMonitor[i]->id, monitores[j],
                  // servidorMonitor[i]->pesos[j]);
            vetorSM[aux] = servidorMonitor[i]->pesos[j];
            aux++;
        }
        //printf("\n");
    }
    aux = 0;
    //printf("---------------------------------------------------\n");
    // Armazena todas as distancias de monitor --> cliente
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < M; j++) {
           // printf("(%d) --> (%d) = %.16lf\n", monitorCliente[j]->id, clientes[i],
                   //monitorCliente[j]->pesos[i]);
            vetorMC[aux] = monitorCliente[j]->pesos[i];
            aux++;
        }
       // printf("\n");
    }
    aux = 0;
    int c = 0, m = 0, s = 0;
    
    double menor = 9999999.0;

    int auxVet1 = 0, auxVet2 = 0;

    int K=0;

    int auxVet0=0;
    int auxVet02=0;

    for(int i=0; i<S*C; i++){
        for(int j=0+auxVet1; j<M+auxVet1; j++){
            double peso = vetorSM[j] + vetorMC[auxVet2];
            
            if(peso < menor){
                menor = peso;
            }
            auxVet2++;
        }

        result[K] = menor/servidorCliente[auxVet0]->pesos[auxVet02];
        K++;
        auxVet02++;
        menor = 9999999.0;
        if(auxVet2==C*M){
            auxVet02 = 0;
            auxVet0++;
            auxVet1 += M;
            auxVet2=0;
            menor = 9999999.0;
        }

    }

    free(vetorSM);
    free(vetorMC);
    
    return result;
}

void freeRTT(Rtt **rtt, int tam) {
    for (int i = 0; i < tam; i++) {
        free(rtt[i]->pesos);
        free(rtt[i]);
    }
    free(rtt);
}