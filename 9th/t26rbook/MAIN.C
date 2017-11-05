/*Farutin V., 9 - 1, 14.01.2014
  This Programm puts pupils in book.
*/

#include <stdio.h>
#include <conio.h>
#include "book.h"

void main( void )
{
  int id, t, ProgrammRuns = 1, n;
  char name[MAXS], surname[MAXS];
  Record *rec;
  Pupil p;
  Init();
  while (ProgrammRuns)
  {
    printf("0 - Exit\n"
           "1 - Add Pupil\n"
           "2 - Find By Name\n"
           "3 - Find By Surname\n"
           "4 - Print Pupil\n"
           "5 - Print All\n"
           "6 - Save\n"
           "7 - Load\n"
           "8 - Delete\n"
           "s - Sort by name\n"
           "Records: [%i]\n", GetRecordCount()
           );
    t = getch();
    switch(t)
    {
      case '0':
        ProgrammRuns = 0;
        break;
      case '1':
        AddPupil();
        break;
      case '2':
        printf("Input name: \n");
        n = ReadArray(name);
        if (FindRecordByName(name, n) != -1)
          printf("ID : %i \n", FindRecordByName(name, n));
        else
          printf("This pupil is not record.\n");
      break;
      case '3':
        printf("Input surname: \n");
        n = ReadArray(surname);
        if (FindRecordBySurname(surname, n) != -1)
          printf("ID : %i \n", FindRecordBySurname(surname, n));
        else
          printf("This pupil is not record.\n");
      break;
      case '4':
        printf("Input ID: \n");
        scanf("%i", &id);
        PrintPupil(&records[id].pupil);
      break;
      case '5':
        PrintAll();
      break;
      case '6':
        Save();
      break;
      case '7':
        Load();
      break;
      case '8':
        printf("Input ID: \n");
        scanf("%i", &id);
        DeleteRecord(id);
      break;
      /*case 's':
        SortName();
      break;*/
    }
  }
}