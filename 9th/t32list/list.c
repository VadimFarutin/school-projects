#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void PushFront(List **L, Type x)
{
  List *newEl;
  newEl = malloc(sizeof(List));
  if (newEl == NULL)
    return;
  newEl->key = x;
  newEl->next = (*L);
  (*L) = newEl;
}

void PushBack(List **L, Type x)
{
  List *newEl;
  newEl = malloc(sizeof(List));
  newEl->key = x;
  while ((*L)->next != NULL)
    L = &(*L)->next;
  newEl->next = (*L)->next;
  (*L)->next = newEl;
}
void Display(List *L)
{
  while(L != NULL)
  {
    printf("%lf ", L->key);
    L = L->next;
  }
  printf("\n");
}
int InsertAfter(List **L, Type x, Type afterwhat)
{
  List *newEl;
  while(L != NULL && (*L)->key != afterwhat)
    L = &(*L)->next;
  if (*L == NULL)
    return 0;
  newEl = malloc(sizeof(List));
  newEl->key = x;
  newEl->next = (*L)->next;
  (*L)->next = newEl;
  return 1;
}

int InsertBefore(List **L, Type x, Type beforewhat)
{
  List *newEl;
  if ((*L)->next == NULL && (*L)->key == beforewhat)
    PushFront(&L, x);
  else
  {
    while((*L)->next != NULL && (*L)->next->key != beforewhat)
      L = &(*L)->next;
    if (*L == NULL)
      return 0;
    newEl = malloc(sizeof(List));
    newEl->key = x;
    newEl->next = (*L)->next;
    (*L)->next = newEl;
  }
  return 1;
}

int PopFront(List **L)
{
  List *toDelete;
  if (*L == NULL)
    return 0;
  toDelete = *L;
  *L = (*L)->next;
  free(toDelete);
  return 1;
}

int PopBack(List **L)
{
  while ((*L)->next != NULL)
  {
    L = &(*L)->next;
  }
  *L = NULL;
  free(*L);
  return 1;
}

void EraseFirst(List **L, Type x)
{
  List *toDelete;
  if ((*L)->key == x)
  {
    PopFront(&(*L));
    return;
  }
  while ((*L)->next != NULL && (*L)->next->key != x)
  {
    L = &(*L)->next;
  }
  if ((*L)->next == NULL)
    return;
  toDelete = (*L)->next;
  (*L)->next = (*L)->next->next;
  free(toDelete);
}