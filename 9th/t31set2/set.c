#include "set.h"
#include <stdio.h>
#include <stdlib.h>

Type *elements = NULL;
Type *elements2 = NULL;
int elementsSize = 0;
int memorySize = 0;

void Display( void )
{
  int i;
  printf("{ ");
  if (elementsSize == 0)
    printf(" }\n");
  else 
  {
    for (i = 0; i < elementsSize - 1; i++)
      printf("%f, ", elements[i]);
    if (elementsSize != 0)
      printf("%f }\n", elements[i]);
    else
      printf(" }\n", elements[i]);
  }
}
int Add( Type x )
{
  int i;
  if (memorySize == elementsSize * sizeof(Type))
  {
    elements2 = malloc(elementsSize * sizeof(Type) * 2 + sizeof(Type));
    for (i = 0; i < elementsSize; i++)
      elements2[i] = elements[i];
    memorySize = memorySize * 2 + sizeof(Type);
    free(elements);
    elements = elements2;
  }
  elements[elementsSize] = x;
  elementsSize++;
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