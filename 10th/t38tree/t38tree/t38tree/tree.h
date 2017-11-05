#include "memcheck.h"

typedef struct tagTREE TREE;
struct tagTREE
{
  int key;
  TREE *left;
  TREE *right;
};

TREE * Access( TREE **T, int x );
void Display( TREE *T );
void Display2( TREE *T, int depth );
void Display3( TREE *T, int depth );
void FreeTree( TREE **T );
void Insert( TREE **T, int x );
TREE * Find( TREE *T, int x );
void Erase( TREE **T, int x );
void EraseRight( TREE **T, int x );
