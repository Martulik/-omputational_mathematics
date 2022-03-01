#include <iostream>
#include <FORSYTHE.H>
#include "data.hpp"

int main()
{
  double k = FMIN(36, 46, f_k, eps);
  std::cout << "k = " << k << '\n';

  return 0;
}
