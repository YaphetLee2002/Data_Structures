#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct node
{
    int tag;
    int mark;
    struct node *tlink;
    union
    {
        ElementType data;
        struct node *hlink;
    } val;
} GLNode, *GList;
