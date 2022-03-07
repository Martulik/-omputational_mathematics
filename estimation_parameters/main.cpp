#include <iostream>
#include "data.hpp"

void make_table(double k)
{
  k_global = k;
  x_mod_fill();
  for (double i : x_mod) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

int main()
{
  std::cout.precision(10);

  double k = FMIN(36, 46, f_k, 0.0001);
  std::cout << "k = " << k << '\n';
  make_table(k);

  double k_bad = k * 0.99;
  std::cout << "k - 1% = " << k_bad << '\n';
  make_table(k_bad);
  k_bad = k * 1.01;
  std::cout << "k + 1% = " << k_bad << '\n';
  make_table(k_bad);

  std::cout << "k = " << k << '\n';
  M = 0.99;
  std::cout << "M - 1% = " << M << '\n';
  make_table(k);
  M = 1.01;
  std::cout << "M + 1% = " << M << '\n';
  make_table(k);

  return 0;
}
