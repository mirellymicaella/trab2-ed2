#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"

struct heap {
    int N;
    int* map;
    Item** pq;
};

static void swap(int i, int j, Heap* heap) {
    exch(heap->pq[i], heap->pq[j]);
    heap->map[id(heap->pq[i])] = i;
    heap->map[id(heap->pq[j])] = j;
}

static void fix_up(int k, Heap* heap) {
    while (k > 1 && more(heap->pq[k/2], heap->pq[k])) {
        swap(k, k/2, heap);
        k = k/2;
    }
}

static void fix_down(int sz, int k, Heap* heap){
    while (2*k <= sz) {
        int j = 2*k;
        if (j < sz && more(heap->pq[j], heap->pq[j+1])){
            j++;
        }
        if (!more(heap->pq[k], heap->pq[j])) {
            break;
        }
        swap(k, j, heap);
        k = j;
    }
}

Heap* PQ_init(int maxN) {
    Heap* h = (Heap*) malloc(sizeof(Heap));
    h->pq = initItem(maxN+1);
    h->map = (int *) malloc((maxN+1) * sizeof (int));
    h->N = 0;

    return h;
}

void PQ_insert(Item* v, Heap* heap) {
    heap->N++;
    heap->pq[heap->N] = v;
    heap->map[retornaId(v)] = heap->N;
    fix_up(heap->N, heap);
}

Item* PQ_delmin(Heap* heap) {
    Item* min = heap->pq[1];
    swap(1, heap->N, heap);
    heap->N--;
    fix_down(heap->N, 1, heap);
    return min;
}

Item* PQ_min(Heap* heap) {
    return heap->pq[1];
}

void PQ_decrease_key(int id, double value, Heap* heap) {
    int i = heap->map[id];
    value(heap->pq[i]) = value;
    fix_up(i, heap);
}

bool PQ_empty(Heap* heap) {
    return heap->N == 0;
}

int  PQ_size(Heap* heap) {
    return heap->N;
}

void PQ_setPeso(Heap* heap, int pos, double peso){

    int i = heap->map[pos];

    if (pos >= 0){
        setpeso_Item(heap->pq[i], peso);
        fix_up(i, heap);
    }

}

void PQ_finish(Heap* heap) {
    free(heap->pq);
    free(heap->map);
    free(heap);
}


