/* Vadim Farutin, 8-1, 11.01.13
 * This programm tells the number of the day of the week for your day.
 */

#include <stdio.h>

long Day( int y, int m, int d )
{
  m++;
  if (m <= 3)
  {
    y--;
    m += 12;
  }
  return (36525L * y / 100 + 306L * (m - 2) / 10 + d) % 7;
}

void main( void )
{
  int y, m, d;
  long s;
  printf("Input your day: \n");
  scanf("%i%i%i", &y, &m, &d);
  s = Day(y, m, d);
  if (s == 0)
    printf("%i.%i.%i is %li Sunday\n", y, m, d );
  if (s == 1)
    printf("%i.%i.%i is %li Monday\n", y, m, d );
  if (s == 2)
    printf("%i.%i.%i is %li Tuesday\n", y, m, d );
  if (s == 3)
    printf("%i.%i.%i is %li Wednesday\n", y, m, d );
  if (s == 4)
    printf("%i.%i.%i is %li Thursday\n", y, m, d );
  if (s == 5)
    printf("%i.%i.%i is %li Friday\n", y, m, d );
  if (s == 6)
    printf("%i.%i.%i is %li Saturday\n", y, m, d );
}
