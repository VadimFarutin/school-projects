#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <glut.h>
#include <time.h>
#define SCRH 1000
#define SCRW 1000
#define FRAMEH 600
#define FRAMEW 800

typedef unsigned char byte;
byte Frame[FRAMEH][FRAMEW][3], Frame2[FRAMEH][FRAMEW][3];

void Draw( void )
{
  glClear(GL_COLOR_BUFFER_BIT);

  glDrawPixels(FRAMEW, FRAMEH, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame2);

  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
}
void NextPop( void )
{
  int x, y, i, j, c;
  for (y = 0; y < FRAMEH; y++)
    for (x = 0; x < FRAMEW; x++)
    {
      c = 0;
      for (j = y - 2; j < y + 3; i++)
        for (i = y - 2; i < y + 3; i++)
          if (Frame[y][x][1] != 0)
            c++;
      if (c < 2 || c > 3)
        Frame2[y][x][1] = 0;
      if (c == 3)
        Frame2[y][x][1] = 255;
    }
}
void Keyboard( unsigned char Key, int X, int Y )
{
  if (Key == 27)
    exit(0);
}

void Idle( void )
{
  static long startTime = -1, lastTime;
  long curTime;
  double dt;
  if (startTime == -1)
    startTime = lastTime = clock();
  curTime = clock();
  dt = (double)(curTime - lastTime) / CLOCKS_PER_SEC;
  if(dt >= 0.1)
  {
    lastTime = curTime;
    NextPop();
    
  }

}

int main( int argc, char *argv[] )
{
  int x, y, c, r;
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(400, 400);
  glutCreateWindow("9 - 1 test");
  glPixelZoom(1, -1);
  
  for (y = 0; y < FRAMEH; y++)
    for (x = 0; y < FRAMEW; x++)
      for (c = 0; c < 3; c++)
      {
        Frame[y][x][c] = Frame2[y][x][c] = 0;
        if (c == 0) 
        {
          r = rand() % 2;
          Frame[y][x][c] = Frame[y][x][c] = 255 * r;
        }
      }
  glutIdleFunc(Idle);
  glutDisplayFunc(Draw);
  glutKeyboardFunc(Keyboard);
  
  glutMainLoop();
  return 0;
}