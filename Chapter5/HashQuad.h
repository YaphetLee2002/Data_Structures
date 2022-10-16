typedef int Elementype;
#define MINTABLESIZE 10

#ifndef _HashQuad_H
#define _HashQuad_H

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestoryTable(HashTable H);
Position Find(Elementype Key, HashTable H);
void Insert(Elementype Key, HashTable H);
Elementype Retrieve(Position P, HashTable H);
HashTable Rehash(HashTable H);
/* Routines such as Delete and MakeEmpty are omitted */

#endif /* _HashQuad_H */