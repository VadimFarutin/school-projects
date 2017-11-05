#include "Types.h"
#include "Token.h"

TOKEN tokens[100];
int tokenNumber = 0;
int lastTokenNumberThatWeAreAboutToReadNow;

void AddToken( TOKEN tok )
{
  tokens[tokenNumber ++] = tok;
}

void RewindTokens()
{
  lastTokenNumberThatWeAreAboutToReadNow = 0;
}

TOKEN GetNextToken()
{
  return tokens[lastTokenNumberThatWeAreAboutToReadNow ++];
}

int IsAnyToken()
{
  return lastTokenNumberThatWeAreAboutToReadNow < tokenNumber;
}

