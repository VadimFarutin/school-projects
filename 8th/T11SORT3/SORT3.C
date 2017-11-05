#include <stdio.h>

void sort3( int a, int b, int c )
{
  if (a > b)
  {
    if (b > c)
      printf("%i %i %i", c, b, a);
    else
    {
      if (a > c)
        printf("%i %i %i", b, c, a);
      else
        printf("%i %i %i", b, a, c);
    }
  }
  else
  {
    if (a > c)
      printf("%i %i %i", c, a, b);
    else
    {
      if (b > c)
        printf("%i %i %i", a, c, b);
      else
        printf("%i %i %i", a, b, c);
    }
  }
}