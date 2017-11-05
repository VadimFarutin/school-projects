#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <glut.h>

        

double full_time;

void Init(void)
{
  glEnable(GL_DEPTH_TEST);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_COLOR_MATERIAL);
}

void Reshape(int wp, int hp)
{
  double h = (double)hp / wp;

  glViewport(0, 0, wp, hp);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, (double)wp / hp, 1, 100);
  gluLookAt(10, 0, 3, 
             0, 0, 0, 
             0, 0, 1);
  
  glMatrixMode(GL_MODELVIEW);
}
void Keyboard(unsigned char key, int x, int y)
{
  if (key == 27)
    exit(0);
}

void Idle(void)
{
  static long start_time = -1;
  long cur_time;
  if (start_time == -1)
    start_time = clock();
  cur_time = clock();
  full_time = (double)(cur_time - start_time) / CLOCKS_PER_SEC;

  glutPostRedisplay();
}
void Display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();
    glTranslated(0, 1, 0);
    glColor3d(1, 0, 0);
    glScaled(1, 1, 0.1);
    glutSolidCube(5);
    glScaled(1, 1, 10);
    
    glPushMatrix();
      glRotated(sin(full_time) * 70, 1, 0, 0);
      glPushMatrix();
        glTranslated(0, 0, -2.5);
        glScaled(1, 1, 10);
        glutSolidCube(0.45);
        glScaled(1, 1, 0.1);
      glPopMatrix();
      glTranslated(0, 0, -4.5);
      glColor3d(0, 0, 1);
      glutSolidSphere(0.5, 500, 500);
    glPopMatrix(); 
  glPopMatrix();    

  glFinish();
  glutSwapBuffers();
}

void main(void)
{
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowPosition(50, 50);
  glutInitWindowSize(1280, 960);
  glutCreateWindow("3 variant");

  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutKeyboardFunc(Keyboard);
  glutIdleFunc(Idle);
  Init();

  glutMainLoop();
}
