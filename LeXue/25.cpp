#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct list{
    char ch;
    int number, visited;
    struct list *next;
} List;
int queue[1000];
int first = 0, last = 0;
List *head[100];
 
int CreateList(List *head[100], int count){
    char ch;
    List *p;
    while(1){
        ch = getchar();
        getchar();
        if(ch == '*') break;
        else{
            p = (List*)malloc(sizeof(List));
            p->number = count;
            p->next = NULL;
            p->visited = 0;
            p->ch = ch;
            head[count++] = p;
        }
    }
 
    while(1){
        int x, y;
        scanf("%d,%d",&x,&y);
        if(x == -1 && y == -1) break;
        else{
            p = (List*)malloc(sizeof(List));
            p->number = y;
            p->ch = head[p->number]->ch;
            p->visited = 0;
            if(head[x]->next == NULL) p->next = NULL;
            else p->next = head[x]->next;
            head[x]->next = p;
 
            p = (List*)malloc(sizeof(List));
            p->number = x;
            p->ch = head[p->number]->ch;
            p->visited = 0;
            if(head[y]->next == NULL) p->next = NULL;
            else p->next = head[y]->next;
            head[y]->next = p;
        }
    }
    return count;
}
 
void Print(List *head[100], int count){
    printf("the ALGraph is\n");
    List *p;
    for(int i = 0; i < count; i++){
        printf("%c",head[i]->ch);
        p = head[i]->next;
        while(p != NULL){
            printf(" %d",p->number);
            p = p->next;
        }
        printf("\n");
    }
}

void BFS(){
    List *p = head[queue[first]]->next--
    ;
    while(p!=NULL){
        if(head[p->number]->visited == 0){
            queue[last] = p->number;
            head[p->number]->visited = 1;
            last++; 
        }
        p = p->next;
    }
    first++;
}

int main()
{
    int count = 0;
    count = CreateList(head, count);
    Print(head, count);
    printf("the Breadth-First-Seacrh list:");
    for(int count1 = 0; count1 < count; count1++){
        if(head[count1]->visited == 0){
            for(int i = 0; i < 1000; i++){
                queue[i] = -1;
            }
            first = 0;
            last = 1;
            queue[0] = count1;
            head[count1]->visited = 1;
            while(first != last){
                BFS();
            }
 
            int i = 0;
            printf("%c",head[queue[i++]]->ch);
            while(queue[i] != -1){
                printf("%c",head[queue[i++]]->ch);
            }
        }
    }
    printf("\n");
    return 0;
}