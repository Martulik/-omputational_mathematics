#ifndef LAB1_DATA_HPP
#define LAB1_DATA_HPP

double eps = 0.000000001;

double f(const double x)
{
  return 6 * x + 3;
}

struct table {
  int n = 6;
  double x[6] = {1.0, 1.2, 1.5, 1.6, 1.8, 2.0};
  double y[6] = {5.0, 6.899, 11.180, 13.133, 18.119, 25.0};
};

#endif
