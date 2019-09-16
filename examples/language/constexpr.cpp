
#include <cstddef>
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

template<std::size_t N>
struct Factorial
{
  static const int value = N * Factorial<N - 1>::value;
};

template<>
struct Factorial<0>
{
  static const int value = 1;
};

// constexpr // constexpr-functions cannot use variables that are not initialized
int random_integer()
{
  int n;
  return n;
}

int main() 
{
  // template arguments must be compile-time constants
  print<Factorial<5>::value>();
  print<factorial(5)>();

  // constexpr variables must be evaluated at compile-time
  constexpr int n = factorial(6); 
  std::cout << n << std::endl;

  std::cout << factorial(7) << "\n";

  std::cout << random_integer() << "\n";
}
