#ifndef DATA_HPP
#define DATA_HPP

#include <cmath>
#include "FORSYTHE.H"

double eps = 0.00001;
const double g = 9.81;
const int M = 1;
double k_global = 0.0;
const int N = 7;
const double x_exp[7] = {0.0, 0.303, -0.465, 0.592, -0.409, 0.164, 0.180};
double x_mod[7] = {0.0};

// MAIN - FMIN - F(p) - RKF45 - f (t, x, p)

double integral(double x)
{
  return std::cos(x * x);
}

double l()
{
  double result, flag;
  int nofun = 0;
  double errest = 0.0;
  QUANC8(integral, 0.0, 1.0, eps, eps, result, errest, nofun, flag);
  double l = result / 0.90452424;
  return l;
}

void f(const double k, const double *y, double *yp)
{
//  yp[0] = y[1];
//  yp[1] = -((k_global / M) * y[0] + g * (1 - std::cos(y[2])) - (1 + y[0]) * y[3] * y[3]);
//  yp[2] = y[3];
//  yp[3] = -(g / (l() + y[0]) * std::sin(y[2]) + 2 / (1 + y[0]) + y[1] * y[3]);
 // std::cout << yp[0] << ' ' << yp[1] << ' ' << yp[2] << ' ' << yp[3] << '\n';
 yp[0] = (y[2] * y[2] - k_global / M) * y[1] + l() * y[2] * y[2] - g * (1 - std::cos(y[3]));
yp[1] = y[0];
yp[2] = (-2 * y[0] / (l() + y[1])) * y[2] - (g * std::sin(y[3]) / (l() + y[1]));
yp[3] = y[2];
}



void (*f_ptr)(double, double *, double *) = reinterpret_cast<void (*)(double, double *, double *)>(f);

//void x_mod_fill()
//{
//  double tout = 0.4;
//  int neqn = 4;
//  double work[6 * 4 + 3] = {0.0};
//  x_mod[0] = 0.0;
//  int iflag = 1;
//  for (int i = 1; i < N; ++i) {
//    double t = 0.0;
//    double x_mod_p[4] = {0.0, 0.0, 0.0, 4.0};
//    RKF45(f_ptr, neqn, x_mod_p, t, tout, eps, eps, work, iflag);
//    x_mod[i] = x_mod_p[0];
//    tout += 0.4;
//  }
//}

double f_k(double k)
{
  k_global = k;
  //std::cout << "F(K): k = " << k << '\n';
  double sum = 0.0;
  double tout = 0.0;
  int neqn = 4;
  double work[6 * 4 + 3] = {0.0};
  int iflag = 1; // k = 36
  double t = 0.0;
  for (int i = 1; i < N; ++i) {
    tout += 0.4;
    iflag = 1;
    t = 0.0;
    //double x_mod_p[4] = {0.0, 0.0, 0.0, 4.0};
    double x_mod_p[4] = {0.0, 0.0, 4.0, 0.0};

    while (abs(t - tout) > eps) {
      RKF45(f_ptr, neqn, x_mod_p, t, tout, eps, eps, work, iflag);
      //std::cout << "tout = " << tout << "\t t = " << t << "\t iflag = " << iflag << '\n';
    }
    sum += std::pow(x_exp[i] - x_mod_p[1], 2);
  }
  //std::cout << "tout = " << tout << "\t t = " << t << "\t iflag = " << iflag << '\n';
  return sum;
}

#endif
