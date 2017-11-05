/* Vadim Farutin, 8-1, 07.12.12
 * This program computes  LCM of two integers A and B.
 */
#include <stdio.h>

int GCD( int a, int b )
{
  int c;
  c = a % b;
  while (c != 0)
  {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}

int LCM( int a, int b )
{
  int lcm;
  lcm = a * b;
  lcm = lcm / GCD(a, b);
  return lcm;
}

void main( void )
{
  int a, b, d;
  printf("Input two integers: ");
  scanf("%i %i", &a, &b);
  d = LCM(a, b);
  printf("This is LCM of a and b : %i\n", d);
}












































