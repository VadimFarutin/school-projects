#include <vector>
#include "objects.h"

class Scene
{
private:
  std::vector<IObject *> objects;
public:
  ~Scene();
  void operator += (IObject *obj);
  void Update(double time, double dt);
  void Draw();
};