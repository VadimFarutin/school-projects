/* Vadim Farutin, 8-1, 22.02.13
 * This programm searches Pifagor's 3 for your number.
 */

#include <stdio.h>
#include <math.h>

void Pif3( int n )
{
  int a, b, c;
  float eps = 0.5;
  for (c = 1; c <= n; c++)
    for (b = 1; b <= c; b++)
    {
      a = (int)(sqrt(c * c - b * b) + eps);
      if(a * a + b * b == c * c && a > 0 && a <= b)
        printf("%i^2 + %i^2 = %i^2\n", a, b, c);
    }
}

void FastPif3( int n )
{
  int a, b, c = n;
  float eps = 0.5;
  for(b = 1; b <= c; b++)
  {
    a = (int)(sqrt(c * c - b * b) + eps);
    if(a * a + b * b == c * c && a > 0 && a <= b)
    {
      printf("%i^2 + %i^2 = %i^2\n", a, b, c);
      b++;
    }
    else
    {
      c--;
    }
  }
}

void main( void )
{
  int n;
  printf("Input your number: \n");
  scanf("%i", &n);
  Pif3(n);
}

