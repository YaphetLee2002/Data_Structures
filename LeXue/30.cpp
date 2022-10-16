#include<iostream>
#include<cstring>
#define NUM 1503
using namespace std;

struct Node
{
    int degree = 0;
    int to_link[NUM] = { 0 };
    int pointer = 0;
};

int main()
{
    int count = 0;
    while (~scanf("%d", &count))
    {
        int out_num = 0;
        Node *node = new Node[count];
        int node_1, link_num, node_2;

        for (int i = 0; i < count; i++)
        {
            scanf("%d:(%d)", &node_1, &link_num);
            for (int j = 0; j < link_num; j++)
            {
                scanf("%d", &node_2);
                node[node_1].degree++;
                node[node_2].degree++;
                node[node_1].to_link[node[node_1].pointer++] = node_2;
                node[node_2].to_link[node[node_2].pointer++] = node_1;
            }
        }

        int remain = count;  // 剩余人数
        while (remain > 0)
        {
            for (int i = 0; i < count; i++)
            {
                if (node[i].degree == 1)
                {
                    node[i].degree = 0;
                    remain--;
                    int j = 0;
                    while (node[node[i].to_link[j]].degree == 1 
                        && j < node[i].pointer)
                        j++;
                    int node_f = node[i].to_link[j];
                    node[node_f].degree = 0;
                    out_num++;
                    remain--;
                    for (int k = 0; k < node[node_f].pointer; k++)
                    {
                        if (node[node[node_f].to_link[k]].degree == 1)
                        {
                            node[node[node_f].to_link[k]].degree = 0;
                            remain--;
                        }
                        else
                            node[node[node_f].to_link[k]].degree--;
                    }
                }
            }
        }
        delete[] node;
        printf("%d\n", out_num);
    }
    return 0;
}