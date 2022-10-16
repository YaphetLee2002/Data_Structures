#include<cstdio>
#include<stack>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
typedef int ElementType;
typedef struct TreeNode * BinTree;

struct TreeNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree ReBiTree( string PostOrder , string InOrder , int i , int j , int k , int h )  // ， ，后序第一个元素，后序最后一个元素，中序第一个元素，中序最后一个元素   
{  
    BinTree T;  
    T=(BinTree)malloc(sizeof(TreeNode));  
    T->Data = PostOrder[j];     //找到根结点   
    int m=k;   
    while( InOrder[m] != PostOrder[j] )  
    {  
        m++;   
    }  
    if( InOrder[k] == PostOrder[j] ){  
        T->Left=NULL;  //无左孩子   
    }  
    else{  
        T->Left=ReBiTree(  PostOrder , InOrder , i , i+m-k-1 , k , m-1 );  
    }  
    if( InOrder[h] == PostOrder[j] ){  
        T->Right=NULL;   //无右孩子   
    }  
    else{  
        T->Right=ReBiTree( PostOrder , InOrder , i+m-k , j-1 , m+1 , h );  
    }  
    return T;  
}

int main()
{
    string InOrder, PostOrder;
    cin >> InOrder;
    cin >> PostOrder;

    return 0;
}