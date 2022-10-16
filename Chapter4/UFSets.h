#include<stdio.h>
#include<stdlib.h>
#define size 100
typedef struct {
    int parent[size];
}UFSets;

void Initial(UFSets S);
