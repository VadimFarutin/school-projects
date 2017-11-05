/* Vadim Farutin, 8-1, 14.12.12
 * This programm computes area of triangular with  three sides a, b and c.
 */
#include <stdio.h>
#include <math.h>

float area( int x, int y, int z )
{
  float p, s, d;
  p = x + y + z;
  p = p / 2;
  d = p * (p - x) * (p - y) * (p - z);
  s = sqrt(d);
  return s;
}

void main( void )
{
  int a, b, c;
  printf("Input three integers: ");
  scanf("%i %i %i", &a, &b, &c);
  if(a + b > c && a + c > b && b + c > a)
    printf("Area of triangular with these sides: %f\n", area(a, b, c));
  else
    printf("The triangular with these sides can not exist.\n");
}
