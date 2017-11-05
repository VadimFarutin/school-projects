#include "cube.h"

Cube::Cube(Vec pos, Color color, double size)
: BaseObject(pos, color), size(size) {}
void Cube::Draw()
{
  glPushMatrix();
    glColor3d(color.r, color.g, color.b);
    glTranslated(pos.x, pos.y, pos.z);
    glutSolidCube(size);
  glPopMatrix();
}
void Cube::Update(double time, double dt)
{
}
