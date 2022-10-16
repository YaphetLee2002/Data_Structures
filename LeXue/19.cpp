#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<iostream>
using namespace std;
struct Tree;
typedef struct Tree* TreeNode;
typedef char ElementType;
struct Tree{
    ElementType element;
    TreeNode sibling;
    TreeNode child;
};

TreeNode CreateNode()
{
    TreeNode T = (TreeNode)malloc(sizeof(struct Tree));
    T->element = '\0';
    T->sibling = NULL;
    T->child = NULL;
    return T;
}

void BuildTree(TreeNode T)
{
    T = CreateNode();
    char ch;
    ch = getchar();
    if(ch == ',')
        ch = getchar();
    if(isalpha(ch))
        T->element = ch;
    else if(ch == '(')
        BuildTree(T->child);
    else if(ch == ')')
        BuildTree(T->sibling);
}

int main()
{

}