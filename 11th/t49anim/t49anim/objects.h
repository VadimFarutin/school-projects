#pragma once
#include <glut.h>
#include "vec.h"
#include "color.h"

struct IObject
{
  virtual ~IObject() {}
  virtual void Draw() = 0;
  virtual Vec Pos() const = 0;
  virtual void Update(double time, double dt) = 0;
};
struct BaseObject : public IObject
{
protected:
  Vec pos;
  Color color;
public:
  BaseObject(Vec pos, Color color);
  void Draw() {};
  void Update(double time, double dt) {};
  Vec Pos() const;
}; 