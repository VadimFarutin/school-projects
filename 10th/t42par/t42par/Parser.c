#include <math.h>
#include "Types.h"
#include "Stack.h"
#include "Token.h"
#include "Parser.h"


double Factorial( double n )
{
  int i;
  double res = 1;
  for (i = 1; i <= n; i++)
    res *= i;
  return res;
}
int CanReadUnary( TOKEN *ptok )
{
  if (ptok->type == TOKEN_CLOSEPAR || ptok->type == TOKEN_FUNCTION ||
    ptok->type == TOKEN_POSTFIX || ptok->type == TOKEN_VALUE)
    return 0;
  return 1;
}

TOKEN Tokenize( char *str )
{
  TOKEN tok, prevToken;
  prevToken = CreateSuccessToken();
  while (1)
  {
    tok = ReadOneToken(&str, CanReadUnary(&prevToken));
    if (!IsErrorToken(&tok))
      AddToken(tok);
    else
      return tok;
    if (tok.type == TOKEN_END)
      break;
    prevToken = tok;
  }

  return CreateSuccessToken();
}

TOKEN DoOneOperator()
{
  TOKEN tokOper, tokValue1, tokValue2, newTok;
  tokOper = PopOper();
  if (tokOper.type == TOKEN_ERROR)
    return tokOper;
  tokValue1 = PopVal();
  if (tokValue1.type == TOKEN_ERROR)
    return tokValue1;
  newTok.type = TOKEN_VALUE;
  
  if (tokOper.type == TOKEN_BINARY)
  {
    tokValue2 = PopVal();
    if (tokValue2.type == TOKEN_ERROR)
      return tokValue2;
    if (tokOper.oper[0] == '+')
      newTok.value = tokValue1.value + tokValue2.value;
    if (tokOper.oper[0] == '-')
      newTok.value = tokValue1.value - tokValue2.value;
    if (tokOper.oper[0] == '*')
      newTok.value = tokValue1.value * tokValue2.value;
    if (tokOper.oper[0] == '/')
    {
      if (tokValue1.value == 0)
      {
        newTok = CreateErrorToken(ERROR_NOT_IMPLEMENTED, 0);
        return newTok;
      }
      newTok.value = tokValue1.value / tokValue2.value;
    }
  }
  if (tokOper.type == TOKEN_PREFIX)
  {
    if (tokOper.oper[0] == '-')
      tokValue1.value *= -1;
    newTok.value = tokValue1.value;
  }
  if (tokOper.type == TOKEN_POSTFIX)
    newTok.value = Factorial(tokValue1.value);
  if (tokOper.type == TOKEN_FUNCTION)
  {
    if (tokOper.oper[0] == 's')
      newTok.value = sin(tokValue1.value);
    if (tokOper.oper[0] == 'c')
      newTok.value = cos(tokValue1.value);
    if (tokOper.oper[0] == 'l')
      newTok.value = log10(tokValue1.value);
  }  
  if (tokOper.type != TOKEN_OPENPAR)
    PushVal(newTok);
  else
  {
    PushOper(tokOper);
    PushVal(tokValue1);
  }
  return CreateSuccessToken();
}

void DoAll( void )
{
  while (IsAnyOper())
    DoOneOperator();
}    
void PushClosePar( void )
{
  while (PeekOper().type != TOKEN_OPENPAR)
    DoOneOperator();
  PopOper();
}
void PushOperator( TOKEN tok )
{
  while (PeekOper().prior < tok.prior && PeekOper().type != TOKEN_OPENPAR)
    DoOneOperator();
  PushOper(tok);
}

TOKEN Parse()
{
  TOKEN tok;
  STATE state = WAIT_VALUE;

  RewindTokens();
  while (IsAnyToken())
  {
    tok = GetNextToken();
    switch (state)
    {
      case WAIT_VALUE:
        if (IsValueToken(&tok))
        {  
          PushVal(tok);
          state = WAIT_OPER;
        }
        else if (tok.type == TOKEN_PREFIX || tok.type == TOKEN_OPENPAR)
          PushOperator(tok);
        else if (tok.type == TOKEN_FUNCTION)
        {
          PushOperator(tok);
          state = WAIT_BRACKET;
        }
        else
          return CreateErrorToken(ERROR_NOT_IMPLEMENTED, 0);
      break;
    case WAIT_OPER:
      if (tok.type == TOKEN_POSTFIX)
        PushOperator(tok);
      else if (IsEndToken(&tok))
      {
        DoAll();
        break;
      }
      else if (IsOperatorToken(&tok))
      {
        PushOperator(tok);
        state = WAIT_VALUE;
      }
      else if (tok.type == TOKEN_CLOSEPAR)
        PushClosePar();
      else      
        return CreateErrorToken(ERROR_NOT_IMPLEMENTED, 0);
      break;
    case WAIT_BRACKET:
      if (tok.type == TOKEN_OPENPAR)
      {
        PushOperator(tok);
        state = WAIT_VALUE;
      }
      else      
        return CreateErrorToken(ERROR_NOT_IMPLEMENTED, 0);
      break;
    }
  }
  if (state != WAIT_OPER)
    return CreateErrorToken(ERROR_NOT_IMPLEMENTED, 0); 
  tok = PopVal();
  return tok;
}
