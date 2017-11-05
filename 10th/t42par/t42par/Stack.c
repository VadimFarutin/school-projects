#include "Token.h"
#include "Stack.h"

TOKEN operatorsStack[100];
int operatorsSP = 0;
TOKEN valuesStack[100];
int valuesSP = 0;

void PushOper( TOKEN tok )
{
  operatorsStack[operatorsSP++] = tok;
}

TOKEN PopOper()
{
  TOKEN tok;
  if (!IsAnyOper())
    return CreateErrorToken(ERROR_NOT_IMPLEMENTED, 0);
  tok = operatorsStack[--operatorsSP];
  return tok;
}

TOKEN PeekOper()
{
  TOKEN tok;
  if (!IsAnyOper())
    return CreateErrorToken(ERROR_NOT_IMPLEMENTED, 0);
  tok = operatorsStack[operatorsSP - 1];
  return tok;
}

int IsAnyOper()
{
  return operatorsSP > 0;
}

void PushVal( TOKEN tok )
{
  valuesStack[valuesSP++] = tok;
}

TOKEN PopVal()
{
  TOKEN tok;
  if (!IsAnyVal())
    return CreateErrorToken(ERROR_NOT_IMPLEMENTED, 0);
  tok = valuesStack[--valuesSP];
  return tok;
}

TOKEN PeekVal()
{
  TOKEN tok;
  if (!IsAnyVal())
    return CreateErrorToken(ERROR_NOT_IMPLEMENTED, 0);
  tok = valuesStack[valuesSP - 1];
  return tok;
}

int IsAnyVal()
{
  return valuesSP > 0;
}
