typedef struct tagTREE TREE;
struct tagTREE
{
  char *s;
  TREE *left;
  TREE *right;
};
void Create( TREE **T, FILE *F );
void FreeTree( TREE **T );
void Ask( TREE *T );