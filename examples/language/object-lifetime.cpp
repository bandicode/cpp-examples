
#include <iostream>

struct X
{
  int n;

  X(int val)
    : n(val)
  {
    std::cout << n << "\n";
  }

  ~X()
  {
    std::cout << "~" << n << "\n";
  }
};

int main() 
{
  X x{ 1 };

  std::cout << "Entering {}-scope" << "\n";

  {
    X y{ 2 };
  }

  std::cout << "Just leaved {}-scope" << "\n";

  X z = X{ 3 }.n + X{ 4 }.n;

  std::cout << "About to leave main()" << "\n";
}
