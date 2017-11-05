#include "set.h"
#include <stdio.h>

Type elements[MAXN];
int elementsSize = 0;

void Display( void )
{
  int i;
  printf("{ ");
  for (i = 0; i < elementsSize - 1; i++)
    printf("%f, ", elements[i]);
  if (elementsSize != 0)
    printf("%f }\n", elements[i]);
  else
    printf(" }\n", elements[i]);
}
int Add( Type x )
{
  if (elementsSize <= MAXN)
  {
    elements[elementsSize] = x;
    elementsSize++;
    return 1;
  }
  return 0;
}
int FindPos( Type x )
{
  int i;
  for (i = 0; i < elementsSize; i++)
    if (elements[i] == x)
      return i;
  return -1;
}
void Remove( Type x )
{
  int i;
  if (FindPos(x) != -1)
  {
    for (i = FindPos(x); i < elementsSize - 1; i++)
      elements[i] = elements[i + 1];
    elementsSize--;  
  }
}

int Find( Type x )
{
  if(FindPos(x) != -1)
    return 1;
  return 0;
}