//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "huf.h"

int main( int argc, char *argv[] )
{
  FILE *textFile, *archFile;
  if (argc != 4 || (argv[1][0] != 'E' && argv[1][0] != 'D'))
  {
    printf("Usage:\n\t t40huf.exe E|D <textfile> <archive>\n");
    return 1;
  }
  textFile = fopen(argv[2], argv[1][0] == 'E' ? "rt" : "wt");
  archFile = fopen(argv[3], argv[1][0] == 'E' ? "wb" : "rb");
  if (textFile == NULL || archFile == NULL)
  {
    printf("Error: Can not open file.");
    return 2;
  }
  if (argv[1][0] == 'E')
    Encode(textFile, archFile);
  if (argv[1][0] == 'D')
    Decode(textFile, archFile);
  fclose(textFile);
  fclose(archFile);
  return 0;

}
