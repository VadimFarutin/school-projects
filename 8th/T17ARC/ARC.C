#include "grx.h"

int Bricks[BNUMY][BNUMX];
void Open( void )
{
  asm{
  mov AX, 0x13
  int 0x10
  }
}
void Close( void )
{
  asm{
  mov AX, 0x3
  int 0x10
  }
}
void PutPixel( int x, int y, int z)
{
  *((unsigned char *) 0xA0000000UL + y * 320 + x) = z;
}
void Shift( int *bx, int by, int bz, int bw )
{
  if(*((unsigned char *) 0x417UL) & 1 == 1)
  {
    PutPixel(*bx, by, 0);
    PutPixel(*bx + bw, by, bz);
    (*bx)++;
  }
  if((*((unsigned char *) 0x417UL) >> 1) & 1 == 1)
  {
    PutPixel(*bx + bw, by, 0);
    PutPixel(*bx, by, bz);
    (*bx)--;
  }
  if(*bx == 0)
    (*bx)++;
  if(*bx == (319 - bw))
    (*bx)--;
}

void DrawBrick( int row, int column, int color )
{
  int i, j;
  for(i = 0; i < BRICKW / BNUMX; i++)
    for(j = 0; j < BRICKH / BNUMY; j++)
      PutPixel(BSTARTX + column * BRICKW / BNUMX + i, BSTARTY + row * BRICKH / BNUMY + j, color);
}
void DrawBricks( void )
{
  int i, j;
  for(i = 0; i < BNUMX; i++)
    for(j = 0; j < BNUMY; j++)
      DrawBrick(j, i, 7);
}

int Hit( int x, int y )
{
  if(x < BSTARTX || y < BSTARTY)
    return 0;
  x = (x - BSTARTX) / BRICKW;
  y = (y - BSTARTY) / BRICKH;
  if(x >= BNUMX || y >= BNUMY)
    return 0;
  if(Bricks[y][x] == 0)
    return 0;
  Bricks[y][x]--;
  DrawBrick(x, y, 4);
  return 1;
}
/*
void CollisionDetection( int x, int y, int vx, int vy )
{
  if(Hit(x + vx, y))
    vx = -vx;
  if(Hit(x, y + vy))
    vy = -vy;
  if(Hit(x + vx, y + vy))
  {
    vx = -vx;
    vy = -vy;
  }
}
*/