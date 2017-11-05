#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    glRotated(full_time * 10, 1, 1, 1);
    glColor3d(1, 1, 0);
    glutSolidTorus(0.5, 1, 500, 100);

    glPushMatrix();
      glRotated(full_time * 100, 0, 0, 1);
      glTranslated(0, -3, 0);
      glColor3d(0, 0, 1);
      glutSolidSphere(0.2, 100, 500);

      glPushMatrix();
        glRotated(full_time * 200, 1, 0, 0);
        glTranslated(0, -0.25, 0);
        glColor3d(30, 30, 30);
        glutSolidSphere(0.05, 100, 500);
      glPopMatrix();
    glPopMatrix();
    glPushMatrix();
      glRotated(full_time * -50, 0, 0, 1);
      glTranslated(0, -5, 0);
      glColor3d(1, 0, 0);
      glutSolidSphere(0.2, 100, 500);

      glPushMatrix();
        glRotated(full_time * 200, 1, 0, 0);
        glTranslated(0, -0.5, 0);
        glColor3d(0, 30, 30);
        glutSolidSphere(0.1, 100, 500);
      glPopMatrix();
    glPopMatrix();
    glPushMatrix();
      glRotated(full_time * 10, 1, 1, 1);
      glTranslated(0, -7, 0);
      glColor3d(1, 3, 5);
      glutSolidSphere(0.2, 100, 500);

      glPushMatrix();
        glRotated(full_time * 200, 1, 0, 0);
        glTranslated(-0.5, -0.5, 0);
        glColor3d(5, 3, 1);
        glutSolidSphere(0.1, 100, 500);
      glPopMatrix();
    glPopMatrix();
    glPushMatrix();
      glRotated(full_time * 200, 0, 0, 1);
      glTranslated(0, -2, 0);
      glColor3d(135, 351, 543);
      glutSolidSphere(0.2, 100, 500);
    glPopMatrix();
    glPushMatrix();
      glRotated(full_time * -10, 0, 1, 0);
      glTranslated(0, 0, -5);
      glColor3d(1, 3, 5);
      glutSolidSphere(0.25, 100, 500);

      glPushMatrix();
        glRotated(full_time * 300, 1, 0, 0);
        glTranslated(0.5, 0.5, 0.5);
        glColor3d(0, 3, 1);
        glutSolidSphere(0.1, 100, 500);
      glPopMatrix();
      glPushMatrix();
        glRotated(full_time * -300, 0, 0, 1);
        glTranslated(0, 0.3, 0);
        glColor3d(5, 0, 1);
        glutSolidSphere(0.05, 100, 500);
      glPopMatrix();
    glPopMatrix();
    glPushMatrix();
      glRotated(full_time * -50, 0, 1, 0);
      glTranslated(0, 0, 4.5);
      glColor3d(0, 1, 0);
      glutSolidSphere(0.25, 100, 500);
      glPushMatrix();
        glRotated(full_time * -700, 1, 0, 0);
        glTranslated(0, 0.35, 0);
        glColor3d(0, 0, 1);
        glutSolidSphere(0.1, 100, 500);
      glPopMatrix();
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
  glutCreateWindow("my first 3D");

  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutKeyboardFunc(Keyboard);
  glutIdleFunc(Idle);
  Init();

  glutMainLoop();
}
