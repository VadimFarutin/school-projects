/* Vadim Farutin, 8-1, 21.12.12
 * This programm tells if the number is prime or composite
 */
#include <stdio.h>

int IsPrime( int a )
{
  int k;
  k = 1;
  if (a == 1)
    return 1;
  while (k < a - 1)
  {
    k++;
    if (a % k == 0)
      return 2;
  }
  return 0;
}

void main( void )
{
  int a, n;
  printf("Input your number.");
  scanf("%i", &a);
  n = IsPrime(a);
  if (n == 0)
    printf("%i is a prime number.\n", a);
  if (n == 1)
    printf("%i is not prime or composite number.\n", a);
  if (n == 2)
    printf("%i is a composite number.\n", a);
}
