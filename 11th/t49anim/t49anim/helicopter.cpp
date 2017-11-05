#include "helicopter.h"

Helicopter::Helicopter(Vec pos, Color color)
: BaseObject(pos, color) 
{
  blades_angle = 0;
  body_angle = 0;
  height = 0;
}
void Helicopter::Body()
{
    glPushMatrix();
      glScaled(1, 2, 1);
      glutSolidSphere(1, 500, 500);
    glPopMatrix();

    glPushMatrix();
      glScaled(4, 0.5, 0.1);
      glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
      glColor3d(255, 0, 0);
      glTranslated(0, -2, 0);
      glScaled(0.2, 2, 0.2);
      glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
      glColor3d(255, 0, 0);
      glTranslated(0, -5, 0);
      glRotated(90, 0, 1, 0);
      glutSolidTorus(0.1, 1, 500, 500);
    glPopMatrix();
}

void Helicopter::Blades()
{
  glPushMatrix();
      glColor3d(0, 0, 255);
      glTranslated(3, 0.05, 0.2);
      glRotated(blades_angle, 0, 0, 1);
      glScaled(1, 0.1, 0.1);
      glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
      glColor3d(0, 0, 255);
      glTranslated(3, 0.05, 0.2);
      glRotated(blades_angle, 0, 0, 1);
      glScaled(0.1, 1, 0.1);
      glutSolidCube(2);
    glPopMatrix();
 
    glPushMatrix();
      glColor3d(0, 0, 255);
      glTranslated(-3, 0.05, 0.2);
      glRotated(-blades_angle, 0, 0, 1);
      glScaled(1, 0.1, 0.1);
      glutSolidCube(2);
    glPopMatrix();
    
    glPushMatrix();
      glColor3d(0, 0, 255);
      glTranslated(-3, 0.05, 0.2);
      glRotated(-blades_angle, 0, 0, 1);
      glScaled(0.1, 1, 0.1);
      glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
      glColor3d(0, 0, 255);
      glTranslated(0, -5, 0);
      glRotated(90, 0, 1, 0);
      glRotated(2 * blades_angle, 0, 0, 1);
      glScaled(0.1, 1, 0.1);
      glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
      glColor3d(0, 0, 255);
      glTranslated(0, -5, 0);
      glRotated(90, 0, 1, 0);
      glRotated(90 + 2 * blades_angle, 0, 0, 1);
      glScaled(0.1, 1, 0.1);
      glutSolidCube(2);
    glPopMatrix();
}
void Helicopter::Draw()
{
  glPushMatrix();
    glColor3d(color.r, color.g, color.b);
    glTranslated(pos.x + 6, pos.y, pos.z);
    
    glRotated(body_angle, 0, 1, 0);
    Body();
    Blades();
    
  glPopMatrix();
}
void Helicopter::Update(double time, double dt)
{
  glRotated(dt * 40, 0, 0, 1);
  glTranslated(0, 0, height);
  blades_angle += dt * 160;
  body_angle = 30 * sin(time);
  height = sin(time) * 0.025;
}
