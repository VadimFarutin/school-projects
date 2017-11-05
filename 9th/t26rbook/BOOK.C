#include <stdio.h>
#include <conio.h>
#include "book.h"

Record records[MAX_RECORDS];

void Init( void )
{
  int i;
  for (i = 0; i < MAX_RECORDS; i++)
    records[i].deleted = 1;
}

int GetRecordCount( void )
{
  int i, res = 0;
  for (i = 0; i < MAX_RECORDS; i++)
    if (records[i].deleted == 0)
      res++;
  return res;
}

int FindFirstFree( void )
{
  int i = 0;
  while (records[i++].deleted != 1)
    ;
  return i - 1;
}

int FGetStr( FILE *F, char *buf, int MaxLen )
{
  int c = 0, i = 0;
  while (MaxLen-- > 1)
  {
    int c = fgetc(F);
    if (c == '\n' || c == EOF)
      break;
      *buf++ = c;
    i++;
  }
  *buf = 0;
  return c != EOF;
}

void GetStr( char *buf, int MaxLen )
{
  FGetStr(stdin, buf, MaxLen);
}

long ReadLong(long a, long b)
{
  long x;
  while (scanf("%li", &x) != 1 || x < a || x > b)
  {
    printf("Error: must be in [%li; %li] \n", a, b);
  }
  return x;
}


void InputPupil( Pupil *p )
{
  printf("Input first name: \n");
  GetStr(p->name.name, MAXS);
  printf("Input surname: \n");
  GetStr(p->name.surname, MAXS);
  printf("Input form: \n");
  p->class.form = (int)ReadLong(1, 11);
  printf("Input index: \n");
  p->class.index = (int)ReadLong(1, 6);
  printf("Input age: \n");
  p->age = (int)ReadLong(1, 150);
  printf("Input phone number: \n");
  p->phoneNumber = ReadLong(0, 9999999);
}

void AddPupil( void )
{
  int id = FindFirstFree();
  if (id == -1)
    printf("Sorry.\n");
  else
  {
    InputPupil(&records[id].pupil);
    records[id].deleted = 0;
  }
}
/*
void PrintArray( char *a, int n )
{
  int i;
  for (i = 0; i < n; i++)
    printf("%c ", a[i]);
  printf("\n");
} */

int ReadArray( char *a )
{
  int i, n = 0;
  for (i = 0; i < MAXS; i++)
  {
    scanf("%c", &a[i]);
    if (a[i] == '\n')
      break;
    n++;
  }
  return n;
}

void PrintPupil( Pupil *p )
{
  puts(p->name.name);
  puts(p->name.surname);
  printf("Class : %i - %i \n", p->class.form, p->class.index);
  printf("Age : %i \n", p->age);
  printf("Phone number : %li \n", p->phoneNumber);
}

void PrintAll( void )
{
  int i;
  for (i = 0; i < GetRecordCount(); i++)
    PrintPupil(&records[i].pupil);
}

int FindRecordByName( char *name2 , int n )
{
  int i, j, r = 0;
  for (i = 0; i < GetRecordCount; i++)
  {
    for (j = 0; j < n; j++)
      if (records[i].pupil.name.name[j] != name2[j])
        r = -1;
    if (r == 0)
      return i;
  }
  return r;
}

int FindRecordBySurname( char *surname2 , int n )
{
  int i, j, r = 0;
  for (i = 0; i < GetRecordCount; i++)
  {
    for (j = 0; j < n; j++)
      if (records[i].pupil.name.surname[j] != surname2[j])
        r = -1;
    if (r == 0)
      return i;
  }
  return r;
}

void Save( void )
{
  FILE *F = fopen("book.txt", "wb");
  if (F != NULL)
  {
    fwrite(records, sizeof(Record), MAX_RECORDS, F);
    fclose(F);
  }
  else
    printf("Error.\n");
}

void Load( void )
{
  FILE *F = fopen("book.txt", "rb");
  if (F != NULL)
  {
    fread(records, sizeof(Record), MAX_RECORDS, F);
    fclose(F);
  }
  else
    printf("Error.\n");
}

void DeleteRecord( int id )
{
  records[id].deleted = 1;
}

