#include <stdio.h>
#include "str0.h"

int FGetStr( FILE *F, char *buf, int MaxLen )
{
  int c = 0;
  while (MaxLen-- > 1)
  {
    int c = fgetc(F);
    if (c == '\n' || c == EOF)
      break;
      *buf++ = c;
  }
  *buf = 0;
  return c != EOF;
}

void GetStr( char *buf, int MaxLen )
{
  FGetStr(stdin, buf, MaxLen);
}

void FPutStr( FILE *F, char *buf )
{
  while (*buf != 0)
    fputc(*buf++, F);
}

void PutStr( char *buf )
{
  FPutStr(stdout, buf);
}

int StrLen( char *buf )
{
  int len = 0;
  while (*buf++ != 0)
    len++;
  return len;
}

int FindChar( char *buf, char c )
{
  int i = 0;
  while (buf[i] != 0)
    if (buf[i++] == c)
      return i;
  return 0;
}

void FindAll( char *buf, char c )
{
  int i = 0;
  while (buf[i] != 0)
    if (buf[i++] == c)
      printf("%i, ", i - 1);
  printf("\n");
}

int CountVowels( char *buf )
{
  int i, j = 0, n = 0;
  char vowels[] = "eyuioaEYUIOA";
  while (buf[j] != 0)
  {
    for (i = 0; i < sizeof(vowels) - 1; i++)
      if (buf[j] == vowels[i])
        n++;
    j++;
  }
  return n;
}

void StringSplit( char *buf, char c )
{
  int i = 0;
  printf("\'");
  while (buf[i] != 0)
  {
    if (buf[i] == c)
      if (buf[++i] != 0)
        printf("\', \'");
      else
        break;
    printf("%c", buf[i++]);
  }
  printf("\'\n");
}

void FindStr( char *buf, char *buf2 )
{
  int i = 0, j, k, res = 0;
  while (buf[i] != 0 && res == 0)
  {
    if (buf[i] == buf2[0])
    {
      k = i;
      j = 0;
      while (buf2[j] != 0 && buf[k] != 0 && buf2[j] == buf[k])
      {
        k++;
        j++;
      }
      if (buf2[j] == 0)
        res++;
    }
    i++;
  }
  if (res != 0)
    printf("Main string contents your string.\n");
  else
    printf("Main string does not content your string.\n");
}

void PrefixFunc( char *buf, int *p )
{
  int n = StrLen(buf);
  int k, i;
  p[0] = 0;
  k = p[0];
  for (i = 1; i < n; i++)
  {
    while (k > 0 && buf[k] != buf[i])
      k = p[k - 1];
    if (buf[k] == buf[i])
      k++;
    p[i] = k;
  }
}

void QuickStrStr( char *buf, char *buf2, int *p )
{
  char buf3[2 * MAXLEN + 1];
  int i, res = 0;
  int n1 = StrLen(buf);
  int n2 = StrLen(buf2);
  for (i = 0; i < n2; i++)
    buf3[i] = buf2[i];
  buf3[i] = 0;
  for (i = 0; i < n1; i++)
    buf3[n2 + 1 + i] = buf[i];
  PrefixFunc(buf3, p);
  for(i = n1; i >= n2; i--)
    if (p[n2 + i] == n2)
    {
      res++;
      break;
    }
  if (res != 0)
    printf("Main string contents your string.\n");
  else
    printf("Main string does not content your string.\n");
}