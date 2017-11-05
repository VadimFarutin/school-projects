//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "tree.h"

void main( void )
{
  TREE *head = NULL, *T;
  int ProgrammRuns = 1, t, x;
  while (ProgrammRuns)
  {
    printf("0 - Exit\n"
           "1 - Access\n"
           "2 - Display\n"
           "3 - Display2\n"
           "4 - Insert\n"
           "5 - Find\n"
           "6 - Erase\n"
           "7 - Display3\n"
           "8 - EraseRight\n"
           );
    t = _getch();
    switch (t)
    {
      case '0':
        ProgrammRuns = 0;
        break;
      case '1':
        printf("Input x: \n");
        scanf("%i", &x);
        T = Access(&head, x);
        break;
      case '2':
        Display(head);
        printf("\n");
        break;
      case '3':
        Display2(head, 1);
        printf("\n");
        break;
      case '4':
        printf("Input x: \n");
        scanf("%i", &x);
        Insert(&head, x);
        break;
      case '5':
        printf("Input x: \n");
        scanf("%i", &x);
        T = Find(head, x);
        if (T != NULL)
          printf("%i is in the tree.\n", x);
        else
          printf("%i is not in the tree.\n", x);
        break; 
      case '6':
        printf("Input x: \n");
        scanf("%i", &x);
        Erase(&head, x);
        break;
      case '7':
        Display3(head, 1);
        printf("\n");
        break; 
      case '8':
        printf("Input x: \n");
        scanf("%i", &x);
        EraseRight(&head, x);
        break;
    }
  }
  FreeTree(&head);
  MC_Stats();
}
