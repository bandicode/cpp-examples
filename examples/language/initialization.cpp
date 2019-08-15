
#include <iostream>

struct X
{
  int x;

  X(int, int) : x(2) { }
  X(int) : x(1) { }
  X() : x(0) { }
};

struct Y
{
  Y(X) { }
};

struct Point
{
  int x;
  int y;
};

enum class Color
{
  Red, Green, Blue
};

int main()
{
  /* Variable declaration without an initializer */

  int n; // bad: value of 'n' is unpredictable (UB)
  X x; // ok: x is default constructed

  /* Value initialization */

  int n2{}; // good: n2 is zero-initialized
  // X x2(); // bad: declares a function !
  X x3{};

  /* Initialization with an expression */

  const int n3 = 7;
  const auto x4 = X();
  const auto x5 = X{};

  /* Direct () & List {} initialization */

  int n4(3.14); 
  int n5{ static_cast<int>(3.14) }; // list-initialization forbids narrowing conversion
  X x6(1, 2);
  X x7{ 1, 2 };
  X x8(1);
  X x9{ 1 };
  // Y y1(X()); // bad: most vexing parse !
  Y y2{ X() };

  /* Reference initialization */

  int& n_ref_init_expr = n4;
  int& n_ref_init_arg(n4);
  int& n_ref_init_brace{ n4 };

  /* Initialization of enums */

  const Color color_init_expr = Color::Blue;
  const Color color_init_arg(Color::Green);
  const Color color_init_brace{ Color::Red };

  /* Aggregate initialization */

  int int_array[5] = { 1, 2, 3, 4, 5 };
  Point pt{ 1, 2 };
}
