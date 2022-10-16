#include "GList.h"
void CreateList(char *s, int i, GLNode *g)
{
    char ch = s[i++];
    if (ch != '0')
    {
        if (ch == '(')
        {
            if (s[i] == ')')
            {
                g == NULL;
                i++;
            }
            else
            {
                g = (GLNode *)malloc(sizeof(GLNode));
                g->tag = 1;
                g->mark = 0;
                CreateList(s, i, g->val.hlink);
                CreateList(s, i, g->tlink);
            }
        }
        else if (ch == ')')
            g == NULL;
        else if (ch == ',')
        {
            g = (GLNode*) malloc(sizeof(GLNode));
            g->tag = 1;
            g->mark = 0;
            CreateList(s, i, g->val.hlink);
            CreateList(s, i, g->tlink); 
        }
        else
        {
            g = (GLNode*)malloc(sizeof(GLNode));
            g->tag = 0;
            g->mark = 0;
            g->val.data = ch;
        }
    }
}