#define MINTABLESIZE 10
typedef int ElemenType;

#ifndef _HashSep_H
#define _HashSep_H

typedef unsigned int Index;
struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;
Index Hash(ElemenType Key, int TableSize);

HashTable InitializeTable(int TableSize);
void DestoryTable(HashTable H);
Position Find(ElemenType Key, HashTable H);
void Insert(ElemenType Key, HashTable H);
ElemenType Retrieve(Position P);
/* Routines such as Delete and MakeEmpty are omitted */

#endif /* _HashSep_H */