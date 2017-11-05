#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Parser.h"
#include "Token.h"
#define MAXN 1000

void Run( void )
{
  TOKEN tok;
  char str[MAXN];
  scanf("%s", &str);
  tok = Tokenize(str);
  PrintError(&tok);
  tok = Parse();
  if (!PrintError(&tok))
    printf("%lf\n", tok.value);
}
int main( void ) 
{
  Run();
  return 0;
}

