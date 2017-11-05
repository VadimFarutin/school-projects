typedef struct
{
  char Bits[256];
  int Len;
} CODE;

typedef struct tagNode NODE;
struct tagNode
{
  unsigned char Symbol;
  long Frequency;
  NODE *left, *right;
  int Len;
};

void Encode( FILE *textFile, FILE *archFile );
void Decode( FILE *textFile, FILE *archFile );

