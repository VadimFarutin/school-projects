#include <iostream>
#include <glut.h>
#include "complex.h"

using namespace std;

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
  glutIdleFunc(Idle);
  glutMainLoop();

  return 0;
}