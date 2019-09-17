
#include <iostream>

// Try to swap the following preprocessor directives
#include "inclusion-order-1.h"
#include "inclusion-order-2.h"

int main() 
{
  std::cout << "Gravity: " << GRAVITY << "\n";
}
