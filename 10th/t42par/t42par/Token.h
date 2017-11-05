#include "Types.h"

TOKEN CreateErrorToken( ERROR_TYPE err, char *str );
TOKEN CreateSuccessToken( void );
TOKEN ReadOneToken( char **pstr, int canBeUnary );
void AddToken( TOKEN tok );
void RewindTokens();
TOKEN GetNextToken();
int IsAnyToken();
int IsErrorToken( TOKEN *ptok );
int IsEndToken( TOKEN *ptok );
int IsValueToken( TOKEN *ptok );
int IsOperatorToken( TOKEN *ptok );
int PrintError( TOKEN *ptok );
