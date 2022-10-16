#include <stdio.h>
#include <stdlib.h>
typedef struct node
{   int         data;
    struct node * next;
} NODE;

NODE * find( NODE * , int * );
void outputring( NODE * );
void change( int , int , NODE * );
void outputring( NODE * pring )
{	NODE * p;
	p = pring;
	if ( p == NULL )
		printf("NULL");
	else
		do	{	printf("%d", p->data);
			p = p->next;
		} while ( p != pring );
	printf("\n");
	return;
}

int main()
{   int n, m;
	NODE * head;//* pring;

	scanf("%d%d", &n, &m);
	head = (NODE *)malloc( sizeof(NODE) );
	head->next = NULL;
	head->data = -1;

	change( n, m, head );
	//pring = find( head, &n );
	printf("ring=%d\n", n);
	//outputring( pring );

	return 0;
}

void change( int n, int m, NODE * head )
{
    NODE * TmpHead, *TmpCell;
    TmpHead = head;

    int Remainder[10000];
    for (int i = 0; n != 0; i++)
    {
        TmpHead->data = n * 10 / m;
        n = n * 10 % m;
        Remainder[i] = n;
        for (int j = 0; j < i; j++)
            if(Remainder[j] == Remainder[i])
                return;
        TmpCell = (NODE*)malloc(sizeof(struct node));
        TmpCell->data = -1;
        TmpCell->next = NULL;
        TmpHead->next = TmpCell;
        TmpHead = TmpCell;
    }
}

//NODE * find( NODE * head, int * n )
//{
//}