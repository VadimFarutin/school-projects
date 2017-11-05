#include <time.h>
#include <glut.h>
#include "scene.h"
#include "sphere.h"
#include "cube.h"
#include "helicopter.h"
#include "bezier3.h"

#define SCRW 1920
#define SCRH 1080

class Anim
{
private:
  Anim();
  static Anim *instance;
  static Scene scene;
  static double full_time;
  static void Init();
  static void Reshape(int wp, int hp);
  static void Idle();
  static void Keyboard(unsigned char key, int x, int y);
  static void Display();
public:
  static Anim &GetInstance();
  void MainLoop();
};