/* Vadim Farutin, 8-1, 14.12.12
 * This programm tells if the year is biss.
 */
#include <stdio.h>

int BISS( int a )
{
  if (a % 4 == 0)
  {
    if (a % 100 == 0)
    {
      if (a % 400 == 0)
        return 0;
      else
        return 1;
    }
    return 0;
  }
  else
    return 1;
}

void main( void )
{
  int a, b;
  printf("Input the number of the year: ");
  scanf("%i", &a);
  b = BISS(a);
  if (b == 0)
    printf("This year is biss.\n");
  else
    printf("This year is not biss.\n");
}
