#include <iostream>
#include <iomanip>
#include <FORSYTHE.H>
#include "data.hpp"

void out(double t, double *y)
{
  std::cout << "t = " << std::setw(10) << t;
  std::cout << std::setw(15) << "y[0] = " << std::setw(15) << y[0];
  std::cout << std::setw(15) << "y[1] = " << std::setw(15) << y[1] << '\n';
}

void rkf()
{
  double tout = 0.0;
  int neqn = 2;
  double work[6 * 2 + 3] = {0.0};
  while (tout <= 1.0 + eps) {
    int iflag = 1;
    double t = 0.0;
    double func[2] = {y[0], y[1]};
    RKF45(f_ptr, neqn, func, t, tout, eps, eps, work, iflag);
    out(t, func);
    tout += h_print;
  }
}

void adams(const double h)
{
  double y_h[2] = {-3.0, 1.0};
  double work[6 * 2 + 3] = {0.0};
  double t = 0.0;
  int iflag = 1;
  RKF45(f_ptr, 2, y_h, t, t + h, eps, eps, work, iflag);

  double f_0[2] = {0.0, 0.0};
  double f_1[2] = {0.0, 0.0};
  f(0.0, y, f_0);
  f(h, y_h, f_1);

  double z[2] = {y_h[0], y_h[1]};
  for (double t = 0.025; t <= 1.0 - h + eps; t += h) {
    z[0] = z[0] + h * (3 * dx1_dt(z[0], z[1], t) - dx1_dt(z[0], z[1], t - h)) / 2;
    z[1] = z[1] + h * (3 * dx2_dt(z[0], t) - dx2_dt(z[0], t - h)) / 2;

    out(t, z);
  }
}

int main()
{
  std::cout.precision(10);

  std::cout << "RKF45" << '\n';
  rkf();

  std::cout << "ADAMS" << '\n';
  adams(h_int);

  return 0;
}
