/* Vadim Farutin, 8-1, 15.02.13
 * This programm shows multiples of your number.
 */

#include <stdio.h>

int mult( int num )
{
  int i = 2, mult = 0, k = 0;
  while (num > 1)
  {
    for(k = 0; num % i == 0; k++)
    {
      num /= i;
    }
    printf("* %i^%i ", i, k);
    i++;
  }
  return 0;
}

void main( void )
{
  int num;
  printf("Input your number: \n");
  scanf("%i", &num);
  printf("%i = 1 ", num);
  mult(num);
}

