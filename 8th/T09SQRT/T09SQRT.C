/* Vadim Farutin, 8-1, 01.02.13
 * This programm computes square of X.
 */

#include <stdio.h>
#include <math.h>

double MySqrt( double x )
{
  double s;
  double eps = 1e-9;
  while(s * s - x >= eps || s * s - x <= -eps)
  {
    s = s / 2 + x / 2 / s;
  }
  return s;
}

void main( void )
{
  double x;
  printf("Input X: ");
  scanf("%lf", &x);
  if(x < 0)
    printf("X must not be fewer 0.\n");
  printf("Square of X: %f.Exact square: %f\n", MySqrt(x), sqrt(x));
}
