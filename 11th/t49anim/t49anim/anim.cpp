#include "anim.h"

Anim *Anim::instance = 0;
Scene Anim::scene;
double Anim::full_time;

void Anim::Init()
{
  glEnable(GL_DEPTH_TEST);
  /*
  scene += new Cube(Vec(0, 0, -0.5), Color(0, 200, 255), 0.5);
  scene += new Cube(Vec(0, 0, 0), Color(0, 200, 255), 1.5);
  scene += new Cube(Vec(0, 0, 1.5), Color(0, 200, 255), 1.5);
  scene += new Cube(Vec(0, 0, 3), Color(0, 200, 255), 1.5);
  scene += new Sphere(Vec(0.75, 0, 0), Color(0, 255, 0), 0.75);
  scene += new Sphere(Vec(0.75, 0, 1.5), Color(255, 255, 0), 0.75);
  scene += new Sphere(Vec(0.75, 0, 3), Color(255, 0, 0), 0.75);
  */
  //scene += new Helicopter(Vec(0, 0, 0), Color(255, 0, 0));
  scene += new Bezier3(Vec(0, 0, 0), Color(255, 0, 0));
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_COLOR_MATERIAL); 
}
void Anim::Reshape(int wp, int hp)
{
  double h = (double)hp / wp;

  glViewport(0, 0, wp, hp);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, (double)wp / hp, 1, 100);
  gluLookAt(10, 0, 5, 
            2, 2, 2, 
            0, 0, 1);
  
  glMatrixMode(GL_MODELVIEW);
}
void Anim::Idle()
{
  static long start_time = -1;
  long cur_time;
  double last_time = full_time; 
  if (start_time == -1)
    start_time = clock();
  cur_time = clock();
  full_time = (double)(cur_time - start_time) / CLOCKS_PER_SEC;
 
  scene.Update(full_time, full_time - last_time);
  glutPostRedisplay();
}
void Anim::Keyboard(unsigned char key, int x, int y)
{
  if (key == 27)
    exit(0);
}
void Anim::Display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  scene.Draw();
  
  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
}
Anim::Anim()
{
  //glutInit(0, 0);
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(SCRW, SCRH);
  glutCreateWindow("Animation");
  
  Init();
  glutReshapeFunc(Reshape);
  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);
  glutIdleFunc(Idle); 
}
Anim &Anim::GetInstance()
{
  if (instance == 0)
    instance = new Anim();
  return *instance;
}    
void Anim::MainLoop()
{
  glutMainLoop();
}