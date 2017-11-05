/* Vadim Farutin, 8-1, 21.12.12
 * This programm computes C.
 */
#include <stdio.h>

float Factorial( int a )
{
  float fact;
  fact = 1;
  while (a != 0)
  {
    fact = fact * a;
    a = a - 1;
  }
  return fact;
}

float CNK( int n, int k )
{
  int c;
  if (n < k)
    return 0;
  c = Factorial(n) / Factorial(k) / Factorial(n - k);
  return c;
}

void main( void )
{
  int n, k;
  float d;
  printf("Input n and k. ");
  scanf("%i %i", &n, &k);
  d = CNK(n, k);
  if (d == 0)
    printf("N must be bigger than k!\n");
  else
    printf("The C is %f.\n", d);
}
