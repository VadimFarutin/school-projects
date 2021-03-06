#ifndef __TYPES_H__
#define __TYPES_H__

typedef enum
{
  WAIT_VALUE,
  WAIT_OPER,
  WAIT_BRACKET
} STATE;

typedef enum
{
  TOKEN_FUNCTION,
  TOKEN_BINARY,
  TOKEN_PREFIX,
  TOKEN_POSTFIX,
  TOKEN_OPENPAR,
  TOKEN_CLOSEPAR,
  TOKEN_VALUE,
  TOKEN_END,
  TOKEN_ERROR
} TOKEN_TYPE;

typedef enum
{
  ERROR_NOT_IMPLEMENTED,
  ERROR_SUCCESS,
  ERROR_UNEXPECTED_END,
  ERROR_OPERATOR_EXPECTED,
  ERROR_OPENPAR_EXPECTED,
  ERROR_CLOSEPAR_EXPECTED,
  ERROR_DIGIT_EXPECTED,
  ERROR_DIGIT_AFTER_DECIMAL_POINT_EXPECTED,
  ERROR_UNEXPECTED_TOKEN
} ERROR_TYPE;

typedef struct TOKEN
{
  TOKEN_TYPE type;
  char oper[8];
  int prior;
  double value;
  ERROR_TYPE error;
} TOKEN;

#endif
