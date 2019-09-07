
#include <complex>
#include <iostream>
#include <type_traits>

struct Weight
{
  double value; // weight in kg
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

Weight operator"" _pound(unsigned long long int w)
{
  return Weight{ double(w) * 0.4535923 };
}

int main() 
{
  {
    /* Built-in suffix */

    const auto n = 42;
    static_assert(std::is_same<decltype(n), const int>::value, "n is const int");

    const auto p = 42u;
    static_assert(std::is_same<decltype(p), const unsigned int>::value, "n is const unsigned int");

    const auto x = 3.14;
    static_assert(std::is_same<decltype(x), const double>::value, "x is const double");

    const auto y = 3.14f;
    static_assert(std::is_same<decltype(y), const float>::value, "x is const float");
  }

  {
    /* C++ suffix for complex literals */

    std::complex<double> z1{ 1., 2. };
    std::cout << z1 << "\n";

    using namespace std::literals::complex_literals;

    auto z2 = 1. + 2i;
    std::cout << z2 << "\n";
  }

  {
    /* User-defined literals */

    std::cout << 2.8_kg << "\n";
    std::cout << 250_g << "\n";
    std::cout << "299 pound is " <<  299_pound << "\n";
  }
}
