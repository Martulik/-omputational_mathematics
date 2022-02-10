#include <iostream>
#include <FORSYTHE.H>

#include "data.hpp"

int main()
{
  std::cout.precision(10);

  double tout = 0.0;
  void (*ff)(double, double *, double *) = reinterpret_cast<void (*)(double, double *, double *)>(f);
  double relerr = eps;
  double abserr = eps;
  double y[2] = {-3, 1};
  double yy[2] = {0, 0};
  double work[30] = {0};
  int neqn = 2;
  while (tout < 1.0 + eps) {
    double t = 0.0;
    yy[0] = y[0];
    yy[1] = y[1];
    int iflag = 1;

    RKF45(ff, neqn, yy, t, tout, relerr, abserr, work, iflag);

    std::cout << " Y = " << yy[0] << "   " << yy[1];
    std::cout << " | t = " << t;
    std::cout << " | iflag = " << iflag;
    std::cout << " | tout = " << tout;
    std::cout << '\n';

    tout += h_print;

  }


  return 0;
}
