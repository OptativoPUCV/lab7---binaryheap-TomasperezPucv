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
    pq ->heapArray = realloc(pq ->heapArray,pq->capac*(sizeof(heapElem)*2)+1);
    pq->capac=(pq->capac*2)+1;
  } 

  pq ->heapArray[pq->size].priority = priority;
  pq ->heapArray[pq->size].data = data;
  pq->size++;

  int i = pq->size-1;
  heapElem aux = pq ->heapArray[pq->size-1];
  while((i!= 0)&&(pq->heapArray[i].priority > pq->heapArray[(i-1)/2].priority)){
    aux = pq->heapArray[i];
    pq->heapArray[i] = pq->heapArray[(i-1)/2];
    pq->heapArray[(i-1)/2] = aux;
    i = (i-1)/2;
  }
  
}


void heap_pop(Heap* pq){
  heapElem aux = pq ->heapArray[(pq->size)-1];
  pq ->heapArray[(pq->size)-1] =pq ->heapArray[0];
  pq ->heapArray[0] = aux;
  pq ->heapArray[(pq->size)-1].priority =0;
  pq -> size --;
  int i=0;
  
  while(i< pq->size-1){
    //caso 1 sin hijos :(
    if(pq ->size == 1) break;
    //caso 2 1 hijo
    if((pq ->heapArray[(i*2)+1].data != NULL)||(pq ->heapArray[(i*2)+2].data != NULL)){
      if(pq -> heapArray[i].priority < pq -> heapArray[(i*2)+1].priority){
        aux = pq -> heapArray[i];
        pq -> heapArray[i]= pq -> heapArray[(i*2)+1];
        pq -> heapArray[(i*2)+1] = aux;
        i = (i*2)+1;
        
      }else{
        aux = pq -> heapArray[i];
        pq -> heapArray[i]= pq -> heapArray[(i*2)+2];
        pq -> heapArray[(i*2)+2] = aux;
        i = (i*2)+2;
      }
    }
    //caso 3 2 hijos
    if((pq ->heapArray[(i*2)+1].data != NULL)&&(pq ->heapArray[(i*2)+2].data != NULL)){
      if((pq -> heapArray[i].priority > pq -> heapArray[(i*2)+1].priority)&&(pq -> heapArray[i].priority > pq -> heapArray[(i*2)+2].priority)) break;
      if((pq -> heapArray[i].priority < pq -> heapArray[(i*2)+1].priority)&&(pq -> heapArray[i].priority > pq -> heapArray[(i*2)+2].priority)){
        aux = pq-> heapArray[i];
        pq-> heapArray[i] = pq-> heapArray[(i*2)+1];
        pq-> heapArray[(i*2)+1] = aux;
        i = (i*2)+1;
        
      }else{
        aux = pq-> heapArray[i];
        pq-> heapArray[i] = pq-> heapArray[(i*2)+2];
        pq-> heapArray[(i*2)+2] = aux;
        i = (i*2)+2;
      }
      
    }
}

Heap* createHeap(){
  Heap *nuevo =malloc(sizeof(Heap));
  nuevo ->heapArray = malloc(sizeof(heapElem)*3);
  nuevo ->capac =3;
  nuevo ->size = 0;
  
   return nuevo;
}
