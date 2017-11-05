#include <time.h>
#include "sort.h"
#include <stdio.h>

void Save( Type *a, int n )
{
  int i;
  FILE *F;
  F = fopen(STATE_FILE, "wt");
  if (F == NULL)
  {
    printf("Could not open file " STATE_FILE);
    return;
  }
  fprintf(F, "%i\n", n);
  for (i = 0; i < n; i++)
    fprintf(F, "%i ", a[i]);
  fprintf(F, "\n");
  printf("Array is saved.\n");
  fclose(F);
}

int Load( Type *a )
{
  int i, n;
  FILE *F;
  F = fopen(STATE_FILE, "rt");
  if (F == NULL)
  {
    printf("Could not open file " STATE_FILE);
    return;
  }
  fscanf(F, "%i", &n);
  for (i = 0; i < n; i++)
    fscanf(F, "%i ", &a[i]);
  printf("Array is loaded.\n");
  fclose(F);
  return n;
}


void AntiQuick( Type *a, int n )
{
  int i;
  SelectionSort(a, n);
  Swap(&a[n - 1], &a[n - 2]);
  for (i = n - 3; i >= 0; i--)
    Swap(&a[i], &a[(n - 1 + i) / 2]);
}

void QuickSort( Type *a, int l, int r )
{
  int i = l, j = r;
  Type x = a[(l + r) / 2];
  if (l >= r)
    return;
  while (i < j)
  {
    while (a[i] < x)
      i++;
    while (a[j] > x)
      j--;
    if (i <= j)
    {
      if (i != j)
        Swap(&a[i], &a[j]);
      i++;
      j--;
    }
  }
  QuickSort(a, l, j);
  QuickSort(a, i, r);
}

void Table( Type *a, int n )
{
  long StartTime;
  int i, j;
  char* SortNames[5] =
  {
    "BubbleSort", "SelectionSort", "InsertionSort", "MergeSort", "HeapSort"
  };
  char* FillsNames[4] =
  {
    "increase order ", "discrease order ", "random values ", "AntiQuick"
  };
  void (*sorts[5])( Type * a, int n ) =
  {
    BubbleSort, SelectionSort, InsertionSort, MergeSort, HeapSort
  };
  void (*fills[4])( Type * a, int n ) =
  {
    SetIncreaseOrder, SetDiscreaseOrder, SetRandomOrder, AntiQuick
  };
  printf("%17s", "");
  for (i = 0; i < 4; i++)
    printf("%15s", FillsNames[i]);
  printf("\n");
  for (i = 0; i < 5; i++)
  {
    printf("%17s ", SortNames[i]);
    for (j  = 0; j < 4; j++)
    {
      fills[j](a, n);
      StartTime = clock();
      sorts[i](a, n);
      printf("%14.3f", (double)(clock() - StartTime) / CLOCKS_PER_SEC);
      if(!Check(a, n))
        printf("+");
      else
       printf("-");
    }
    printf("\n");
  }
  printf("%17s", "" "QuickSort");
  for (j  = 0; j < 4; j++)
    {
      fills[j](a, n);
      StartTime = clock();
      QuickSort(a, 0, n - 1);
      printf("%13.3f", (double)(clock() - StartTime) / CLOCKS_PER_SEC);
      if(!Check(a, n))
        printf("+");
      else
       printf("-");
    }
    printf("\n");
}

