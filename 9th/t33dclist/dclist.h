#include <memcheck.h>

typedef struct tagList List;
typedef double Type;
struct tagList
{
  Type key;
  List *next;
  List *prev;
};

void PushFront(List **L, Type x);
void PushBack(List **L, Type x);
void Display(List *L);
//int InsertAfter(List **L, Type x, Type afterwhat);
//int InsertBefore(List **L, Type x, Type beforewhat);
int PopFront(List **L);
int PopBack(List **L);
List *Init(void);
//int Find(List **head, Type x);
//int Replace(List **head, Type x, Type y);
void FreeList(List *L);
void DisplayReverse(List *L);
void EraseFirst(List **L, Type x);
