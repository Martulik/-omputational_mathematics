#include <iostream>
#include <FORSYTHE.H>
#include <iomanip>
#include "data.hpp"

int main()
{
  double k = FMIN(36, 46, f_k, 0.0001);
  std::cout << "k = " << std::fixed << std::setprecision(10) << k << '\n';
  std::cout << "f(k + 0.2) = " << std::fixed << std::setprecision(10) << f_k(k + 0.2) << '\n';
  std::cout << "f(k + 0.1) = " << std::fixed << std::setprecision(10) << f_k(k + 0.1) << '\n';
  std::cout << "f(k) = " << std::fixed << std::setprecision(10) << f_k(k) << '\n';
  std::cout << "f(k - 0.1) = " << std::fixed << std::setprecision(10) << f_k(k - 0.1) << '\n';
  std::cout << "f(k - 0.2) = " << std::fixed << std::setprecision(10) << f_k(k - 0.2) << '\n';

  return 0;
}
