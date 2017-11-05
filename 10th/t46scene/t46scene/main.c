#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <glut.h>
#include <math.h>
        

double full_time;
double speed = 0.1, last_position = 0;
int isMan = 1;
double anglez = 0, angley = 0;

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
  if (key == 'a')
    speed -= 0.025;
  if (key == 'd')
    speed += 0.025;
  if (key == 32)
    if (speed == 0)
      speed = 0.1;
    else
    {
      speed = 0;
      if (last_position > 260 && last_position < 280)
        if (isMan)
          isMan = 0;
        else
          isMan = 1;
    }
  if (key == 'j')
    anglez -= 5;
  if (key == 'l')
    anglez += 5;
  if (key == 'k')
    angley -= 5;
  if (key == 'i')
    angley += 5;
}

void Idle(void)
{
  static long start_time = -1;
  long cur_time;
  if (start_time == -1)
    start_time = clock();
  cur_time = clock();
  full_time = (double)(cur_time - start_time) / CLOCKS_PER_SEC;
  

  last_position += speed;
  if (last_position > 360)
    last_position -= 360;
  if (last_position < 0)
    last_position += 360;
  glutPostRedisplay();
}
void DrawCylinder(double H, double r, int slices)
{
  int i;
  double a;
  double pi = 3.1415926;
  glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= slices; i++)
    {
      a = 2 * pi / slices * i;
      glNormal3d(cos(a), sin(a), 0);
      glVertex3d(r * cos(a), r * sin(a), 0);
      glVertex3d(r * cos(a), r * sin(a), H);
    } 
  glEnd();
  glBegin(GL_TRIANGLE_FAN);
    glNormal3d(0, 0, -1);
    glVertex3d(0, 0, 0);
    for (i = 0; i <= slices; i++)
    {
      a = 2 * pi / slices * i;
      glNormal3d(0, 0, -1);
      glVertex3d(r * cos(a), r * sin(a), 0);
    } 
  glEnd();
  glBegin(GL_TRIANGLE_FAN);
    glNormal3d(0, 0, 1);
    glVertex3d(0, 0, H);
    for (i = 0; i <= slices; i++)
    {
      a = 2 * pi / slices * i;
      glNormal3d(0, 0, 1);
      glVertex3d(r * cos(a), r * sin(a), H);
    } 
  glEnd();

}
void Railway(void)
{
  double i, r1 = 3.695, r2 = 4.055, n = 1000;
  double l1 = sqrt(2 * r1 * r1 * (1 - cos(360 / n))), l2 = sqrt(2 * r2 * r2 * (1 - cos(360 / n)));
  glPushMatrix();
    glColor3d(1, 1, 1);
    glScaled(1, 1, 0.05);
    glutSolidCube(10);
    glScaled(1, 1, 20); 
    for (i = 0; i < n; i++)
    {
      glPushMatrix();
        glRotated(i * 360 / n, 0, 0, 1);
        glPushMatrix();
          glTranslated(0, r1, 0.25 + l1 * 0.05 / 2);
          glColor3d(1, 0, 0);
          glScaled(1, 0.05, 0.05);
          glutSolidCube(l1);
          glScaled(1, 20, 20);  
        glPopMatrix();
        glPushMatrix();
          glTranslated(0, r2, 0.25 + l1 * 0.05 / 2);
          glColor3d(1, 0, 0);
          glScaled(1, 0.05 * l1 / l2, 0.05 * l1 / l2);
          glutSolidCube(l2);
          glScaled(1, 20 * l2 / l1, 20 * l2 / l1);  
        glPopMatrix();
      glPopMatrix();
    }              
  glPopMatrix();
}
void Train(void)
{
  double r = 3.875;
  double r1 = 3.695, n = 1000;
  double l1 = sqrt(2 * r1 * r1 * (1 - cos(360 / n)));
  glPushMatrix();
    glTranslated(0, r, 0.25 + l1 * 0.05 + l1 * 0.5 / 2 + 4 * l1 * 0.05);
    glTranslated(0, 0, - l1 * 0.05);
    glColor3d(0, 0, 1);
    glScaled(1, 0.5, 0.5);
    glutSolidCube(l1);
    glScaled(1, 2, 2); 
    glTranslated(0, 0, l1 * 0.05);
    glPushMatrix();
      glTranslated(- l1 / 2 + 2 * l1 * 0.05, l1 * 0.5 / 2, - l1 * 0.5 / 2 - 4 * l1 * 0.05 / 2);
      glRotated(90, 1, 0, 0);
      glRotated(last_position * 4, 0, 0, 1);
      glColor3d(1, 0, 1);
      DrawCylinder(l1 * 0.5, 2 * l1 * 0.05, 6); 
      glutSolidTorus(l1 * 0.05, 3 * l1 * 0.05, 6, 6);
      glTranslated(0, 0, l1 * 0.5);
      glutSolidTorus(l1 * 0.05, 3 * l1 * 0.05, 6, 6);
    glPopMatrix();
    glPushMatrix();
      glTranslated(l1 / 2 - 2 * l1 * 0.05, l1 * 0.5 / 2, - l1 * 0.5 / 2 - 4 * l1 * 0.05 / 2);
      glRotated(90, 1, 0, 0);
      glRotated(last_position * 4, 0, 0, 1);
      glColor3d(1, 0, 1);
      DrawCylinder(l1 * 0.5, 2 * l1 * 0.05, 6); 
      glutSolidTorus(l1 * 0.05, 3 * l1 * 0.05, 6, 6);
      glTranslated(0, 0, l1 * 0.5);
      glutSolidTorus(l1 * 0.05, 3 * l1 * 0.05, 6, 6);
    glPopMatrix();
  glPopMatrix();
}

