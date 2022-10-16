typedef int ElementType;

#ifndef _LeftHeap_H
#define _LeftHeap_H

struct TreeNode;
typedef struct TreeNode *PriorityQueue;

/* Minimal set of priority queue operations */
/* Node that nodes will be shared among several leftist heaps after a merge; the users must make sure to not use the old leftist heaps */

PriorityQueue Initialize(ElementType X);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);

#define Insert(X, H) (H = Insert1((X), H))

PriorityQueue Insert1(ElementType X, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);

#endif /* _LeftHeap_H*/