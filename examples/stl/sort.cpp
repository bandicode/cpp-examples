#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <numeric> // iota
#include <random>
#include <vector>

int main()
{
  std::array<int, 10> ar = { 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };

  /* sort using the default operator< */

  std::sort(ar.begin(), ar.end());

  for (int e : ar)
  {
    std::cout << e << " ";
  }

  std::cout << '\n';

  /* sort using a standard library compare function object */

  std::sort(ar.begin(), ar.end(), std::greater<int>());

  for (int e : ar)
  {
    std::cout << e << " ";
  }

  std::cout << '\n';

  /* sort using a custom function object */

  struct 
  {
    bool operator()(int a, int b) const
    {
      return a % 2 < b %2 || (a % 2 == b % 2 && a < b);
    }
  } customLess;

  std::sort(ar.begin(), ar.end(), customLess);

  for (int e : ar)
  {
    std::cout << e << " ";
  }

  std::cout << '\n';

  /* sort using a lambda expression */

  auto vec = std::vector<int>(128);
  std::iota(vec.begin(), vec.end(), 0);
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(vec.begin(), vec.end(), g);

  int nb_comp = 0;

  std::sort(vec.begin(), vec.end(), [&nb_comp](int a, int b) {
    ++nb_comp;
    return a % 2 < b % 2 || (a % 2 == b % 2 && a < b);
    });

  std::cout << nb_comp << " comparisons" << '\n';

  for (int e : vec)
  {
    std::cout << e << " ";
  }

  std::cout << '\n';
}