void Platform(void)
{
  glPushMatrix();
    glTranslated(3, 0, 0.25);
    glColor3d(0, 1, 0);
    glScaled(0.5, 1.5, 0.3);
    glutSolidCube(1);  
  glPopMatrix();
}
void HalfSphere(double r, int slices, int stacks)
{
  int i, j;
  double a, b;
  double pi = 3.1415926;
  

  for (i = 0; i <= stacks; i++)
  {
    a = pi / stacks * i;
    glBegin(GL_QUAD_STRIP);
      for (j = 0; j <= slices; j++)
      {
        b = 2 * pi / slices * j;
        glNormal3d(sin(b) * cos(a), cos(b) * cos(a), sin(a));
        glVertex3d(r * sin(b) * cos(a), r * cos(b) * cos(a), r * sin(a));
        glVertex3d(r * sin(b) * cos(a + pi / stacks), r * cos(b) * cos(a + pi / stacks), r * sin(a + pi / stacks));
      }
    glEnd();
  }
}
void Man(void)
{
  glPushMatrix();
    glTranslated(3, sin(full_time) * 0.5, 0.25 + 0.15);
    glColor3d(0, 1, 1);
    glutSolidCone(0.24, 1, 50, 50);
    glTranslated(0, 0, 1);
    glutSolidSphere(0.25, 50, 50);
    glPushMatrix();
      glTranslated(0.2, -0.1, 0);
      glColor3d(1, 1, 1);
      glutSolidSphere(0.05, 50, 50);
      glTranslated(0.01, 0, 0);
      glColor3d(0, 0, 0);
      glRotated(sin(full_time * 3) * 90, 0, 1, 0);
      HalfSphere(0.05, 50, 50);
    glPopMatrix();
    glPushMatrix();
      glTranslated(0.2, 0.1, 0);
      glColor3d(1, 1, 1);
      glutSolidSphere(0.05, 50, 50);  
      glTranslated(0.01, 0, 0);
      glColor3d(0, 0, 0);
      glRotated(sin(full_time * 3) * 90, 0, 1, 0);
      HalfSphere(0.05, 50, 50);
    glPopMatrix();
  glPopMatrix();
}
void Display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();
    glRotated(anglez, 0, 0, 1);
    glRotated(angley, 0, 1, 0);
    Railway();
    Platform();
    if (isMan)
      Man();
    glRotated(last_position, 0, 0, 1);
    Train();
  glPopMatrix();

  glFinish();
  glutSwapBuffers();
}

void main(void)
{
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowPosition(50, 50);
  glutInitWindowSize(1000, 1000);
  glutCreateWindow("Scene");

  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutKeyboardFunc(Keyboard);
  glutIdleFunc(Idle);
  Init();

  glutMainLoop();
}
