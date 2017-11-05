#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <glut.h>
#define SCRH 1000
#define SCRW 1000
#define FRAMEH 600
#define FRAMEW 800

typedef unsigned char byte;
typedef struct
{
  short w, h;
  byte *pixel;
} Pic;
static Pic src, dst;
byte Frame[FRAMEH][FRAMEW][3];
byte *Get(Pic *p, int x, int y, int c)
{
  return p->pixel + 3 * (y * p->w + x) + c;
}
int Create( int w, int h, Pic *p )
{
  p->w = w;
  p->h = h;
  p->pixel = malloc(w * h * 3);
  return p->pixel != NULL;   
}
void Draw( Pic *p , int x0, int y0 )
{
  int x, y, c;
  for (y = 0; y < p->h; y++)
    for (x = 0; x < p->w; x++)
      for (c = 0; c < 3; c++)
        Frame[y + y0][x + x0][c] = *Get(p, x, y, c);
}                           
  
void Negative( Pic *src, Pic *dst )
{
  int x, y, c;
  if(Create(src->w, src->h, dst))
  for(y = 0; y < src->h; y++)
    for(x = 0; x < src->w; x++)
      for(c = 0; c < 3; c++)
        *Get(dst, x, y, c) = 255 - *Get(src, x, y, c);
} 
void Blur( Pic *src, Pic *dst, int size )
{
  int sum, cnt, i, j, y, x, c;
  cnt = size * size;
  if(Create(src->w, src->h, dst))
  for(y = 0; y < src->h; y++)
    for(x = 0; x < src->w; x++)
      for(c = 0; c < 3; c++)
      {
        sum = 0;
        for(i = 0; i < size; i++)
          for(j = 0; j < size; j++)
            sum += *Get(src, x - size / 2 +j, y - size / 2 + i, c);
        *Get(dst, x, y, c)  = sum / cnt;
      }
}
void FishEye(Pic *src, Pic *dst, int x0, int y0, int r)
{
  int d, y, x, c, u, v;
  if(Create(src->w, src->h, dst))
  for(y = 0; y < src->h; y++)
    for(x = 0; x < src->w; x++)
      for(c = 0; c < 3; c++)
      {
        d = (x - x0) * (x - x0) + (y - y0) * (y - y0);
        if (d > r * r)
          *Get(dst, x, y, c) = *Get(src, x, y, c);
        else
        {
          u = x0 + (x - x0) * d / r / r;
          v = y0 + (y - y0) * d / r / r;
          *Get(dst, x, y, c) = *Get(src, u, v, c);
        }
      }
}
int LoadG24( Pic *p )
{
  short y;
  FILE *F;
  F = fopen("X:\\PICS\\M.G24", "rb");
  if (F == NULL)
    return;
  fread(&p->w, 2, 1, F);
  fread(&p->h, 2, 1, F);
  if (!Create(p->w, p->h, p))
    return 0;
  for (y = 0; y < p->h; y++)
    for (y = 0; y < p->h; y++)
      for (y = 0; y < p->h; y++)
        fread(p->pixel, 3 * p->h * p->w, 1, F);
  fclose(F);
  return 1;
}
void Display( void )
{
  glClear(GL_COLOR_BUFFER_BIT);
  
  Draw(&src, 0, 0);
  glDrawPixels(FRAMEW, FRAMEH, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame);
  
  Negative(&src, &dst);
  Draw(&dst, 150, 0);
  glDrawPixels(FRAMEW, FRAMEH, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame);
  
  Blur(&src, &dst, 5);
  Draw(&dst, 0, 150);
  glDrawPixels(FRAMEW, FRAMEH, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame);
  
  FishEye(&src, &dst, 60, 60, 40);
  Draw(&dst, 150, 150);
  glDrawPixels(FRAMEW, FRAMEH, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame);
  
  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
}


void Keyboard( unsigned char Key, int X, int Y )
{
  if (Key == 27)
    exit(0);
}

int main( int argc, char *argv[] )
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(400, 400);
  glutCreateWindow("9 - 1 test");
  glRasterPos2d(-1, 1);
  glPixelZoom(1, -1);
  

  LoadG24(&src);
  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);
   
  glutMainLoop();
  return 0;
}