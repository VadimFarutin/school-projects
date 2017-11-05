//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "fur.h"

void main( void )
{
  TREE *head = NULL;
  FILE *F;
  F = fopen("fur.in", "rt");
  Create(&head, F);
  Ask(head);
  FreeTree(&head);
  fclose(F);
}
