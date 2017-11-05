#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <glut.h>
#include <math.h>
        

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
void Sphere(double r, int slices, int stacks)
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
  for (i = 0; i <= stacks; i++)
  {
    a = -pi / stacks * i;
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
void Paraboloid(double A, double H, int slices, int stacks)
{
  int i, j;
  double a, b, r;
  double pi = 3.1415926;
  
  for (i = 0; i <= stacks; i++)
  {
    a = pi / stacks * i;
    r = sqrt(H * i / stacks);
    glBegin(GL_QUAD_STRIP);
      for (j = 0; j <= slices; j++)
      {
        b = 2 * pi / slices * j;
        glVertex3d(r * sin(b) * cos(a), r * cos(b) * cos(a), r * r * sin(a));
        glVertex3d(r * sin(b) * cos(a + pi / stacks), r * cos(b) * cos(a + pi / stacks), r * r * sin(a + pi / stacks));
      }
    glEnd();
  }

  
}
void Display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();
    glRotated(full_time * 90, 1, 0, 0);
    glColor3d(1, 1, 0);
    DrawCylinder(5, 1, 6);
    glTranslated(0, 3, 0);     
    Sphere(1, 50, 50); 
    Paraboloid(1, 5, 100, 100);
  glPopMatrix();

  glFinish();
  glutSwapBuffers();
}

void main(void)
{
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowPosition(50, 50);
  glutInitWindowSize(1280, 960);
  glutCreateWindow("Cylinder");

  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutKeyboardFunc(Keyboard);
  glutIdleFunc(Idle);
  Init();

  glutMainLoop();
}
