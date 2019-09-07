
#include <chrono>
#include <iostream>
#include <numeric>
#include <future>
#include <vector>

int accumulate(const std::vector<int>& vec, size_t start_index, size_t end_index)
{
  return std::accumulate(std::begin(vec) + start_index, std::begin(vec) + end_index, 0);
}

int main() 
{
  /* Threaded version of "library/chrono" */

  constexpr size_t size = 100000;

  auto start = std::chrono::high_resolution_clock::now();

  const std::vector<int> v(size, 42);
  
  std::future<int> future_sum_1 = std::async(accumulate, std::cref(v), 0, size / 2);
  std::future<int> future_sum_2 = std::async(accumulate, std::cref(v), size / 2, size);

  // Wait for & get the results
  
  const int sum_1 = future_sum_1.get();
  const int sum_2 = future_sum_2.get();

  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> diff = end - start;
  
  std::cout << "Time to fill and iterate a vector of "
    << size << " ints : " << diff.count() << " s\n";

  std::cout << "Total : " << (sum_1 + sum_2) << "\n";
}
