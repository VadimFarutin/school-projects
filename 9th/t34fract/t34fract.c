#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <glut.h>
#define SCRH 1200
#define SCRW 1600

typedef struct
{
  double x, y;
} Complex;

unsigned char Frame[SCRH][SCRW][3];
void Keyboard( unsigned char Key, int X, int Y )
{
  if (Key == 27)
    exit(0);
}
void Display( void )
{
  glClear(GL_COLOR_BUFFER_BIT);
  
  glDrawPixels(SCRW, SCRH, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame);

  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
}
void Check( void )
{
  int x, y, c;
  unsigned char iters;
  Complex Z, C, K;
  for (y = 0; y < SCRH; y++)
    for (x = 0; x < SCRW; x++)
    {
      C.x = 4.0 / SCRW * (x - SCRW / 2);
      C.y = 4.0 / SCRW * (SCRH / 2 - y);
      Z.x = C.x;
      Z.y = C.y;
      for (iters = 0; iters < 255; iters++)
      {
        K.x = Z.x;
        K.y = Z.y;
//        Z.x = K.x * K.x - K.y * K.y + C.x;
//        Z.y = K.x * K.y + K.x * K.y + C.y;
        Z.x = K.x * K.x - K.y * K.y + 0.28;
        Z.y = K.x * K.y + K.x * K.y + 0.0113;
        if (Z.x * Z.x + Z.y * Z.y > 4)
        {
          break;
        }
      }
/*      for (c = 0; c < 2; c++)
        Frame[y][x][c] = 0;
      Frame[y][x][c] = iters;
*/    
      Frame[y][x][0] = iters * iters;
      Frame[y][x][1] = iters * iters;
      Frame[y][x][2] = iters * iters;
    }
}

int main( int argc, char *argv[] )
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(SCRW, SCRH);
  glutCreateWindow("Fractal");
  glRasterPos2d(-1, 1);
  glPixelZoom(1, -1);
  
  Check();
  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);
   
  glutMainLoop();
  return 0;
}