#include <stdio.h>
#include <stdlib.h>

void Swap( int *a, int *b )
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
void SelectionSort( int *a, int n )
{
  int i, j, k;
  for (i = 0; i < n - 1; i++)
  {
    k = i;
    for (j = i + 1; j < n; j++)
    {
      if (a[k] > a[j])
      {
        k = j;
      }
    }
    Swap(&a[k], &a[i]);
  }
}
void BubbleSort( int *a, int n )
{
  int i, j;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - 1 - i; j++)
    {
      if (a[j] > a[j + 1])
        Swap(&a[j], &a[j + 1]);
    }
  }
}

void ChangeArray( int *a, int n, int max )
{
  int i;
  for(i = 0; i < n; i++)
    a[i] = rand() % max;
  BubbleSort(a, n);
}

void Display( int *a, int n )
{
  int i;
  printf("Index: ");
  for (i = 0; i < n; i++)
    printf("%i ", i);
  printf("\n");
  printf("Array: ");
  for (i = 0; i < n; i++)
    printf("%i ", a[i]);
  printf("\n");
}

int LowerBound( int *a, int n, int x )
{
  int L = -1, R= n - 1, m;
  while (R - L > 1)
  {
    m = (L + R) / 2;
    if (a[m] < x)
      L = m;
    else
      R = m;
  }
  return R;  
}
int UpperBound( int *a, int n, int x )
{
  int L = -1, R= n - 1, m;
  while (R - L > 1)
  {
    m = (L + R) / 2;
    if (a[m] > x)
      R = m;
    else
      L = m;
  }
  L++;
  return L; 
}