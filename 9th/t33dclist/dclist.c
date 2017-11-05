#include <stdio.h>
#include <stdlib.h>
#include "dclist.h"

void PushFront(List **L, Type x)
{
  List *newEl;
  newEl = malloc(sizeof(List));
  newEl->key = x;
  newEl->next = (*L)->next;
  newEl->prev = (*L);
  newEl->prev->next = newEl;
  newEl->next->prev = newEl;
}

void PushBack(List **L, Type x)
{
  List *newEl;
  newEl = malloc(sizeof(List));
  newEl->key = x;
  newEl->next = (*L);
  newEl->prev = (*L)->prev;
  newEl->prev->next = newEl;
  newEl->next->prev = newEl;

}
void Display(List *head)
{
  List *L;
  for(L = head->next; L != head; L = L->next)
    printf("%lf ", L->key);
  printf("\n");
}
/*
int InsertAfter(List **head, Type x, Type afterwhat)
{
  List *L = *head;
  List *newEl;
  int k = 0;
  while(L->next != *head && L->key != afterwhat)
  {
    L = L->next;
    k = 1;
  }
  if (L->next == *head && k == 1 && L->key != afterwhat)
    return 0;
  newEl = malloc(sizeof(List));
  newEl->key = x;
  newEl->next = L->next;
  newEl->prev = L;
  L->next->prev = newEl;
  L->next = newEl;
  return 1;
}

int InsertBefore(List **head, Type x, Type beforewhat)
{
  List *L = *head;
  List *newEl;
  int k = 0;
  while(L->prev != *head && L->key != beforewhat)
  {
    L = L->prev;
    k = 1;
  }
  if (L->prev == *head && k == 1 && L->key != beforewhat)
    return 0;
  newEl = malloc(sizeof(List));
  newEl->key = x;
  newEl->prev = L->prev;
  newEl->next = L;
  L->prev->next = newEl;
  L->prev = newEl;
  if((*head)->key == beforewhat)
    *head = newEl;
  return 1;
}

*/

int PopFront(List **L)
{
  List *toDelete = ((*L)->next);
  (*L)->next = (*L)->next->next;
  (*L)->next->prev = (*L);
  free(toDelete);
  return 1;
}

int PopBack(List **L)
{
  List *toDelete = ((*L)->prev);
  (*L)->prev = (*L)->prev->prev;
  (*L)->prev->next = (*L);
  free(toDelete);
  return 1;
}


List *Init(void)
{
  List *L = malloc(sizeof(List));
  L->key = -1;
  L->next = L;
  L->prev = L;
  return L;
}
/*
int Find(List **head, Type x)
{
  List *L;
  if((*head)->key == x)
      return 1;
  for(L = (*head)->next; L != *head; L = L->next)
    if(L->key == x)
      return 1;
  return 0;
}

int Replace(List **head, Type x, Type y)
{
  List *L;
  for(L = (*head)->next; L != *head; L = L->next)
    if(L->key == x)
    {
      L->key = y;
      return 1;
    }
  return 0;
}
*/

void FreeList(List *head)
{
  List *L;
  for(L = head->next->next; L != head; L = L->next)
    free(L->prev);
  if(L != L->prev)
    free(L->prev);
  free(L);
}
void DisplayReverse(List *head)
{
  List *L;
  for(L = head->prev; L != head; L = L->prev)
    printf("%f ", L->key);
  printf("\n");
}

void EraseFirst(List **head, Type x)
{
  List *toDelete, *L;
  int k = 0;
  for(L = (*head)->next; L != (*head); L = L->next)
    if(L->key == x)
    {
      k = 1;
      break;
    }
  if(k == 1)
  {
    L->next->prev = L->prev;
    L->prev->next = L->next;
    free(L);
  }
  if((*head)->key == x)
    (*head)->key = -1;
}

