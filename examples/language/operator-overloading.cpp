
#include <iostream>
#include <vector>

struct MyVecIterator;

struct MyVec
{
    std::vector<int> vec;


    // MyVec() { } // pre-C++11
    MyVec() = default; // since C++11

    MyVec(std::initializer_list<int>&& ilist) // since C++11
      : vec{ ilist.begin(), ilist.end() }
    {

    }

    MyVecIterator begin() const;
    MyVecIterator end() const;

    const int& operator[](size_t index) const { return vec[index]; }
    int& operator[](size_t index) { return vec[index]; }
};

MyVec& operator,(MyVec& vec, int n) // bad: will lead to hard-to-read code
{
  vec.vec.push_back(n);
  return vec;
}

MyVec& operator<<(MyVec& vec, int n) // ok: container will act like a stream
{
  vec.vec.push_back(n);
  return vec;
}

struct MyVecIterator
{
  const MyVec& vec;
  size_t index;

  const int& operator*() const
  {
    return vec[index];
  }
  
  MyVecIterator& operator++()
  {
    ++index;
    return *this;
  }
};

MyVecIterator MyVec::begin() const
{
  return MyVecIterator{ *this, 0 };
}

MyVecIterator MyVec::end() const
{
  return MyVecIterator{ *this, vec.size() };
}

bool operator==(const MyVecIterator& lhs, const MyVecIterator& rhs)
{
  return (&lhs.vec == &rhs.vec) && lhs.index == rhs.index;
}

bool operator!=(const MyVecIterator& lhs, const MyVecIterator& rhs)
{
  return !(lhs == rhs);
}

void print(const MyVec& vec)
{
  for (int n : vec)
    std::cout << n << " ";

  std::cout << "\n";
}

int main() 
{
  MyVec a;
  a, 1, 2, 3, 4, 5; // bad: meaning is unclear
  print(a);

  MyVec b;
  b << 1 << 2 << 3 << 4 << 5;
  print(b);

  MyVec c{ 1, 2, 3, 4, 5 };
  print(c);
}
