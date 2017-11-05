#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "binsh.h"


void main( void )
{
  int ProgrammRuns = 1, t, n = 0, x, max;
  int *a = NULL;
  while (ProgrammRuns)
  {
    printf("0 - Exit\n"
           "1 - Change array\n"
           "2 - Lower Bound\n"
           "3 - Upper Bound\n"
           );
    Display(a, n);
    t = _getch();
    switch (t)
    {
      case '0':
        ProgrammRuns = 0;
        break;
      case '1':
        free(a);
        printf("Input n and max: \n");
        scanf("%i %i", &n, &max);
        a = malloc(sizeof(int) * n);
        if( a == NULL )
        {
          printf("Not enough memory\n");
          return;
        }
        ChangeArray(a, n, max);
        break;
      case '2':
        printf("Input x: \n");
        scanf("%i", &x);
        printf("LowerBound(%i) = %i\n", x, LowerBound(a, n, x));
        break;
      case '3':
        printf("Input x: \n");
        scanf("%i", &x);
        printf("UpperBound(%i) = %i\n", x, UpperBound(a, n, x));
        break;     
    }
  }
  free(a);
}