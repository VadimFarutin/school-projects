/*Farutin V., 8 - 1, 22.02.2013
  This Programm computes sqare under your function.
*/

#include <stdio.h>
#include "fsqr.h"


void main( void )
{
  double a, b, n, l, t, m, sim;
  printf("Input a, b and n:");
  scanf("%lf%lf%lf", &a, &b, &n);
  l = AreaLeftBars(n, a, b);
  t = AreaTrap(n, a, b);
  m = AreaMiddle(n, a, b);
  sim = Simpson(n, a, b);
  printf("The sqare is: \n %f \n %f \n %f \n %f \n", l, t, m, sim);
}
