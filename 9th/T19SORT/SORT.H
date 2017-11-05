#define MAXN 10000
#define STATE_FILE "STATE.TXT"

typedef int Type;

void SelectionSort( Type *a, int n );
void BubbleSort( Type *a, int n );
void SetIncreaseOrder( Type *a, int n );
void SetDiscreaseOrder( Type *a, int n );
void InsertionSort( Type *a, int n );
void SetRandomOrder( Type *a, int n );
void BubbleSort2( Type *a, int n );
void MergeSort( Type *a, int n );
int Check( Type *a, int n );
void HeapSort( Type *a, int n );
void Save( Type *a, int n );
int Load( Type *a );
void Table( Type *a, int n  );
void Swap( Type *a, Type *b );