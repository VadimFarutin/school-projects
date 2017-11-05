#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "dclist.h"

void main( void )
{
  List *head = Init();
  Type x, y, afterwhat, beforewhat;
  int ProgrammRuns = 1, t, i;
  while (ProgrammRuns)
  {
    printf("0 - Exit\n"
           "1 - PushFront\n"
           "2 - PushBack\n"
           "3 - InsertAfter\n"
           "4 - InsertBefore\n"
           "5 - PopFront\n"
           "6 - PopBack\n"
           "7 - EraseFirst\n"
           "8 - DisplayReverse\n"
           );
    Display(head);
    t = getch();
    switch(t)
    {
      case '0':
        ProgrammRuns = 0;
        FreeList(head);
        break;
      case '1':
        printf("Input X: \n");
        scanf("%lf", &x);
        PushFront(&head, x);
        break;
      case '2':
        printf("Input X: \n");
        scanf("%lf", &x);
        PushBack(&head, x);
        break;
  /*    case '3':
        printf("Input X and after what: \n");
        scanf("%lf %lf", &x, &afterwhat);
        i = InsertAfter(&head, x, afterwhat);
        break;
      case '4':
        printf("Input X and before what: \n");
        scanf("%lf %lf", &x, &beforewhat);
        i = InsertBefore(&head, x, beforewhat);
        break;*/
      case '5':
        PopFront(&head);
        break;
      case '6':
        PopBack(&head);
        break;
      case '7':
        printf("Input X: \n");
        scanf("%lf", &x);
        EraseFirst(&head, x);
        break;
      case '8':
        DisplayReverse(head);
        break;
    }
  }
  MC_Stats();
}
