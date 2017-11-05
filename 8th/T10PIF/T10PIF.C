/* Vadim Farutin, 8-1, 08.02.13
 * This programm makes the table of Pifagor.
 */

#include <stdio.h>

void Pif( int n )
{
  int i, k;
  for (k = 1; k <= n; k++)
  {
    for (i = k; i <= k * n; i = i + k)
    {
      printf("%3i", i);
    }
    printf("\n");
  }
}

void main( void )
{
  int n;
  printf("Input your number: \n");
  scanf("%i", &n);
  Pif(n);
}

