#define MAXS 20
#define MAX_RECORDS 100

typedef struct
{
  char name[MAXS];
  char surname[MAXS];
} Name;
typedef struct
{
  int form;
  int index;
} Class;
typedef struct
{
  Name name;
  Class class;
  int age;
  long phoneNumber;
} Pupil;
typedef struct
{
  Pupil pupil;
  int deleted;
} Record;

extern Record records[MAX_RECORDS];
void Init( void );
int GetRecordCount( void );
void InputPupil( Pupil *p );
void AddPupil( void );
void PrintPupil( Pupil *p );
void PrintAll( void );
void PrintArray( char *a, int n );
int  ReadArray( char *a );
int FindRecordByName( char *name, int n );
int FindRecordBySurname( char *surname, int n );
void Save( void );
void Load( void );
void DeleteRecord( int id );


