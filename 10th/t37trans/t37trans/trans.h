#include "memcheck.h"

typedef struct tagList LIST;
struct tagList
{
  char *eng;
  char *rus;
  LIST *next;
};
void Display( LIST *L );
void Delete( LIST **L, char *word );
int Find( LIST **L, char *word );
void FreeList( LIST **L );
void Translate( LIST **L );