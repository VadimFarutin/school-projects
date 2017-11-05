/*Farutin V., 8 - 1, 26.04.2013
  This Programm.
*/

#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include "grx.h"

void main( void )
{
  int Bricks[BNUMY][BNUMX];
  int vx = 1, vy = 1, c, i, j;
  int x = STARTX, y = STARTY, z = STARTZ;
  int bw = BARW;
  int bx = (SCRW - bw) / 2, by = SCRH - 1, bz = BARZ;
  int *t;
  t = &bx;
  for(i = 0; i < BNUMY; i++)
    for(j = 0; j < BNUMX; j++)
      Bricks[i][j] = 3;
  Open();
  for(i = 0; i < bw; i++)
  {
    PutPixel(bx + i, by, bz);
  }
  DrawBricks();
  while(1)
  {
//    CollisionDetection(x, y, vx, vy);
    PutPixel(x, y, 0);
    x += vx;
    y += vy;
    PutPixel(x, y, z);
    if(x == SCRW - 1 || x == 0)
      vx = -vx;
    if(y == 0)
      vy = -vy;
    if(y == SCRH - 1)
    {
      PutPixel(x, y, 0);
      y = STARTY;
      x = STARTX;
      vx = -vx;
    }
    if(x <= bx + bw && x >= bx && y == by - 1)
      vy = -vy;


    if(Hit(x + vx, y))
      vx = -vx;
    if(Hit(x, y + vy))
      vy = -vy;
    if(Hit(x + vx, y + vy))
    {
      vx = -vx;
      vy = -vy;
    }


    Shift(t, by, bz, bw);
    if(kbhit())
    {
      c = getch();
      if(c == 27)
        break;
    }
    delay(DELAY);
  }
  Close();
}
