
#include <iostream>
#include <random>

static constexpr size_t N = 100;

int main() 
{
  std::random_device rd;
  std::mt19937 rng{ rd() }; // use non-deterministic source to seed Mersenne Twister

  /* uniform_int_distribution */

  std::uniform_int_distribution<int> int_distrib{ 0, 100 };

  for (size_t i(0); i < N; ++i)
  {
    std::cout << int_distrib(rng) << " ";
  }

  std::cout << std::endl;

  /* bernoulli_distribution */

  std::bernoulli_distribution bernoulli_distrib;

  for (size_t i(0); i < N; ++i)
  {
    std::cout << bernoulli_distrib(rng) << " ";
  }

  std::cout << std::endl;

  /* normal_distribution */

  std::normal_distribution<double> normal_distrib;

  for (size_t i(0); i < N; ++i)
  {
    std::cout << normal_distrib(rng) << " ";
  }

  std::cout << std::endl;
}
