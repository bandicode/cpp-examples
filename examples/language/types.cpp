
#include <iostream>
#include <type_traits>

struct X
{

};

enum Device
{
  Keyboard, Mouse
};

enum class Color
{
  Red, Green, Blue
};

int main()
{
  static_assert(std::is_fundamental<int>::value, "int is a fundamental type");
  static_assert(!std::is_fundamental<X>::value, "a class is not a fundamental type");
  static_assert(!std::is_fundamental<Device>::value, "an enum is not a fundamental type");

  static_assert(std::is_pointer<int*>::value, "int* is a pointer type");
  static_assert(std::is_pointer<X*>::value, "X* is a pointer type");

  static_assert(std::is_reference<int&>::value, "int& is a reference type");
  static_assert(std::is_reference<X&>::value, "X& is a reference type");

  static_assert(std::is_rvalue_reference<int&&>::value, "int&& is a rvalue-reference");
  static_assert(std::is_rvalue_reference<Color&&>::value, "Color&& is a rvalue-reference");

  static_assert(std::is_const<const int>::value, "const int is const");
  static_assert(std::is_const<const X>::value, "const X is const");
  static_assert(std::is_const<std::remove_pointer<const X*>::type>::value, "const X* is const");
}
