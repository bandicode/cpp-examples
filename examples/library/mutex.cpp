
#include <chrono>
#include <iostream>
#include <mutex>
#include <numeric>
#include <thread>
#include <vector>

std::mutex g_mutex;

void slow_increment(int& s, int i)
{
  using namespace std::chrono_literals;
  std::this_thread::sleep_for(1ms);

  s += i;
}

void accumulate(const std::vector<int>& vec, size_t start_index, size_t end_index, int& sum)
{
  const int s = std::accumulate(std::begin(vec) + start_index, std::begin(vec) + end_index, 0);

  // bad: writing to sum is unsafe as the variable is shared between multiple threads.
  //slow_increment(sum, s);

  {
    g_mutex.lock();
    sum += s;
    g_mutex.unlock(); // try commenting this line
  }

  //{
  //  // better: lock_guard (RAII!!)
  //  std::lock_guard<std::mutex> guard{g_mutex};
  //  sum += s;
  //}
}

int main() 
{
  /* Threaded version of "library/chrono" */

  constexpr size_t size = 1000000;
  const size_t tcount = std::thread::hardware_concurrency();

  std::cout << "Ideal number of threads (indication) : " << tcount << "\n";

  auto start = std::chrono::high_resolution_clock::now();

  const std::vector<int> v(size, 42);
 
  int sum = 0;

  // Thread arguments are copied, we use std::cref & std::ref to create copyable 
  // std::reference_wrapper.

  std::vector<std::thread> threads;
  const size_t thread_workload = v.size() / tcount;

  for (size_t i(0); i < tcount; ++i)
  {
    const size_t begin = thread_workload * i;
    const size_t end = thread_workload * (i + 1);
    threads.emplace_back(accumulate, std::cref(v), begin, end, std::ref(sum));
  }

  // Wait for the threads to finish
  for (std::thread& t : threads)
  {
    t.join();
  }

  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> diff = end - start;
  
  std::cout << "Time to fill and iterate a vector of "
    << size << " ints : " << diff.count() << " s\n";

  std::cout << "Total : " << sum << "\n";
}
