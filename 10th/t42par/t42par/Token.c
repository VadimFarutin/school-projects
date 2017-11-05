#include <string.h>
#include <stdio.h>
#include "Types.h"
#include "Token.h"

typedef char OperatorsArray[][8];
OperatorsArray binary_operators =
{
  "+", "-", "*", "/"
};
OperatorsArray prefix_operators =
{
  "+", "-"
};
OperatorsArray postfix_operators =
{
  "!"
};
OperatorsArray functions =
{
  "sin", "cos", "lg"
};

int IsSpaceChar( char c )
{
	return c == ' ' || c == '\t';
}

int IsDigitChar( char c )
{
	return (c >= '0') && (c <= '9');
}

void SkipSpaces(char **pstr)
{
  char *str = *pstr;
    while (*str && IsSpaceChar(*str))
      str++;
  *pstr = str;
}

int GetPriority( TOKEN_TYPE type, char *oper )
{
  if (type == TOKEN_OPENPAR || type == TOKEN_CLOSEPAR)
    return 0;
  if (type == TOKEN_POSTFIX)
    return 2;
  if (type == TOKEN_FUNCTION)
    return 4;
  if (type == TOKEN_PREFIX)
    return 6;
  if (type == TOKEN_BINARY && (*oper == '*' || *oper == '/'))
    return 8;
  return 10; 
}

TOKEN CreateErrorToken( ERROR_TYPE err, char *str )
{
  TOKEN tok;
  tok.type = TOKEN_ERROR;
  tok.error = err;
  tok.prior = 12;
  return tok;
}

TOKEN CreateSuccessToken( void )
{
  TOKEN tok;
  tok.type = TOKEN_ERROR;
  tok.error = ERROR_SUCCESS;
  return tok;
}

int IsErrorToken( TOKEN *ptok )
{
  return ptok->type == TOKEN_ERROR;
}

int IsEndToken( TOKEN *ptok )
{
	return ptok->type == TOKEN_END;
}

int IsValueToken( TOKEN *ptok )
{
	return ptok->type == TOKEN_VALUE;
}

int IsOperatorToken( TOKEN *ptok )
{
  return ptok->type == TOKEN_PREFIX || ptok->type == TOKEN_BINARY; 
}

TOKEN ReadOpenParToken( char **pstr )
{
  TOKEN tok;
  tok.type = TOKEN_OPENPAR;
  tok.prior = GetPriority(TOKEN_OPENPAR, tok.oper);
  (*pstr)++;
  return tok;
}

TOKEN ReadCloseParToken( char **pstr )
{
  TOKEN tok;
  tok.type = TOKEN_CLOSEPAR;
  tok.prior = GetPriority(TOKEN_CLOSEPAR, tok.oper);
  (*pstr)++;
  return tok;
}

TOKEN ReadEndToken( char **pstr )
{
  TOKEN tok;
  tok.type = TOKEN_END;
  return tok;
}

TOKEN ReadValueToken( char **pstr )
{
  TOKEN tok;
  double val, power;
  char *str = *pstr;

      val = 0;
      while (IsDigitChar(*str))
      {
        val = val * 10 + *str - '0';
        str ++;
      }
      if (*str == '.')
      {
        str ++;
        if (!IsDigitChar(*str))
		  return CreateErrorToken(ERROR_DIGIT_AFTER_DECIMAL_POINT_EXPECTED, str);
        power = 0.1;
        while (IsDigitChar(*str))
        {
          val = val + (*str - '0') * power;
          str ++;
          power /= 10;
        }
      }
      tok.type = TOKEN_VALUE;
      tok.value = val;
  *pstr = str;
  return tok;
}

TOKEN ReadOneTypeOperator( char **pstr, char *ops, int opCount, TOKEN_TYPE type )
{
	TOKEN tok;
	int i;
	for (i = 0; i < opCount; i ++, ops += 8)
	{
		if (!strncmp(*pstr, ops, strlen(ops)))
		{
			*pstr += strlen(ops);
			tok.type = type;
			strcpy(tok.oper, ops);
                        tok.prior = GetPriority(type, tok.oper);
			return tok;
		}
	}
	return CreateErrorToken(ERROR_OPERATOR_EXPECTED, *pstr);
}

TOKEN ReadOperator( char **pstr, int canBeUnary )
{
	TOKEN tok;

	if (canBeUnary && *pstr[0] != 's' && *pstr[0] != 'c' && *pstr[0] != 'l' )
	{
	  tok = ReadOneTypeOperator(pstr, (char *)prefix_operators,
             sizeof(prefix_operators) / 8, TOKEN_PREFIX);
	  if (!IsErrorToken(&tok))
		return tok;
	}
	tok = ReadOneTypeOperator(pstr, (char *)postfix_operators,
             sizeof(postfix_operators) / 8, TOKEN_POSTFIX);
	if (!IsErrorToken(&tok))
		return tok;
	tok = ReadOneTypeOperator(pstr, (char *)binary_operators,
             sizeof(binary_operators) / 8, TOKEN_BINARY);
	if (!IsErrorToken(&tok))
		return tok;
	tok = ReadOneTypeOperator(pstr, (char *)functions,
             sizeof(functions) / 8, TOKEN_FUNCTION);
	if (!IsErrorToken(&tok))
		return tok;
	return CreateErrorToken(ERROR_UNEXPECTED_TOKEN, *pstr);
}

TOKEN ReadOneToken( char **pstr, int canBeUnary )
{
    TOKEN tok;
    SkipSpaces(pstr);
    if (IsDigitChar(**pstr))
      tok = ReadValueToken(pstr);
    else if (**pstr == '(')
      tok = ReadOpenParToken(pstr);
    else if (**pstr == ')')
      tok = ReadCloseParToken(pstr);
    else if (**pstr == NULL)
      tok = ReadEndToken(pstr);
    else
      tok = ReadOperator(pstr, canBeUnary);
    return tok;
}

int PrintError( TOKEN *ptok )
{
  if (ptok->type != TOKEN_ERROR || ptok->error == ERROR_SUCCESS)
    return 0;
  if (ptok->error == ERROR_NOT_IMPLEMENTED)
    printf("ERROR_NOT_IMPLEMENTED \n");
  if (ptok->error == ERROR_UNEXPECTED_END)
    printf("ERROR_UNEXPECTED_END \n");
  if (ptok->error == ERROR_OPERATOR_EXPECTED)
    printf("ERROR_OPERATOR_EXPECTED \n");
  if (ptok->error == ERROR_OPENPAR_EXPECTED)
    printf("ERROR_OPENPAR_EXPECTED \n");
  if (ptok->error == ERROR_CLOSEPAR_EXPECTED)
    printf("ERROR_CLOSEPAR_EXPECTED \n");
  if (ptok->error == ERROR_DIGIT_EXPECTED)
    printf("ERROR_DIGIT_EXPECTED \n");
  if (ptok->error == ERROR_DIGIT_AFTER_DECIMAL_POINT_EXPECTED)
    printf("ERROR_DIGIT_AFTER_DECIMAL_POINT_EXPECTED \n");
  if (ptok->error == ERROR_UNEXPECTED_TOKEN)
    printf("ERROR_UNEXPECTED_TOKEN \n");
  return 1;
}
