#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"

struct heap {
    int N;
    int* map;
    Item** pq;
};

static void swap(int i, int j, Heap* heap) {
    int v1 = getIdItem(heap->pq[i]);
    int v2 = getIdItem(heap->pq[j]);

    int aux = heap->map[v1];
    heap->map[v1] = heap->map[v2];
    heap->map[v2] = aux;

    Item* it = heap->pq[i];
    heap->pq[i] = heap->pq[j];
    heap->pq[j] = it;
}

static void fix_up(int k, Heap* heap) {
    while (k > 1 && moreItem(heap->pq[k/2], heap->pq[k])) {
        swap(k, k/2, heap);
        k = k/2;
    }
}

static void fix_down(int sz, int k, Heap* heap){
    while (2*k <= sz) {
        int j = 2*k;
        if (j < sz && moreItem(heap->pq[j], heap->pq[j+1]))
            j++;
        
        if (!moreItem(heap->pq[k], heap->pq[j])) 
            break;
        
        swap(k, j, heap);
        k = j;
    }
}

Heap* initPQ(int maxN) {
    Heap* h = (Heap*) malloc(sizeof(Heap));
    h->pq = initItem(maxN+1);
    h->map = (int *) malloc((maxN+1) * sizeof (int));
    h->N = 0;

    return h;
}

void insertPQ(Item* v, Heap* heap) {
    heap->N++;
    heap->pq[heap->N] = v;
    heap->map[getIdItem(v)] = heap->N;
    fix_up(heap->N, heap);
}

void printPQ(Heap* heap){
     printf("------ HEAP -------\n");

    for(int i=1; i<= heap->N; ++i)
        printItem(heap->pq[i]);
    
    printf("--------------------\n");

}

Item* delMinPQ(Heap* heap) {
    Item* min = heap->pq[1];
    swap(1, heap->N, heap);
    heap->N--;
    fix_down(heap->N, 1, heap);
    return min;
}



Item* getMinPQ(Heap* heap) {
    return heap->pq[1];
}

void decreaseKeyPQ(int id, double value, Heap* heap) {
    int i = heap->map[id];
    setWeightItem(heap->pq[i], value);
    fix_up(i, heap);
}

bool isEmptyPQ(Heap* heap) {
    return heap->N == 0;
}

int  getSizePQ(Heap* heap) {
    return heap->N;
}

void setWeightPQ(Heap* heap, int pos, double peso){

    int i = heap->map[pos];

    if (pos >= 0){
        setWeightItem(heap->pq[i], peso);
        fix_up(i, heap);
    }

}

void destroyPQ(Heap* heap, int V) {
    destroyItem(heap->pq, V);
    free(heap->map);
    free(heap);
}


