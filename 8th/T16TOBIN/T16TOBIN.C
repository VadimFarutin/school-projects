/*Farutin V., 8 - 1, 12.04.2013
  This Programm prints your number in binary.
*/

#include <stdio.h>

void PrintBinary( unsigned long n )
{
  int i;
  for(i = 31; i >= 0; i--)
    printf("%lu", (n >> i) & 1);
  printf("\n");
}
void SuperPrintBinary( unsigned long n )
{
  int i = 31, j;
  while(((n >> i) & 1) != 1 && i >= 0)
  {
    i--;
  }
  for(j = i; j >= 0; j--)
    printf("%lu", (n >> j) & 1);
}

int power( int n, int k )
{
  int i;
  for(i = 1; i < k; i++)
    n *= n;
  return n;
}
void SuperMegaPrintBinary( unsigned long n )
{
  int i = 31, j, k = 0, a = 0, c, x;
  while(((n >> i) & 1) != 1)
  {
    i--;
  }
  for(j = i; j >= 0; j--)
  {
    a += ((n >> j) & 1) * power(2, j);
  }
  while(power(3, k) <= a)
  {
    k++;
  }

  for(; k > 0; k--)
  {
    c = power(3, k);
    x = (a - a % c) / power(3, k);
    printf("%lu", x);
    a = a % c;
  }
}

void main( void )
{
  unsigned long n;
  printf("Input n:");
  scanf("%lu", &n);
  PrintBinary(n);
  SuperPrintBinary(n);
  SuperMegaPrintBinary(n);
}
