#include <iostream>
#include <FORSYTHE.H>
#include "data.hpp"

double bisections(const SPLINE *spline, double a, double b)
{
  double c = 0.0;
  while (abs(b - a) > eps) {
    double fa = spline->Eval(a) - f(a);
    c = (a + b) / 2;
    double fc = spline->Eval(c) - f(c);
    if (fa * fc > 0) {
      a = c;
    } else {
      b = c;
    }
  }
  return c;
}

int main()
{
  std::cout.precision(10);

  table *table = new struct table;
  SPLINE *spline = new SPLINE(table->n, table->x, table->y);
  double x = bisections(spline, table->x[0], table->x[table->n]);

  std::cout << "x = " << x << '\n';
  std::cout << "f(x) = 6x + 3 = " << f(x) << '\n';
  std::cout << "spline = " << spline->Eval(x) << '\n';

  delete spline;
  delete table;

  return 0;
}
