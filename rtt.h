#ifndef RTT_H
#define RTT_H

#include "graph.h"

typedef struct rtt Rtt;

/*
*  Ira inicializar a estrutura RTT
*  inputs: O id e o tamanho máximo do vetor de pesos
*  output: Ponteiro pra um RTT
*  pre-condicao: -
*  pos-condicao: A Heap deverá estar criada
*/
Rtt* initRTT(int id, int tam);

/*
*  Imprime o vetor de RTT
*  inputs: Um ponteiro para um vetor de RTT, um vetor de pontos e o tamanho do vetor
*  output: -
*  pre-condicao: Ambos os vetores devem existir
*  pos-condicao: O RTT não será alterado
*/
void printRTT(Rtt **rtt, int *points, int tam);

/*
*  Ira armazenar todos as distancias minimas do valores encontrados no grafo dentro de um vetor
*  inputs: Vetor de origin, Vetor de destination, Ambos os grafos utilizados e os limites de origin e destination
*  output: Um vetor de RTT com todas as distâncias
*  pre-condicao: Os grafos e os vetores deverão existir
*  pos-condicao: As distâncias deverão estar armazenadas
*/
Rtt** RTT(int* origin, int* destination, Graph* g1, Graph* g2, int limitOrigin, int limitDestination);

double* RTTx(Rtt **servidorMonitor, Rtt **monitorCliente, int S, int M, int C, int *clientes, int *monitores, Rtt **servidorCliente);

int getIdItemRTT(Rtt *rtt);

double getWeightItemRTT(Rtt* rtt, int index);

/*
*  Liberará a memória do RTT
*  inputs: Um ponteiro para o RTT
*  output: -
*  pre-condicao: O RTT deve existir
*  pos-condicao: O RTT não deve existir mais
*/
void freeRTT(Rtt** rtt, int tam);

#endif