#ifndef RTT_H
#define RTT_H

#include "graph.h"


typedef struct rtt Rtt;

Rtt* initRTT(int id, int tam);

static void addPeso(Rtt* rtt,double peso, int index);

void printRTT(Rtt **rtt, int *points, int tam) ;


Rtt** RTT(int* origem, int* destino, Graph* g1, Graph* g2, int limiteOrigem, int limiteDestino);

void RTTx(Rtt **servidorMonitor, Rtt **monitorCliente, int S, int M, int C, int *clientes,
           int *monitores);

void freeRTT(Rtt* rtt);

#endif