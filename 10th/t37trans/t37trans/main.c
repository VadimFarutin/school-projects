#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "engrus.h"

#define MAXS 10

void AddWordToList( LIST **L, char *eng, char *rus)
{
  LIST *newEl = malloc(sizeof(LIST));
  newEl->next = NULL;
  newEl->rus = rus;
  newEl->eng = eng;
  if ((*L) == NULL)
    *L = newEl;
  else
  {
    while ((*L)->next != NULL)
      L = &(*L)->next;
    (*L)->next = newEl;
  }
}
void AddWord( LIST **L )
{
  char *w1, *w2;
  static char buf[MAXS];
  printf("Input new word in english: ");
  scanf("%s", buf);
  w1 = malloc(strlen(buf) + 1);
  strcpy(w1, buf);
  printf("\n Input translation: ");
  scanf("%s", buf);
  w2 = malloc(strlen(buf) + 1);
  strcpy(w2, buf);
  AddWordToList(L, w1, w2);
  free(w1);
  free(w2);
}
void main( void )
{
  static char buf[MAXS];
  LIST *head = NULL;
  int ProgrammRuns = 1, t, c;
  while (ProgrammRuns)
  {
    printf("0 - Exit\n"
           "1 - Add word\n"
           "2 - Display\n"
           "3 - Delete\n"
           "4 - Find\n"
           "5 - Translate\n"
           );
    t = _getch();
    switch (t)
    {
      case '0':
        ProgrammRuns = 0;
        break;
      case '1':
        AddWord(&head);
        break;
      case '2':
        Display(head);
        break;
      case '3':
        printf("Input word: ");
        scanf("%s", buf);
        Delete(&head, buf);
        break;
      case '4':
        printf("Input word: ");
        scanf("%s", buf);
        c = Find(&head, buf);
        if (c)
          printf("Your word is in the list.\n");
        else
          printf("Your word is not in the list.\n");
        break;
      case '5'
        printf("Input words.\n");
        Translate(&head);
        break;
    }
  }
  FreeList(&head);
  MC_Stats();
}
