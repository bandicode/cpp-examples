
#include <iostream>

template<int N>
void print()
{
  std::cout << N << "\n";
}

constexpr 
int factorial(int n)
{
  return n <= 1 ? 1 : n * factorial(n - 1);
}

// constexpr // constexpr-functions cannot invoke UB
int random()
{
  int n;
  return n;
}

int main() 
{
  // template arguments must be compile-time constants
  print<factorial(5)>();

  // constexpr variables must be evaluated at compile-time
  constexpr int n = factorial(6); 
  std::cout << n << std::endl;

  std::cout << factorial(7) << "\n";

  std::cout << random() << "\n";
}
