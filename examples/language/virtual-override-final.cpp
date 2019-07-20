
#include <iostream>

struct A
{
  // classes with virtual functions should declare a virtual destructor
  virtual ~A() = default;

  int foo() const { return 0; }
  virtual int bar() const { return 0; }
};

struct AB /* final */ : A // try declaring AB as final
{
  int foo() const // override // try adding override to Ab::foo()
  { 
    return 1;
  }

  int bar() const override // final // try declaring A::bar() final
  { 
    return 1; 
  }
};

struct ABC : AB
{
  int bar() const override { return 2; }
};

void print_foo(const A& a)
{
  std::cout << a.foo() << "\n";
}

void print_bar(const A& a)
{
  std::cout << a.bar() << "\n";
}

int main() 
{
  A a;
  AB ab;
  ABC abc;

  print_foo(a);
  print_foo(ab);
  print_foo(abc);

  print_bar(a);
  print_bar(ab);
  print_bar(abc);
}
