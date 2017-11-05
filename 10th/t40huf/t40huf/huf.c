#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huf.h"

CODE Codes[256];
int freq[256];
NODE forest[256];
int forestSize = 0;
char acc = 0;
char accBitCount = 0;

int cmp( const void *a, const void *b )
{
  return *(int *)a - *(int *)b;
}
void Sort( void )
{
  qsort(freq, 256, sizeof(int), cmp); 
}
void CalculateFrequency( FILE *F )
{
  char c;
  int i;
  for (i = 0; i < 256; i++)
    freq[i] = 0;
  while (!feof(F))
  {
    c = fgetc(F);
    freq[c]++;
  }
  Sort();
}
 
void InsertToForest( NODE *newTREE )
{
  int pos = forestSize - 1;
  while (pos >= 0 && forest[pos].Frequency < newTREE->Frequency)
  {
    forest[pos + 1] = forest[pos--];
    forest[pos + 1] = *newTREE;
    forestSize++;
  }
}  
void BuildTree( void )
{
  NODE temp;
  int i;
  temp.left = NULL;
  temp.right = NULL;
  for (i = 0; i < 255; i++)
  {
    temp.Symbol = i;
    temp.Frequency = freq[i];
    InsertToForest(&temp);
  }
}  

void MergeTrees( void )
{
  NODE temp;
  NODE *newLeft, *newRight;
  newLeft = malloc(sizeof(NODE));
  *newLeft = forest[forestSize - 2];
  newRight = malloc(sizeof(NODE));
  *newRight = forest[forestSize - 1];
  while (forestSize > 1)
  {
    temp.Frequency = forest[forestSize - 1].Frequency + forest[forestSize - 2].Frequency;
    temp.Symbol = 26;
    temp.left = newLeft;
    temp.right = newRight;
    forestSize -= 2;
    InsertToForest(&temp);
  }
}

void WriteFrequencies( FILE *F )
{
  fwrite(freq, sizeof(freq), 256, F); 
}
void CalculateCodes( NODE *Root, char *RootCode, int RootCodeLen )
{
  if (Root->Symbol != 26)
  {
    Codes[Root->Symbol].Len = RootCodeLen;
    strcpy(Codes[Root->Symbol].Bits, RootCode);
  }
  if (Root->left != NULL)
  {
    RootCode[RootCodeLen] = '0';
    RootCode[RootCodeLen + 1] = 0;
    CalculateCodes(Root->left, RootCode, RootCodeLen + 2);
    RootCode[RootCodeLen] = 0;
  }
  if (Root->right != NULL)
  {
    RootCode[RootCodeLen] = '1';
    RootCode[RootCodeLen + 1] = 0;
    CalculateCodes(Root->right, RootCode, RootCodeLen + 2);
    RootCode[RootCodeLen] = 0;
  }
}

void WriteBit( char Bit, FILE *F )
{
  acc = (acc << 1) + Bit;
  if (accBitCount == 7)
  {
    fwrite(&acc, 1, accBitCount, F);
    accBitCount = 0;
    acc = 0;
  }
  else
    accBitCount++;
}
void EncodeSymbol( char Symbol, FILE *F )
{
  int i;
  for (i = 0; i < Codes[Symbol].Len; i++)
    WriteBit(Codes[Symbol].Bits[i], F);
}

void EncodeText( FILE *textFile, FILE *archFile )
{
  char Symbol;
  while (!feof(textFile))
  {
    Symbol = fgetc(textFile);
    EncodeSymbol(Symbol, archFile);
  }
  if (accBitCount > 0)
    fwrite(&acc, sizeof(acc), accBitCount, archFile);
}

void Encode( FILE *textFile, FILE *archFile )
{
  CalculateFrequency(textFile);
  BuildTree();
  MergeTrees();
  WriteFrequencies(archFile); 
  CalculateCodes(forest, "0", 0);
  rewind(textFile);
  EncodeText(textFile, archFile);
}


void ReadFrequency( FILE *F )
{
  int i;
  for (i = 0; i < 256; i++)
    freq[i] = getc(F);
}

void DecodeText( FILE *textFile, FILE *archFile, NODE *Root )
{
  char Bit;
  NODE *t = Root;
  while (!feof(archFile))
  {
    while (Root->left != NULL && Root->right != NULL)
    {
      Bit = getc(archFile);
      if (Bit)
        Root = Root->right;
      else
        Root = Root->left;
    }
    fprintf(textFile, "%c", Root->Symbol);
    Root = t;
  }
}
void Decode( FILE *textFile, FILE *archFile )
{
  ReadFrequency(archFile);
  BuildTree();
  MergeTrees();
  DecodeText(textFile, archFile, forest);
}