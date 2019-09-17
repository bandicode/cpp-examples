
#include <cassert>
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
  int y = 0;
  Y(X) { }
};

struct Point
{
  int x;
  int y;
};

enum Device
{
  Keyboard, Mouse
};

enum class Color // enum-class values do not leak in parent scope
{
  Red, Green, Blue
};

int main()
{
  /* Variable declaration without an initializer */

  int integer_default_init; // bad: value is unpredictable (UB)
  int* pointer_to_integer_default_init; // bad: value is unpredictable (UB)
  X object_default_init; // ok: object is default constructed
  assert(object_default_init.x == 0);

  /* Value initialization */

  int integer_value_init{}; // good: integer is zero-initialized
  assert(integer_value_init == 0);
  int* pointer_to_integer_value_init{}; // good: pointer is initialized with nullptr
  assert(pointer_to_integer_value_init == nullptr);
  // X object_value_init(); // bad: declares a function !
  X object_value_init{};
  assert(object_value_init.x == 0);

  /* Initialization with an expression */

  const int integer_copy_init = 7;
  const auto object_copy_init_arg = X();
  const auto object_copy_init_brace = X{};
  const int* pointer_to_integer_copy_init = &integer_copy_init;

  /* Direct () & List {} initialization */

  int integer_direct_init(3.14); 
  int integer_brace_init{ static_cast<int>(3.14) }; // list-initialization forbids narrowing conversion
  int* pointer_to_integer_arg_init(&integer_value_init);
  int* pointer_to_integer_brace_init{ &integer_value_init };
  X object_direct_init(1, 2);
  X object_brace_init{ 1, 2 };
  X object_direct_init_b(1);
  X object_brace_init_b{ 1 };
  // Y object_direct_init_c(X()); // bad: most vexing parse !
  Y object_brace_init_c{ X() };

  /* Reference initialization */

  int& integer_ref_init_expr = integer_default_init;
  int& integer_ref_init_arg(integer_direct_init);
  int& integer_ref_init_brace{ integer_direct_init };

  /* Initialization of enums */

  const Device enum_init_expr = Keyboard;
  const Device enum_init_arg(Mouse);
  const Device enum_init_brace{ Keyboard };

  const Color enumclass_init_expr = Color::Blue;
  const Color enumclass_init_arg(Color::Green);
  const Color enumclass_init_brace{ Color::Red };

  /* Aggregate initialization */

  int int_array[5] = { 1, 2, 3, 4, 5 };
  Point pt{ 1, 2 };
}
