/*Farutin V., 9 - 1, 26.11.2013
  This Programm makes different things with string.
*/

#include <stdio.h>
#include <conio.h>
#include "str0.h"

void main( void )
{
  int t, k;
  char buf[MAXLEN], buf2[MAXLEN];
  int p[MAXLEN];
  char c;
  int ProgrammRuns = 1;
  FILE *InF, *OutF;
  //InF = fopen("input.txt", "rt");
  //OutF = fopen("output.txt", "wt");
  while (ProgrammRuns)
  {
    printf("\n"
           "0 - Exit\n"
           "1 - GetStr\n"
           "2 - FGetStr\n"
           "3 - FPutStr\n"
           "4 - StrLen\n"
           "5 - FindChar\n"
           "6 - FindAll\n"
           "7 - CountVowels\n"
           "8 - StringSplit\n"
           "9 - QuickStrStr\n"
           "p - PrefixFunc\n");
    PutStr(buf);
    printf("\n");
    t = getch();
    switch(t)
    {
      case '0':
        ProgrammRuns = 0;
        break;
      case '1':
        printf("Input string: \n");
        GetStr(buf, MAXLEN);
        break;
      case '2':
        printf("Input name of file: \n");
        GetStr(buf2, MAXLEN);
        InF = fopen(buf2, "rt");
        if (InF == NULL)
          printf("Give another file!\n");
        k = FGetStr(InF, buf, MAXLEN);
        break;
      case '3':
        printf("Input name of file: \n");
        GetStr(buf2, MAXLEN);
        OutF = fopen(buf2, "rt");
        if (OutF == NULL)
          printf("Give another file!\n");
        FPutStr(OutF, buf);
        break;
      case '4':
        printf("Len.: %i\n", StrLen(buf));
        break;
      case '5':
        printf("Position of what character do you want to know?\n");
        scanf("%c", &c);
        printf("The first position of '%c' is %i.\n", c, FindChar(buf, c));
        break;
      case '6':
        printf("Positions of what character do you want to know?\n");
        scanf("%c", &c);
        printf("Positions of %c are: ", c);
        FindAll(buf, c);
        break;
      case '7':
        printf("Number of vowels: %i\n", CountVowels(buf));
        break;
      case '8':
        printf("Input character: \n");
        scanf("%c", &c);
        StringSplit(buf, c);
        break;
     /* case '9':
        printf("Input string: \n");
        GetStr(buf2, MAXLEN);
        FindStr(buf, buf2);
        break; */
      case 'p':
        PrefixFunc(buf, p);
        printf("Max prefix lenght: %i\n", p[StrLen(buf) - 1]);
        break;
      case '9':
        printf("Input string: \n");
        GetStr(buf2, MAXLEN);
        QuickStrStr(buf, buf2, p);
        break;
    }
  }
  fclose(InF);
  fclose(OutF);
}
