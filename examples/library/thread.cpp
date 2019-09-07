
#include <chrono>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

void accumulate(const std::vector<int>& vec, size_t start_index, size_t end_index, int& sum)
{
  sum = std::accumulate(std::begin(vec) + start_index, std::begin(vec) + end_index, 0);
}

int main() 
{
  /* Threaded version of "library/chrono" */

  constexpr size_t size = 100000;

  std::cout << "Ideal number of threads (indication) : " << std::thread::hardware_concurrency() << "\n";

  auto start = std::chrono::high_resolution_clock::now();

  const std::vector<int> v(size, 42);
 
  int sum_1, sum_2;

  // Thread arguments are copied, we use std::cref & std::ref to create copyable 
  // std::reference_wrapper.

  std::thread t1{ accumulate, std::cref(v), 0, size / 2, std::ref(sum_1) };
  std::thread t2{ accumulate, std::cref(v), size / 2, size, std::ref(sum_2) };
  
  // Wait for t1 & t2 to finish
  t1.join(); 
  t2.join();

  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> diff = end - start;
  
  std::cout << "Time to fill and iterate a vector of "
    << size << " ints : " << diff.count() << " s\n";

  std::cout << "Total : " << (sum_1 + sum_2) << "\n";
}
