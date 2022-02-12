#include <iostream>
#include <iomanip>

#include <FORSYTHE.H>

#include "data.hpp"

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
    std::cout << "tout = " << tout;
    std::cout << "\t| func[1] = " << func[0] << "\t| func[2] = " << func[1];
    std::cout << "\t| iflag = " << iflag << '\n';
    tout += h_print;
  }
}

void adams(double h)
{
  double y_025[2] = {-3.0, 1.0};
  double work[6 * 2 + 3] = {0.0};
  double tt = 0.0;
  int iflag = 1;
  RKF45(f_ptr, 2, y_025, tt, 0.025, eps, eps, work, iflag);

  double y_05[2] = {-3.0, 1.0};
  tt = 0.0;
  iflag = 1;
  RKF45(f_ptr, 2, y_05, tt, 0.05, eps, eps, work, iflag);

  double f_0[2] = {0.0, 0.0};
  double f_1[2] = {0.0, 0.0};
  double f_2[2] = {0.0, 0.0};
  f(0.0, y, f_0);
  f(0.025, y_025, f_1);
  f(0.05, y_05, f_2);

  double finite_diff[2] = {0.0, 0.0};
  finite_diff[0] = f_1[0] - f_0[0];
  finite_diff[1] = f_2[0] - f_1[0];

  double z[2] = {y_025[0], y_025[1]};
  double temp_1[2] = {f_1[0], f_1[1]};
  double temp_2[2] = {f_0[0], f_0[1]};
  for (double t = 0.025; t <= 1.0 + eps; t += 0.025) {

    z[0] = z[0] + h * (3 * dx1_dt(z[0], z[1], t) - dx1_dt(z[0], z[1], t - h)) / 2;
    z[1] = z[1] + h * (3 * dx2_dt(z[0], t) - dx2_dt(z[0], t - h)) / 2;

    f(t, z, temp_1);
    f(t - h, z, temp_2);

    std::cout << "t = " << std::setw(5) << t << "\t z = " << std::setw(15) << z[0] << '\n';
  }
}

int main()
{
  std::cout.precision(10);
  //rkf();
  adams(0.025);
  return 0;
}
