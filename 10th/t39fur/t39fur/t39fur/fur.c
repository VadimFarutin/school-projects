#include <stdio.h>
#include <stdlib.h>
#include "fur.h"
#define MAXN 20

void FreeTree( TREE **T )
{
  if (*T == NULL)
    return;
  FreeTree(&(*T)->left);
  FreeTree(&(*T)->right);
  free((*T)->s);
  free(*T);
}
void Create( TREE **T, FILE *F )
{
  int i = 0;
  *T = malloc(sizeof(TREE));
  (*T)->s = malloc(sizeof(char) * MAXN);
  (*T)->left = NULL;
  (*T)->right = NULL;
  fscanf(F, "%c", &(*T)->s[i]);
  while ((*T)->s[i] != '(' && (*T)->s[i] != ')' && (*T)->s[i] != ',')
    fscanf(F, "%c", &(*T)->s[++i]);
  if ((*T)->s[i] == '(')
  {
    (*T)->s[i] = 0;
    Create(&(*T)->left, F);
  }
  if ((*T)->s[i] == ',' || (*T)->s[i] == ')')
  {
    while ((*T)->s[i] == ',' || (*T)->s[i] == ')')
    { 
      fscanf(F, "%c", &(*T)->s[++i]);
      (*T)->s[i - 1] = 0;
    }
    return;
  }
  (*T)->s[i] = 0;
  Create(&(*T)->right, F);
}

void Ask( TREE *T )
{
  char ans[3];
  if (T == NULL)
    return;
  printf("%s\n", T->s);
  gets(ans);
  if (ans[0] == 'Y')
    Ask(T->left);
  else 
    Ask(T->right);

}














