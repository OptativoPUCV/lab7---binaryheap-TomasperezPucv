#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
    if(pq -> size ==0) return NULL;
    return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq -> capac == pq ->size){
    pq ->heapArray = realloc(pq ->heapArray, (sizeof(heapElem)*2)+1);
    pq->capac*=2;
  } 

  pq ->heapArray[pq->size].priority = priority;
  pq ->heapArray[pq->size].data = data;
  pq->size++;
  
  if(pq ->heapArray[pq->size].priority > pq ->heapArray[pq->size/2].priority){
    heapElem aux =pq ->heapArray[pq->size];
    pq ->heapArray[pq->size] = pq ->heapArray[pq->size/2];
    pq ->heapArray[pq->size/2] = aux;
    
  }
}


void heap_pop(Heap* pq){
  
}

Heap* createHeap(){
  Heap *nuevo =malloc(sizeof(Heap));
  nuevo ->heapArray = malloc(sizeof(heapElem)*3);
  nuevo ->capac =3;
  nuevo ->size = 0;
  
   return nuevo;
}
