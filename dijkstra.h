#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"

// #define BLACK "\033[0;30m" 
// #define RED "\033[0;31m" 
// #define GREEN "\033[0;32m"
// #define YELLOW "\033[0;33m"
// #define BLUE "\033[0;34m" 
// #define PURPLE "\033[0;35m"
// #define CYAN "\033[0;36m"
// #define WHITE "\033[0;37m" 
// #define RESET "\033[0m"

#define BLACK  printf("\033[0;30m") 
#define RED  printf("\033[0;31m") 
#define GREEN  printf("\033[0;32m")
#define YELLOW  printf("\033[0;33m")
#define BLUE  printf("\033[0;34m") 
#define PURPLE  printf("\033[0;35m")
#define CYAN  printf("\033[0;36m")
#define WHITE  printf("\033[0;37m") 
#define RESET  printf("\033[0m")

void printDist(double *dist, int size);

double *dijkstra(Graph *graph, int src);

#endif