#define SCRH 800
#define SCRW 1000

struct Complex
{
  double x, y;
  Complex();
  Complex(double x, double y);
  Complex operator +(Complex const &p) const;
  Complex operator *(Complex const &p) const;
  double len2() const;
};

void Idle();
void Keyboard(unsigned char Key, int X, int Y);
void Color(int x, int y, unsigned char iters);
void Check();
void Display();