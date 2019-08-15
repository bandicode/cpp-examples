
#include <initializer_list>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Point
{
  int x;
  int y;

  Point() = default;
  Point(const Point&) = default;

  Point(int x_,int y_) : x(x_), y(y_) { }
};

struct Printer
{
  Printer(std::initializer_list<int>&& ilist)
  {
    std::cout << "{ ";

    for (int n : ilist)
      std::cout << n << " ";

    std::cout << "}\n";
  }
  
  Printer(int n)
  {
    std::cout << "(" << n << ")\n";
  }
};

Point foo(const Point& pt)
{
  std::cout << "(" << pt.x << "," << pt.y << ")\n";
  return { pt.y, pt.x };
}

int main()
{
  const Point pt = foo({ 2, 1 });
  std::cout << "(" << pt.x << "," << pt.y << ")\n";

  // careful: initializer_list constructors are preferred when using list-initialization
  auto p1 = Printer(5);
  Printer p2{ 5 };
  Printer p3{ 1, 2, 3, 4 };

  const std::vector<int> digits{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  for (int n : digits)
    std::cout << n << " ";

  std::cout << "\n";

  const std::vector<int> vec1{ 5 };

  for (int n : vec1)
    std::cout << n << " ";

  std::cout << "\n";

  const auto vec2 = std::vector<int>(5);

  for (int n : vec2)
    std::cout << n << " ";

  std::cout << "\n";

  const std::map<std::string, int> dict{ {"zero", 0}, {"one", 1} };

  for (const std::pair<std::string, int> & pair : dict)
    std::cout << "(" << pair.first << "," << pair.second << ") ";

  std::cout << "\n";
}
