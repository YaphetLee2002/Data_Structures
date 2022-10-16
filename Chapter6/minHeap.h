#include<stdio.h>
#include<stdlib.h>
#define heapSize 40
typedef int ElementType;
typedef struct {
    ElementType elem[heapSize];
    int curSize;
} minHeap;