
#include <vector>
#include <iostream>
 
void print(const std::vector<int>& vec)
{
  for (int n : vec)
  {
    std::cout << n << " ";
  }

  std::cout << "\n";

}

int main()
{
  std::vector<int> digits{ 0, 1, 3, 4, 5, 6, 7, 8 };

  print(digits);

  // Get the vector's size()
  std::cout << "size: " << digits.size() << "\n";

  // Insert element at the end, avg. O(1) 
  digits.push_back(9);
  digits.push_back(9);

  print(digits);

  // Insert element in the middle, avg. O(n)
  // insert() returns an iterator to the first inserted element
  auto inserted_it = digits.insert(digits.begin() + 2, 2);
  std::cout << "inserted: " << *inserted_it << "\n";

  print(digits);

  // Remove element at the end, O(1)
  digits.pop_back();

  print(digits);

  // Access element randomly, O(1)
  std::cout << digits.at(5) << "\n";
  digits[0] = 10;

  print(digits);

  // Remove element, avg. O(n)
  for (auto it = digits.begin(); it != digits.end(); )
  {
    if (*it % 2 == 1)
    {
      // erase() returns new iterator to the element that was just after 
      // the removed element
      it = digits.erase(it);
    }
    else
    {
      ++it;
    }
  }

  print(digits);

  // Clear the vector
  digits.clear();
  // Check if the vector is empty
  std::cout << "empty ? " << digits.empty() << "\n";

}