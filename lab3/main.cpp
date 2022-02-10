#include <iostream>
#include <FORSYTHE.H>

#include "data.hpp"

int main()
{
  std::cout << "Hello, World!" << std::endl;
  double *yp = new double[2]{0, 0};
  //void RKF45(void(F)(REAL T,REAL*Y,REAL*YP),int NEQN,REAL *Y,REAL &T,REAL TOUT,REAL &RELERR,REAL &ABSERR,REAL *WORK,int &IFLAG)
  void (*ff)(double, double *, double *) = reinterpret_cast<void (*)(double, double *, double *)>(f);
  int neqn = 2;
  double *y = new double[2]{-3, 1};
  double *t = new double[2]{0, 1};
  double tt = 0.0;
  double tout = 1.0;
  double relerr = eps;
  double abserr = eps;
  double *work = new double[30]; // array [1..6*NEQN+3]
  int iflag = 1;

  RKF45(ff, neqn, y, tt, tout, relerr, abserr, work, iflag);

  std::cout << " Y = " << y[0] << "   " << y[1] << '\n';
  std::cout << " t = " << tt << '\n';
  std::cout << " iflag = " << iflag << '\n';

  return 0;
}
