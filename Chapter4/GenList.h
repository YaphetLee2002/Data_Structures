#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char ElementType;
typedef struct node {
    int tag;
    struct node * tlink;
    union {
        char ref;
        ElementType value;
        struct node *hlink;
    } info;
} GenListNode, *GenList;