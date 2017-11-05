#include "anim.h"
  
using namespace std;

int main()
{ 
  Anim &anim = Anim::GetInstance();
  anim.MainLoop();
  return 0;
} 
