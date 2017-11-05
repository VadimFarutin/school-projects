#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dict.h"

void Display( LIST *L )
{
  while (L != NULL)
  {
    printf("%s \n", L->word);
    L = L->next;
  }
  printf("\n");
}

int Find( LIST **L, char *word )
{
  while (*L != NULL)
  {
    if (!strcmp((*L)->word, word))
      return 1;
    L = &(*L)->next;
  }
  return 0;
}
void Delete( LIST **L, char *word )
{
  LIST *toDelete;
  while (*L != NULL)
  {
    if (strcmp((*L)->word, word) == 0)
    {
      toDelete = *L;
      *L = (*L)->next;
      free(toDelete);
      return;
    }
    L = &(*L)->next;
  }
}

void FreeList( LIST **L )
{
  LIST *toDelete;
  while (*L != NULL)
  {
    toDelete = *L;
    *L = (*L)->next;
    free(toDelete);
  }   
}