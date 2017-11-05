#include "expr.h"

int Prior( char c )
{
  if (c == '*' || c == '/')
    return 1;
  return 0;
}
int IsOperand( char c )
{
  return c >= '0' && c <= '9';
}
int IsOper( char c )
{
  if (c != '+' && c != '-' && c != '*' && c != '/')
    return 0;
  return 1;
}
int DoOper( char c, char a, char b )
{
  if (c == '+')
   return a + b;
  if (c == '-')
   return a - b;
  if (c == '*')
   return a * b;
  return a / b;
}
void Parse( char *inp )
{
  int i = 0, state = WAIT_DIGIT;
  int Values[MAX_TOKENS];
  char Opers[MAX_TOKENS];
  int ValuesTop = 0, OpersTop = 0;
  while (inp[i] != 0)
  {
    if (state == WAIT_DIGIT) 
    {
      if (!IsOperand(inp[i]))
      {
        printf("Error!\n");
        return;
      }
      Values[ValuesTop++] = inp[i] - 48;
    }
    else
    {
      if (!IsOper(inp[i]))
      {
        printf("Error!\n");
        return;
      }
      if (OpersTop != 0 && Prior(inp[i]) < Prior(Opers[OpersTop - 1]))
        while (OpersTop != 0)
        {
          if (Opers[OpersTop - 1] == '/')
            if (Values[ValuesTop - 1] == 0)
            {
              printf("Error!\n");
              return;
            }
          Values[ValuesTop - 2] = DoOper(Opers[OpersTop - 1], Values[ValuesTop - 2], Values[ValuesTop - 1]);
          ValuesTop--;
          OpersTop--;
        }
      Opers[OpersTop++] = inp[i];
    }
    i++;
    state = 1 - state;
  }
  if (inp[i] == 0 && state == WAIT_DIGIT)
  {
    printf("Error!\n");
    return;
  }
  while (OpersTop != 0)
  {
    if (Opers[OpersTop - 1] == '/')
      if (Values[ValuesTop - 1] == 0)
      {
        printf("Error!\n");
        return;
      }
    Values[ValuesTop - 2] = DoOper(Opers[OpersTop - 1], Values[ValuesTop - 2], Values[ValuesTop - 1]);
    ValuesTop--;
    OpersTop--;
  }
  printf("%i\n", Values[ValuesTop - 1]);
}
