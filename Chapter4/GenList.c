#include "GenList.h"
#include<ctype.h>
void CreateList(char *s, int i, GenListNode *h, char L1[], GenList L2[], int k)
{
    GenListNode *p;
    char nam, ch;
    nam = ch;
    ch = s[i++];
    putchar(ch);
    if(isupper(ch)) {
        h = (GenListNode*) malloc(sizeof(GenListNode));
        h->tag = 2;
        nam = ch;
        ch = s[i++];
        if(ch == '(') {
            p = (GenListNode*) malloc(sizeof(GenListNode));
            p->tag = 0;
            p->info.ref = 1;
            h->info.hlink = p;
            L1[k] = nam;
            L2[k++] = p;
            if (s[i] == '#') {
                p->tlink = NULL;
                i++;
            }
            if(ch == ',')
                CreateList(s, i, h->tlink, L1, L2, k);
            else if(ch == ')')
                h->tlink == NULL;
        }
    }

    else if(islower(ch)) {
        h = (GenListNode*) malloc(sizeof(GenListNode));
        h->tag = 1;
        h->info.value = ch;
        nam = ch;
        ch = s[i++];
        if(ch == ',')
            CreateList(s, i, h->tlink, L1, L2, k);
        else if(ch == ')')
            h->tlink = NULL;
    }
}

void CreateGenList(char *s, GenList GL, char Ls1[], GenList Ls2[], int count)
{
    int i = 0;
    count = 0;
    CreateList(s, i, GL, Ls1, Ls2, count);
    GenListNode *p = GL->info.hlink;
    free(GL);
    GL = p;
}