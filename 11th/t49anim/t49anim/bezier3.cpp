#include "bezier3.h"

Bezier3::Bezier3(Vec pos, Color color)
: BaseObject(pos, color)
{
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
    {
      pnt[i][j].x = 2 * i;
      pnt[i][j].y = 2 * j;
      pnt[i][j].z = 1;
    }
}
int Bezier3::C(int i)
{
  return 1 + 2 * (1 <= i && i <= 2);
}
Vec Bezier3::Get(double u, double v)
{
  Vec res(0, 0, 0);
  for (int i = 0; i < 4; i++)
  {
    double t = 0;
    for (int j = 0; j < 4; j++)
    {
      t += C(i) * C(j) * pow(1 - u, 3 - j) * pow(1 - v, 3 - i) * pow(u, j) * pow(v, i) * pnt[i][j].x; 
    }
    res.x += t;
  }
  for (int i = 0; i < 4; i++)
  {
    double t = 0;
    for (int j = 0; j < 4; j++)
    {
      t += C(i) * C(j) * pow(1 - u, 3 - j) * pow(1 - v, 3 - i) * pow(u, j) * pow(v, i) * pnt[i][j].y; 
    }
    res.y += t;
  }
  for (int i = 0; i < 4; i++)
  {
    double t = 0;
    for (int j = 0; j < 4; j++)
    {
      t += C(i) * C(j) * pow(1 - u, 3 - j) * pow(1 - v, 3 - i) * pow(u, j) * pow(v, i) * pnt[i][j].z; 
    }
    res.z += t;
  }
  return res;
}
void Bezier3::Draw()
{
  glColor3d(255, 0, 0);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  for (int i = 0; i < N; i++)
  {
    glBegin(GL_QUAD_STRIP);
    for (int j = 0; j < N + 1; j++)
    {
      double u0 = (double)i / N;
      double u1 = (double)(i + 1)/ N;
      double v = (double)j / N;
      Vec p1 = Get(u0, v);
      Vec p2 = Get(u1, v);
      glVertex3d(p1.x, p1.y, p1.z);
      glVertex3d(p2.x, p2.y, p2.z);
    }
    glEnd();
  }     
}
void Bezier3::Update(double time, double dt)
{
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
}
