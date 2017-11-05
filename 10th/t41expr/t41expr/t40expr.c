#include "expr.h"

void main( void )
{
  char inp[MAX_TOKENS];
  printf("Input: ");
  gets(inp);
  Parse(inp);
}
