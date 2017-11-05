/* Vadim Farutin, 8-1, 01.02.13
 * This programm computes sinus and cosinus of X.
 */

#include <stdio.h>
#include <math.h>

double MySin( double x )
{
  double eps = 1e-6;
  double a = x;
  double xk = x;
  double f = 1;
  double sum = 0;
  int k = 0;
  int s = 1;
  while(a >= eps || a <= -eps)
  {
    sum += a;
    s = -s;
    xk = xk * x * x;
    f = f * (2 * k + 2) * (2 * k + 3);
    k++;
    a = s * xk / f;
  }
  return sum;
}

double MyCos( double x )
{
  double eps = 1e-6;
  double a = 1;
  double xk = 1;
  double f = 1;
  double sum = 0;
  int k = 0;
  int s = 1;
  while(a >= eps || a <= -eps)
  {
    sum += a;
    s = -s;
    xk = xk * x * x;
    f = f * (2 * k + 1) * (2 * k + 2);
    k++;
    a = s * xk / f;
  }
  return sum;
}

double MyP( void )
{
  int i = 1;
  int s = 1;
  double a = 1;
  double eps = 1e-9;
  double sum = 1;
  while(a >= eps || a <= - eps)
  {
    s = -s;
    i++;
    a = s / i;
    sum += a;
  }
  sum = sum * 4;
  return sum;
}

void main( void )
{
  double x;
  printf("Input X: ");
  scanf("%lf", &x);
  x = x * 3.1415926 / 180;
  printf("Sinus of X is %f, cosinus of X is %f.\nExact sinus: %f, exact cosinus: %f\n", MySin(x), MyCos(x), sin(x), cos(x));
  printf("%f", MyP());
}
