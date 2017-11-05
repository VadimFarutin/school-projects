/*Farutin V., 9 - 1, 10.09.2013
  This Programm sorts array.
*/

#include <stdio.h>
#include <conio.h>
#include "sort.h"

int ReadArray( Type *a )
{
  int n, i;
  printf("Input number of elements: ");
  scanf("%i", &n);
  printf("Input array's elements:");
  for (i = 0; i < n; i++)
    scanf("%i", &a[i]);
  return n;
}

void PrintArray( Type *a, int n )
{
  int i;
  for (i = 0; i < n; i++)
    printf("%i ", a[i]);
  printf("\n");
}

void PrintArray2( Type *a, int n )
{
  if (n <= 10)
    PrintArray(a, n);
  else
  {
    int i;
    for (i = 0; i < 5; i++)
      printf("%i ", a[i]);
    printf("... ");
    for (i = n - 3; i < n; i++)
      printf("%i ", a[i]);
    printf("\n");
  }
}

void main( void )
{
  int c, inp, ch;
  int ProgrammRuns = 1;
  int n = 3;
  static Type a[MAXN] = {3, 1, 2};
  while (ProgrammRuns)
  {
    printf("0 - Exit\n"
           "1 - Change array size\n"
           "2 - Set increase order\n"
           "3 - Set discrease order\n"
           "4 - Set random values\n"
           "5 - BubbleSort\n"
           "6 - SelectionSort\n"
           "7 - InsertionSort\n"
           "8 - MergeSort\n"
           "9 - Check\n"
           "h - HeapSort\n"
           "s - Save\n"
           "l - Load\n"
           "t - Table\n");
    printf("Array: ");
    PrintArray2(a, n);
    c = getch();
    switch(c)
    {
      case '0':
        ProgrammRuns = 0;
        break;
      case '1':
        printf("Input array size: ");
        scanf("%i", &inp);
        if (inp > 0 && inp < MAXN + 1)
          n = inp;
        else
          printf("Change your number.\n");
        break;
      case '2':
        SetIncreaseOrder(a, n);
        break;
      case '3':
        SetDiscreaseOrder(a, n);
        break;
      case '4':
        SetRandomOrder(a, n);
        break;
      case '5':
        BubbleSort(a, n);
        break;
      case '6':
        SelectionSort(a, n);
        break;
      case '7':
        InsertionSort(a, n);
        break;
      case '8':
        MergeSort(a, n);
        break;
      case '9':
        ch = Check(a, n);
        if(ch)
          printf("Array is unsorted.\n");
        else
          printf("Array sorted correctly.\n");
        break;
      case 'h':
        HeapSort(a, n);
        break;
      case 's':
        Save(a, n);
        break;
      case 'l':
        n = Load(a);
        break;
      case 't':
        Table(a, n);
        break;
      case 'q':
        QuickSort(a, 0, n - 1);
        break;

    }
  }
}
