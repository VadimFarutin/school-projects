/* Vadim Farutin, 8-1, 11.01.13
 * This programm tells the number of the day of the week for your day.
 */

#include <stdio.h>

long Day( int y, int m, int d )
{
  return (36525L * y / 100 + 306L * (m - 1) / 10 + d) % 7;
}

void main( void )
{
  int y, m, d;
  long s = Day(y, m, d);
  if (s == 0)
    s = 7;
  printf("Input your day: \n");
  scanf("%i%i%i", &y, &m, &d);
  printf("%i.%i.%i is %li\n", y, m, d, s);
}
