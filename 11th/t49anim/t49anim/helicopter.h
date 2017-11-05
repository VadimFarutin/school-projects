#include "objects.h"
#include <math.h>

struct Helicopter : public BaseObject
{
private:
  double blades_angle;
  double body_angle;
  double height;
  void Body();
  void Blades();
public:
  Helicopter(Vec pos, Color color);
  void Draw();
  void Update(double time, double dt);
};