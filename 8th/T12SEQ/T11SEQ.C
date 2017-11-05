/* Vadim Farutin, 8-1, 15.02.13
 * This programm does many interesting things with your numbers.
 */

#include <stdio.h>

int s1( int num )
{
  int sum = 0;
  while (num > 0)
  {
    sum = sum + num % 10;
    num /= 10;
  }
  return sum;
}
int s2( int num )
{
  int sum = 0;
  num /= 10;
  while (num > 0)
  {
    sum = sum + num % 10;
    num /= 100;
  }
  return sum;
}
int s3( int num )
{
  int sum = 0;
  while (num > 0)
  {
    sum = sum + num % 10;
    num /= 100;
  }
  return sum;

}
void s4( void )
{
  int n, sum = 0;
  printf("Input your number: \n");
  scanf("%i", &n);
  while (n > 0)
  {
    if (s2(n) >= s3(n))
      sum++;
    printf("Input your number: \n");
    scanf("%i", &n);
  }
  printf("%i of your numers have s2 >= s3.\n", sum);

}
void main( void )
{
  int num;
  printf("Input your number: \n");
  scanf("%i", &num);
  printf("The sum of all digits of your number: %i.\n", s1(num));
  printf("The sum of all digits on the odd places of your number: %i.\n", s2(num));
  printf("The sum of all digits on the even places of your number: %i.\n", s3(num));
  s4();
}

