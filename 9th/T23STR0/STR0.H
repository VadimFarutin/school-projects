#define MAXLEN 20

int FGetStr( FILE *F, char *buf, int MaxLen );
void GetStr( char *buf, int MaxLen );
void FPutStr( FILE *F, char *buf );
void PutStr( char *buf );
int StrLen( char *buf );
int FindChar( char *buf, char c );
void FindAll( char *buf, char c );
int CountVowels( char *buf );
void StringSplit( char *buf, char c );
void FindStr( char *buf, char *buf2 );
void PrefixFunc( char *buf, int *p );
void QuickStrStr( char *buf, char *buf2, int *p );

