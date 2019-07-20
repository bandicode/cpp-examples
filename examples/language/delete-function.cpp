
#include <iostream>

int gcd(int a, int b)
{
  const int r = a % b;
  return r == 0 ? b : gcd(b, r);
}

int phi(int n)
{
  int result = 0;

  for (int i(1); i < n; ++i)
  {
    if (gcd(i, n) == 1)
      ++result;
  }

  return result;
}

// pre-C++11 way of forcing a compile-time error:
// declare but do not define the overloads.
// bad: produces a linker error
// int phi(double);

// C++11: declare the function deleted
// int phi(double) = delete;

int main() 
{
  std::cout << phi(9) << "\n";

  // bad: most probably a programming error
  std::cout << phi(9.9) << "\n";
}
