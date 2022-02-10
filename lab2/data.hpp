#ifndef LAB2_DATA_HPP
#define LAB2_DATA_HPP

const int p_size = 5;
double p[p_size] = {1.0, 0.1, 0.01, 0.0001, 0.000001};

const int size_of_matrix = 8;

std::vector< std::vector< double>> A(double pp)
{
  return {{pp - 29, 6,   -6, -4, -3, -8, -5, 5},
          {6,       -13, -3, 5,  4,  3,  1,  7},
          {5,       -5,  -1, 7,  2,  0,  7,  1},
          {5,       -5,  5,  6,  4,  -7, 4,  0},
          {4,       4,   7,  -4, 9,  -8, -8, -4},
          {-4,      5,   -4, 1,  0,  12, 0,  6},
          {-3,      -2,  -4, 2,  -8, -3, 16, 4},
          {7,       5,   0,  2,  0,  -6, 8,  -12}};
}

std::vector< double > B(double pp)
{
  return {4 * pp - 175, 133, 110, 112, 17, 32, 13, -18};
}

#endif
