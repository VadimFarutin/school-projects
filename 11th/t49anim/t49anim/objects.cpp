#include "objects.h"

BaseObject::BaseObject(Vec pos, Color color)
: pos(pos), color(color) {}
Vec BaseObject::Pos() const
{
  return pos;
}