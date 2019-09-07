
#include <iostream>


void foo(int)
{
  std::cout << "foo(int)" << "\n";
}

void foo(int*)
{
  std::cout << "foo(int*)" << "\n";
}

void bar(bool)
{
  std::cout << "bar(bool)" << "\n";
}

void bar(const std::string&)
{
  std::cout << "bar(const std::string&)" << "\n";
}

//void bar(const char*)
//{
//  std::cout << "bar(const char*)" << "\n";
//}

void bar(int, float)
{
  std::cout << "bar(int, float)" << "\n";
}

namespace qux 
{

void bar(int, double)
{
  std::cout << "bar(int, double)" << "\n";
}

} // namespace qux

int main() 
{
  foo(7);
  foo(NULL);
  foo(nullptr);

  bar("Hello World");

  bar(1, 2.0);

  using qux::bar;
  bar(1, 2.0);
}
