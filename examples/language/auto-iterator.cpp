
#include <iostream>
#include <list>
#include <vector>

int main() 
{
  // try changing vector to list
  std::vector<int> digits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  // bad: loop is only works with vector
  for (std::vector<int>::const_iterator it = digits.begin(); it != digits.end(); ++it)
  {
    std::cout << *it << " ";
  }

  std::cout << std::endl;

  // good: loop does rely on actual type of digits
  for (auto it = digits.begin(); it != digits.end(); ++it)
  {
    std::cout << *it << " ";
  }

  std::cout << std::endl;
}
