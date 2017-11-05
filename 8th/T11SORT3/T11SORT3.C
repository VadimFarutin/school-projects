/*Farutin V., 8 - 1, 08.02.2013
  This Programm puts numbers in the correct order.
*/

#include <stdio.h>
#include "sort3.h"


void main( void )
{
  int a, b, c;
  printf("Input numbers:\n");
  scanf("%i%i%i", &a, &b, &c);
  sort3(a, b, c);
}
