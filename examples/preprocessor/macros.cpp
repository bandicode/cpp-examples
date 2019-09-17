
// See https://stackoverflow.com/questions/14041453/why-are-preprocessor-macros-evil-and-what-are-the-alternatives

// Checkout the result of "clang++ -E macros.cpp" 
// then "clang++ macros.cpp -o macros"

#include <iostream>

#define NINETEEN_EIGHTY_FOUR 1948

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() 
{
  /* This is a comment */

  std::cout \
    << NINETEEN_EIGHTY_FOUR << "\n";

  int a = 3, b = 2;

  std::cout << max(++a, b) << "\n";
}
