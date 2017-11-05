#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <glut.h>
#define SCRH 1000
#define SCRW 1000
#define MAXH 600
#define MAXW 800

typedef unsigned char byte;
typedef struct
{
  short w, h;
  byte pixel[MAXH][MAXW][3];
} Pic;
static Pic src, dst;

void FishEye(Pic *src, Pic *dst, int x0, int y0, int r)
{
  int d, y, x, c, u, v;
  for(y = 0; y < src->h; y++)
    for(x = 0; x < src->w; x++)
      for(c = 0; c < 3; c++)
      {
        d = (x - x0) * (x - x0) + (y - y0) * (y - y0);
        if (d > r * r)
          dst->pixel[y][x][c] = src->pixel[y][x][c];
        else
        {
          u = x0 + (x - x0) * d / r / r;
          v = y0 + (y - y0) * d / r / r;
          dst->pixel[y][x][c] = src->pixel[v][u][c];
        }
      }
}
void Negative( Pic *src, Pic *dst )
{
  int x, y, c;
  for(y = 0; y < src->h; y++)
    for(x = 0; x < src->w; x++)
      for(c = 0; c < 3; c++)
        dst->pixel[y][x][c] = 255 - src->pixel[y][x][c];
}
void Blur( Pic *src, Pic *dst, int size )
{
  int sum, cnt, i, j, y, x, c;
  cnt = size * size;
  for(y = 0; y < src->h; y++)
    for(x = 0; x < src->w; x++)
      for(c = 0; c < 3; c++)
      {
        sum = 0;
        for(i = 0; i < size; i++)
          for(j = 0; j < size; j++)
            sum += src->pixel[y - size / 2 + i][x - size / 2 + j][c];
        dst->pixel[y][x][c] = sum / cnt;
      }
}
/*void Load( void )
{
  short y, x, w, h, u;
  FILE *F;
  F = fopen("X:\\PICS\\M.G24", "rb");
  if (F == NULL)
    return;
  fread(&w, 2, 1, F);
  fread(&h, 2, 1, F);
  for(y = 0; y < h; y++)
    for(x = 0; x < w; x++)
      for(u = 0; u < 3; u++)
        fread(&Scr[y][x][u], 1, 1, F);
  fclose(F);
}*/
void LoadG24( Pic *pic )
{
  short y;
  FILE *F;
  F = fopen("X:\\PICS\\M.G24", "rb");
  if (F == NULL)
    return;
  fread(&pic->w, 2, 1, F);
  fread(&pic->h, 2, 1, F);
  for(y = 0; y < pic->h; y++)
    fread(&pic->pixel[y][0][0], 1, 3 * pic->w, F);
  fclose(F);
}
/*void Display( void )
{
  glClear(GL_COLOR_BUFFER_BIT);

  glDrawPixels(MAXW, MAXH, GL_BGR_EXT, GL_UNSIGNED_BYTE, dst.pixel);

  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
}*/
void Draw( void )
{
  glClear(GL_COLOR_BUFFER_BIT);
  
  Negative(&src, &dst);
  glRasterPos2d(-1, 1);
  glDrawPixels(MAXW, MAXH, GL_BGR_EXT, GL_UNSIGNED_BYTE, dst.pixel);

  Blur(&src, &dst, 5);
  glRasterPos2d(0, 1);
  glDrawPixels(MAXW, MAXH, GL_BGR_EXT, GL_UNSIGNED_BYTE, dst.pixel);

  FishEye(&src, &dst, 60, 60, 40);
  glRasterPos2d(-1, 0);
  glDrawPixels(MAXW, MAXH, GL_BGR_EXT, GL_UNSIGNED_BYTE, dst.pixel);
 
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
  glPixelZoom(1, -1);
  
  LoadG24(&src);
  glutDisplayFunc(Draw);
  glutKeyboardFunc(Keyboard);
   
  glutMainLoop();
  return 0;
}