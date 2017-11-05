typedef struct tagList List;
typedef double Type;
struct tagList
{
  Type key;
  List *next;
};

void PushFront(List **L, Type x);
void PushBack(List **L, Type x);
void Display(List *L);
int InsertAfter(List **L, Type x, Type afterwhat);
int InsertBefore(List **L, Type x, Type beforewhat);
int PopFront(List **L);
int PopBack(List **L);
void EraseFist(List **L, Type x);
