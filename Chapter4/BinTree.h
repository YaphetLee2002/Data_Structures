typedef int ElementType;
#ifndef _BinTree_h
#define _BinTree_h

typedef struct TreeNode *BinTree;
typedef BinTree Position;   /* Node points to the binary tree */

void PreOrderTraversal(BinTree BT);
void InOrderTraversal(BinTree BT);
void PostOrderTraversal(BinTree BT);

#endif  /* _BinTree_h */