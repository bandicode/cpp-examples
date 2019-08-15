#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main()
{
  // try replacing array by list or vector
  const auto container = std::array<int, 10>{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  {
    auto it = std::find(std::begin(container), std::end(container), 3);

    std::cout << "Found '3' at index " << std::distance(std::begin(container), it) << "\n";
  }

  {
    struct Predicate
    {
      bool operator()(int n)
      {
        return n % 2 == 0 && n % 3 == 1;
      }
    };

    auto it = std::find_if(std::begin(container), std::end(container), Predicate{});

    if (it != std::end(container))
    {
      std::cout << "Found '" << *it << "' at index " << std::distance(std::begin(container), it) << "\n";
    }
  }

  {
    auto it = std::find_if(std::begin(container), std::end(container), [](int n) {
      return n % 2 == 0 && n % 3 == 1;
      });

    if (it != std::end(container))
    {
      std::cout << "Found '" << *it << "' at index " << std::distance(std::begin(container), it) << "\n";
    }
  }
}
