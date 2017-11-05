/* Vadim Farutin, 8-1, 11.01.13
 * This programm solves Linear Equation.
 */

#include <stdio.h>

void main( void )
{
  float a, b, x;
  printf("Input a and b: \n");
  scanf("%f%f", &a, &b);
  if (a == 0)
  {
    if (b == 0)
      printf("Every number can be X.");
    else
      printf("There are not any numbers which X can be.");
  }
  else
  {
    x = (-b) / a;
    printf("X is %f\n", x);
  }
}
