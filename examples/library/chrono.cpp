
#include <chrono>
#include <iostream>
#include <list>
#include <numeric>
#include <vector>

int main() 
{
  constexpr size_t size = 100000;

  auto start = std::chrono::high_resolution_clock::now();

  const std::vector<int> v(size, 42); // try changing std::vector to std::list
  const int sum = std::accumulate(v.begin(), v.end(), 0);

  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> diff = end - start;
  
  std::cout << "Time to fill and iterate a vector of "
    << size << " ints : " << diff.count() << " s\n";

  std::cout << "Total : " << sum << "\n";
}
