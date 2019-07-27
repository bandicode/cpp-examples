
#include <iostream>

// Try to swap the following preprocessor directives
#include "inclusion-order.h"
#define INCREASED_GRAVITY

int main() 
{
  std::cout << "Gravity: " << GRAVITY << "\n";
}
