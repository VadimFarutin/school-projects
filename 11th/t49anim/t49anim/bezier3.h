#include "objects.h"
#include <math.h>

struct Bezier3 : public BaseObject
{
private:
  static const int N = 30;
  Vec pnt[4][4];
  int C(int i);
  Vec Get(double u, double v);
public:
  Bezier3(Vec pos, Color color);
  void Draw();
  void Update(double time, double dt);
};