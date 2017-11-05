/*Farutin V., 9 - 1, 01.04.2014
  
*/

#include <stdio.h>
#include <conio.h>
#include "set.h"

void main( void )
{
  Type x;
  int ProgrammRuns = 1, t, i;
  while (ProgrammRuns)
  {
    printf("0 - Exit\n"
           "1 - Add Element\n"
           "2 - Remove Element\n"
           "3 - Find Element\n"
           );
    Display();
    t = getch();
    switch(t)
    {
      case '0':
        ProgrammRuns = 0;
        break;
      case '1':
        printf("Input element:");
        scanf("%lf", &x);
        i = Add(x);
        break;
      case '2':
        printf("Input element:");
        scanf("%lf", &x);
        Remove(x);
        break;
      case '3':
        printf("Input element:");
        scanf("%lf", &x);
        if(Find(x))
          printf("Yes\n");
        else
          printf("No\n");
        break;
      
    }
  }
}