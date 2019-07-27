
#include <complex>
#include <iostream>

struct Weight
{
  double value;
};

std::ostream& operator<<(std::ostream& stream, const Weight& w)
{
  stream << w.value << "kg";
  return stream;
}

Weight operator""_kg(long double w)
{
  return Weight{ double(w) };
}

Weight operator""_g(unsigned long long int w)
{
  return Weight{ double(w) / 1000. };
}

int main() 
{
  std::complex<double> z1{ 1., 2. };
  std::cout << z1 << "\n";

  using namespace std::literals::complex_literals;

  auto z2 = 1. + 2i;
  std::cout << z2 << "\n";

  std::cout << 2.8_kg << "\n";
  std::cout << 250_g << "\n";
}
