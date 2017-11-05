#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

TREE * Access( TREE **T, int x )
{
  if (*T == NULL)
  {
    *T = malloc(sizeof(TREE));
    if (*T == NULL)
    {
      printf("Not enough memory!\n");
      return NULL;
    }
    (*T)->key = x;
    (*T)->left = NULL;
    (*T)->right = NULL;
    return *T;
  }
  if ((*T)->key == x)
    return *T;
  if ((*T)->key > x)
    return Access(&(*T)->left, x);
  return Access(&(*T)->right, x);
}

void Display( TREE *T ) /*Straight Order*/
{
  if (T == NULL)
  {
    printf(" * ");
    return;
  }
  printf("%i(", T->key);
  Display(T->left);
  Display(T->right);
  printf(")");
}
void Display2( TREE *T, int depth ) 
{
  if (T == NULL)
  {
    return;
  }
  Display2(T->left, depth + 1);
  printf("%*s%i\n", depth, "", T->key);
  Display2(T->right, depth + 1);
}
void Display3( TREE *T, int depth )
{
  char c;
  for (c = 0; c < 100; c++)
    printf("%c", c);
  if (T == NULL)
  {
    return;
  }
  Display3(T->left, depth + 1);
  printf("%*s%i", depth - 1, "", T->key);
  if (T->left == NULL)
    if (T->right == NULL)
      c = 0;
    else
      c = 191;
  else
    if (T->right == NULL)
      c = 217;
    else
      c = 180;
  printf("%c\n", c);
  Display3(T->right, depth + 1);
}

void FreeTree( TREE **T )
{
  if (*T == NULL)
    return;
  FreeTree(&(*T)->left);
  FreeTree(&(*T)->right);
  free(*T);
}
void Insert( TREE **T, int x )
{
  TREE *newElement;
/*  if (*T == NULL)
  {
    *T = malloc(sizeof(TREE));
    if (*T == NULL)
    {
      printf("Not enough memory!\n");
      return;
    }
    (*T)->key = x;
    (*T)->left = NULL;
    (*T)->right = NULL;
    return;
  }
  if ((*T)->key == x)
  {
    newElement = malloc(sizeof(TREE));
    if (newElement == NULL)
    {
      printf("Not enough memory!\n");
      return;
    }
    newElement->key = x;
    newElement->left = (*T)->left;
    newElement->right = NULL; 
    (*T)->left = newElement;
    return;
  }*/
  if (*T == NULL || (*T)->key == x)
  {
    newElement = malloc(sizeof(TREE));
    if (newElement == NULL)
    {
      printf("Not enough memory!\n");
      return;
    }
    newElement->key = x;
    newElement->left = (*T)->left;
    newElement->right = NULL;
    if (*T == NULL)
      *T = newElement;
    else
      (*T)->left = newElement;
  }
  else if ((*T)->key > x)
    Insert(&(*T)->left, x);
  else
    Insert(&(*T)->right, x);
}
TREE * Find( TREE *T, int x )
{
  if (T == NULL)
    return 0;
  if (T->key == x)
    return T;
  if (T->key > x)
    return Find(T->left, x);
  return Find(T->right, x);
}

void Erase( TREE **T, int x )
{
  TREE *toDelete;
  if (*T == NULL)
    return;
  if ((*T)->key == x)
  {
    toDelete = *T;
    *T = (*T)->right;
    if (*T == NULL)
      *T = toDelete->left;
    else
    {
      while((*T)->left != NULL)
        T = &(*T)->left;
      (*T)->left = toDelete->left;
    }
    free(toDelete);
    return;
  }
  if ((*T)->key > x)
    Erase(&(*T)->left, x);
  Erase(&(*T)->right, x);
}
void EraseRight( TREE **T, int x )
{
  if (*T == NULL)
    return;
  if ((*T)->key == x)
  {
    FreeTree(&(*T)->right);
    (*T)->right = NULL;
    return;
  }
  if ((*T)->key > x)
    EraseRight(&(*T)->left, x);
  EraseRight(&(*T)->right, x);
}

