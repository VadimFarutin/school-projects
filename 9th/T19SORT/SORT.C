#include "sort.h"
#include <stdlib.h>

void Swap( Type *a, Type *b )
{
  Type tmp = *a;
  *a = *b;
  *b = tmp;
}

void SelectionSort( Type *a, int n )
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

void BubbleSort( Type *a, int n )
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n - i; j++)
    {
      if (a[j] > a[j + 1])
        Swap(&a[j], &a[j + 1]);
    }
  }
}

void SetIncreaseOrder( Type *a, int n )
{
  int i;
  for (i = 0; i < n; i++)
    a[i] = i + 1;
}

void SetDiscreaseOrder( Type *a, int n )
{
  int i;
  for (i = 0; i < n; i++)
    a[i] = n - i;
}

void SetRandomOrder( Type *a, int n )
{
  int i;
  for (i = 0; i < n; i++)
    a[i] = rand();  // % 30 + 1;
}

void InsertionSort( Type *a, int n )
{
  Type x;
  int i, j;
  for (i = 1; i < n; i++)
  {
    x = a[i];
    for (j = i; j > 0 && a[j - 1] > x; j--)
      a[j] = a[j - 1];
    a[j] = x;
  }
}

void BubbleSort2( Type *a, int n )
{
  int i, j, k;
  for (i = 0; i < n; i++)
  {
    k = 0;
    for (j = 0; j < n - i; j++)
    {
      if (a[j] > a[j + 1])
      {
        Swap(&a[j], &a[j + 1]);
        k = 1;
      }
    }
    if (k == 0)
      break;
  }
}

void Merge( Type *a, int l, int r )
{
  static Type c[MAXN];
  int m = (l + r) / 2;
  int i = l, j = m + 1, k = l;
  while (i <= m && j <= r)
  {
    if (a[i] <= a[j])
      c[k++] = a[i++];
    else
      c[k++] = a[j++];
  }
  while (i <= m)
    c[k++] = a[i++];
  while (j <= r)
    c[k++] = a[j++];
  for (i = l; i <= r; i++)
    a[i] = c[i];
}

void MergeSortInt( Type *a, int l, int r )
{
  int m = (l + r) / 2;
  if (l == r)
    return;
  MergeSortInt(a, l, m);
  MergeSortInt(a, m + 1, r);
  Merge(a, l, r);
}

void MergeSort( Type *a, int n )
{
  MergeSortInt(a, 0, n - 1);
}

int Check( Type *a, int n )
{
  int i;
  for (i = 0; i < n - 1; i++)
    if (a[i] > a[i + 1])
      return 1;
  return 0;
}

void Heapify( Type *h, int hn, int v )
{
  int x = 2 * v + 1;
  while (x < hn && h[v] <= h[x])
  {
    if (x + 1 < hn && h[x + 1] > h[x])
      x++;
    Swap(&h[v], &h[x]);
    v = x;
    x = 2 * v + 1;
  }
}
void BuildHeap( Type *h, int hn )
{
  int v;
  for (v = (hn - 2) / 2; v >= 0; v--)
    Heapify(h, hn, v);
}

void HeapSort( Type *a, int n )
{
  BuildHeap(a, n);
  while (n > 1)
  {
    Swap(&a[0], &a[n - 1]);
    n--;
    Heapify(a, n, 0);
  }
}

