#include "objects.h"

struct Sphere : public BaseObject
{
private:
  double radius;
public:
  Sphere(Vec pos, Color color, double radius);
  void Draw();
  void Update(double time, double dt);
};