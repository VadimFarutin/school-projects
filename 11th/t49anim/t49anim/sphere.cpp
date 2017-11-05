#include "sphere.h"

Sphere::Sphere(Vec pos, Color color, double radius)
: BaseObject(pos, color), radius(radius) {}
void Sphere::Draw()
{
  glPushMatrix();
    glColor3d(color.r, color.g, color.b);
    glTranslated(pos.x, pos.y, pos.z);
    glutSolidSphere(radius, 100, 100);
  glPopMatrix();
}
void Sphere::Update(double time, double dt)
{
}
