
#include <iostream>

// Pass fundamental types by value...
void fundamental_by_value(int)
{
  std::cout << "fundamental_by_value(int)" << "\n";
}

// ...unless you want to use them as "out-parameter"
void fundamental_by_reference(int&)
{
  std::cout << "fundamental_by_reference(int&)" << "\n";
}

// Although the return channel should be preferred to return a value
int fundamental_return()
{
  std::cout << "fundamental_return()" << "\n";
  return 0;
}

struct X
{

};

// Pass X as a const-reference if you only need read-only access
// const-reference parameters can bind to temporaries
void object_by_const_ref(const X&)
{
  std::cout << "object_by_const_ref(const X&)" << "\n";
}


// Pass X as a reference if you want to modify it
// Non-const references cannot bind to temporaries
void object_by_ref(X&)
{
  std::cout << "object_by_ref(X&)" << "\n";
}

// Pass X as a rvalue-reference if you want to transfer resource ownership
// Temporaries bind preferently to rvalue-references
void object_by_rvalue_ref(X&&)
{
  std::cout << "object_by_rvalue_ref(X&&)" << "\n";
}

int main() 
{
  int n = 5;
  const int const_n = n;

  fundamental_by_value(n);
  fundamental_by_value(const_n);
  fundamental_by_value(5);

  fundamental_by_reference(n);
  // fundamental_by_reference(const_n); // error: const value cannot bind to non-const reference
  // fundamental_by_reference(5); // error: temporaries cannot bind to non-const reference

  fundamental_return();

  const X const_x;
  X x;

  object_by_const_ref(x);
  object_by_const_ref(const_x);
  object_by_const_ref(X());

  object_by_ref(x);
  // object_by_ref(const_x); // error: const object cannot bind to non-const reference 
  // object_by_ref(X()); // error: temporaries cannot bind to non-const reference // works on MSVC (sigh!)

  // object_by_rvalue_ref(x); // error: cannot transfer resource without explicit std::move
  object_by_rvalue_ref(std::move(x));
  // object_by_rvalue_ref(const_x); // error: cannot transfer resource of const-object
  object_by_rvalue_ref(X());
}
