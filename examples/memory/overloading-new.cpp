
#include <new>
#include <iostream>

struct X 
{
  int x = 0;

  X()
  {
    std::cout << "Constructing X\n";
  }

  ~X()
  {
    std::cout << "Destroying X\n";
  }

  static void* operator new(std::size_t sz) 
  {
    std::cout << "Allocating X (" << sz << " bytes)\n";
    return ::operator new(sz);
  }

  static void operator delete(void* ptr)
  {
    std::cout << "Deallocating X\n";
    ::operator delete(ptr);
  }
};

int main() 
{
  {
    X x;
  }

  {
    X* x = new X;
    delete x;
  }
}
