#include "objects.h"

struct Cube : public BaseObject
{
private:
  double size;
public:
  Cube(Vec pos, Color color, double size);
  void Draw();
  void Update(double time, double dt);
};