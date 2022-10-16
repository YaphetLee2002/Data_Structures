#include"StaticLinkList.h"
void SLinkInsertSort(StaticLinkList SL)
{
    int i, p, pr;
    SL.Elem[0].Element = MAXVALUE;
    SL.Elem[0].link = 1;
    SL.Elem[1].link = 0;
    for (int i = 2; i < SL.n; i++) {
        p = SL.Elem[0].link;
        pr = 0;
        while (SL.Elem[p].Element <= SL.Elem[i].Element) {
            pr = p;
            p = SL.Elem[p].link;
        }
        SL.Elem[i].link = p;
        SL.Elem[pr].link = i;
    }
    
}