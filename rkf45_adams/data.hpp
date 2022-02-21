#ifndef LAB3_DATA_HPP
#define LAB3_DATA_HPP

#include <cmath>
#include <FORSYTHE.H>

double h_print = 0.05;
double eps = 0.0001;
double h_int = 0.025;
double y[2] = {-3, 1};

double dx1_dt(const double x1, const double x2, const double t)
{
  return -73 * x1 - 210 * x2 + log(1 + t * t);
}

double dx2_dt(const double x1, const double t)
{
  return x1 + exp(-t) + t * t + 1;
}

// y[0], y[1] = значения x1(0) и x2(0)
// yp[0], yp[1] = dx1/dt и dx2/dt
void f(const double t, const double *y, double *yp)
{
  yp[0] = dx1_dt(y[0], y[1], t);
  yp[1] = dx2_dt(y[0], t);
}

void (*f_ptr)(double, double *, double *) = reinterpret_cast<void (*)(double, double *, double *)>(f);

#endif
