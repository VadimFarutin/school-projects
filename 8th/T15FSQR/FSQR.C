double AreaLeftBars( double n, double a, double b )
{
  int i;
  double s = 0, y;
  double dx = (b - a) / n;
  for(i = 0; i <= n - 1; i++)
  {
    y = (a + i * dx) * (a + i * dx);
    s += y * dx;
  }
  return s;
}
double AreaTrap( double n, double a, double b )
{
  int i;
  double s = 0, y, y2;
  double dx = (b - a) / n;
  for(i = 0; i <= n - 1; i++)
  {
    y = (a + i * dx) * (a + i * dx);
    y2 = (a + i * dx + dx) * (a + i * dx + dx);
    s += (y + y2) * dx / 2;
  }
  return s;
}
double AreaMiddle( double n, double a, double b)
{
  int i;
  double s = 0, y;
  double dx = (b - a) / n;
  for(i = 0; i <= n - 1; i++)
  {
    y = (a + i * dx) * (a + i * dx);
    s += (y + dx / 2) * dx;
  }
  return s;
}
double Simpson( double n, double a, double b )
{
  int i;
  double s, s1, s2, y;
  double dx = (b - a) / n / 2;
  s = 0;
  s1 = 0;
  s2 = 0;
  for(i = 0; i <= n - 1; i++)
  {
    y = (a + (2 * i + 1) * dx) * (a + (2 * i + 1) * dx);
    s1 += y;
  }
  s1 *= 4;
  for(i = 1; i <= n - 1; i++)
  {
    y = (a + 2 * i * dx) * (a + 2 * i * dx);
    s2 += y;
  }
  s2 *= 2;
  s = (a * a + b * b + s1 + s2) * dx / 3;
  return s;
}