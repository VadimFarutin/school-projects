#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trans.h"

void Display( LIST *L )
{
  while (L != NULL)
  {
    printf("%s %s\n", L->eng, L->rus);
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
void Translate( LIST **L )
{
  char *delimiters = "1234567890 `!@#$%^&*()-=\_+|[]{};':,./<>?";
  char c;
  _getch(c);

}
void Delete( LIST **L, char *word )
{
  LIST *toDelete;
  while (*L != NULL)
  {
    if (strcmp((*L)->eng, word) == 0 || strcmp((*L)->rus, word) == 0)
    {
      toDelete = *L;
      *L = (*L)->next;
      free(toDelete->eng);
      free(toDelete->rus);
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
    free(toDelete->eng);
    free(toDelete->rus);
    free(toDelete);
  }   
}