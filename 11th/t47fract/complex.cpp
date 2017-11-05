#include <cstdio>
#include <stdlib.h>
#include <glut.h>
#include <time.h>
#include <math.h>
#include "complex.h"

using namespace std;

Complex::Complex()
  : x(0), y(0) 
{}
Complex::Complex(double x, double y)
  : x(x), y(y)
{}
Complex Complex::operator +(Complex const &p) const
{
  return Complex(this->x + p.x, this->y + p.y);
}
Complex Complex::operator *(Complex const &p) const
{
  return Complex(this->x * p.x - this->y * p.y, this->x * p.y + this->y * p.x);
}

double Complex::len2() const
{
  return this->x * this->x + this->y * this->y; 
}


unsigned char Frame[SCRH][SCRW][3];
double full_time;
void Idle()
{
  static long start_time = -1;
  long cur_time;
  if (start_time == -1)
    start_time = clock();
  cur_time = clock();
  full_time = (double)(cur_time - start_time) / CLOCKS_PER_SEC;
  
  glutPostRedisplay();
}
void Keyboard(unsigned char Key, int X, int Y)
{
  if (Key == 27)
    exit(0);
}

void Color(int x, int y, unsigned char iters)
{
    double col = iters / 255.0;
    if (col >= 0 && col < 0.3)
    {
      Frame[y][x][0] = 0;
      Frame[y][x][1] = 0;
      Frame[y][x][2] = col * 10 / 3 * 255;
    }
    if (col >= 0.3 && col < 0.7)
    {
      Frame[y][x][0] = 0;
      Frame[y][x][1] = (col - 0.3) * 2.5 * 255;
      Frame[y][x][2] = 255 - (col - 0.3) * 2.5 * 255;
    }
    if (col >= 0.7 && col < 0.9)
    {
      Frame[y][x][0] = (col - 0.7) * 5 * 255;
      Frame[y][x][1] = 255 - (col - 0.7) * 5 * 255;
      Frame[y][x][2] = 0;
    }
    if (col >= 0.9 && col < 1)
    {
      Frame[y][x][0] = 255;
      Frame[y][x][1] = (col - 0.9) * 10 * 255;
      Frame[y][x][2] = (col - 0.9) * 10 * 255;
    }
}
void Check()
{
  int x, y;
  unsigned char iters;
  double speed = sin(full_time / 10.0);
  double speed3 = speed * speed * speed;
  Complex C(0.4 - (0.4 - 0.28) * speed3, 0.2 - (0.2 - 0.0113) * speed3);
  for (y = 0; y < SCRH; y++)
    for (x = 0; x < SCRW; x++)
    {
//     Complex Z((2.0 + speed / 2) / SCRW * (x - SCRW / 2), (2.0 + speed / 2) / SCRW * (SCRH / 2 - y));
      Complex Z((2.0 + speed / 2) / SCRW * (SCRH / 2 - y), (2.0 + speed / 2) / SCRW * (x - SCRW / 2));
      
      for (iters = 0; iters < 255; iters++)
      {
        Z = Z * Z + C;
        if (Z.len2() > (2.0 + speed / 2) * (2.0 + speed / 2))
          break;
      }
      Color(x, y, iters);  
    }
}

void Display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  
  Check();
  glDrawPixels(SCRW, SCRH, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame);
  
  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
}
