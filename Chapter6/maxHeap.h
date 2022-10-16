#include<stdio.h>
#define HeapSize 128
typedef int ElementType;
typedef struct {
    ElementType elem[HeapSize];
    int curSize;
} maxHeap;