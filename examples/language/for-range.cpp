
#include <iostream>
#include <list>
#include <vector>

int main() 
{
  // try changing vector to list
  std::vector<int> digits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  // bad: only works for random access containers
  for (size_t i(0); i < digits.size(); ++i)
  {
    std::cout << digits.at(i) << " ";
  }

  std::cout << std::endl;

  // better: works for all containers
  // cons: it is only used to read the container's elements
  for (auto it = digits.begin(); it != digits.end(); ++it)
  {
    std::cout << *it << " ";
  }

  std::cout << std::endl;

  // best: range-for loop
  // pros: no useless iterator is visible
  for (const int d : digits)
  {
    std::cout << d << " ";
  }

  std::cout << std::endl;

  // The above range-for is equivalent to the following
  {
    for (auto begin = std::begin(digits); begin != std::end(digits); ++begin)
    {
      const int d = *begin;

      {
        std::cout << d << " ";
      }
    }
  }

  std::cout << std::endl;

  // good: iterators are used to remove elements from the container
  for (auto it = digits.begin(); it != digits.end();)
  {
    if (*it % 2 == 0)
    {
      it = digits.erase(it);
    }
    else
    {
      ++it;
    }
  }

  for (const int d : digits)
  {
    std::cout << d << " ";
  }

  std::cout << std::endl;
}
