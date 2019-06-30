
#include <algorithm> // min
#include <iomanip> // quoted
#include <iostream>
#include <string>
#include <utility> // pair, make_pair
#include <vector>

static_assert(std::string::npos > 0, "npos must be a positive integer"); // guaranteed by the standard

std::pair<std::string, std::string> split_at(const std::string& str, size_t offset)
{
  return std::make_pair(std::string(str.begin(), str.begin() + offset), std::string(str.begin() + offset, str.end()));
}

enum class SplitBehaviour
{
  KeepEmptyParts,
  SkipEmptyParts,
};

std::vector<std::string> split(const std::string& str, char sep = ' ', SplitBehaviour behaviour = SplitBehaviour::SkipEmptyParts)
{
  std::vector<std::string> result;

  for(size_t pos = 0, next = 0; next != std::string::npos; pos = next + 1)
  {
    next = str.find(sep, pos);
    auto s = std::string(str.begin() + pos, str.begin() + std::min(next, str.size()));

    if (!s.empty() || behaviour == SplitBehaviour::KeepEmptyParts)
      result.push_back(std::move(s));
  }

  return result;
}

int main() 
{
  {
    auto result = split_at("Hello World!", 5);
    std::cout << std::quoted(result.first) << "\n";
    std::cout << std::quoted(result.second) << "\n";
  }

  {
    auto result = split("Hello  World! ");
    
    for (const std::string& s : result)
      std::cout << std::quoted(s) << "\n";
  }

  {
    auto result = split("Hello  World! ", ' ', SplitBehaviour::KeepEmptyParts);

    for (const std::string& s : result)
      std::cout << std::quoted(s) << "\n";

    // reconstruct original string from split
    std::string ori = result.front();

    for (size_t i(1); i < result.size(); ++i)
    {
      ori += " " + result.at(i);
    }

    std::cout << std::quoted(ori) << "\n";
  }
}
