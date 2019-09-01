
#include <iostream>

void g(); // try commenting this line

void f()
{
  std::cout << "f()" << "\n" << "  ";

  g();
}

void g()
{
  std::cout << "g()" << "\n";
}

namespace foo 
{

void h()
{
  std::cout << "h()" << "\n";
}

} // namespace foo

int main() 
{
  const int a = 7;
  std::cout << a << "\n";

  {
    const int b = 8;
    std::cout << a  << " " << b << "\n";
  }

  // std::cout << b << "\n"; // b is no longer available

  f();
  g();

  foo::h(); // h() need to be explicitely named

  {
    using foo::h; // using-declaration

    h();
  }

  {
    using namespace foo; // using-directive

    h();
  }
}
