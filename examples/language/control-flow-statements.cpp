
#include <iostream>
#include <vector>

int f(int n)
{
  // if-statement (selection-statement)
  if (n >= 0) return n; // return-statement
  else return -n; 
}

int g(int n)
{
  // if-statement can be "chained"
  if (n > 0)
    return 1;
  else if (n == 0)
    return 0;
  else
    return -1;
}

int main() 
{
  // compound-statement
  {
    std::cout << f(-10) << "\n";
    std::cout << g(-10) << "\n";
  }

  // for-loop (iteration-statement, loop)
  for (int i(0); i < 10; ++i)
    std::cout << i << " ";

  std::cout << "\n";

  const std::vector<int> nums{ 4, 6, 8, 3, 5, 2 };
  size_t i = 0;

  // while-loop (iteration-statement)
  while (i < nums.size() && nums.at(i) % 2 == 0)
  {
    if (i == 6)
      continue; // continue-statement

    std::cout << nums.at(i) << " ";

    ++i;
  }

  std::cout << "\n";

  // do-while loop (iteration-statement)
  do
    std::cout << "Hello there!" << "\n";
  while (false);

  enum class Color {
    Red, Green, Blue,
  };

  Color c = Color::Red;
  // switch-statement (selection-statement)
  switch (c)
  {
  case Color::Red:
    std::cout << "Red" << "\n";
    break; // try commenting this break-statement
  case Color::Green:
    std::cout << "Green" << "\n";
    break;
  default:
    std::cout << "other color" << "\n";
    break;
  }

  for (;;) // "forever" loop
  {
    std::cout << i++ << " ";

    if (i > 10)
      break; // break-statement
  }

  std::cout << "\n";
}
