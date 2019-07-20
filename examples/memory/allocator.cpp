
#include <cstddef>
#include <new>
#include <vector>
#include <iostream>

template<typename T>
struct DebugAllocator
{
  typedef T value_type;

  DebugAllocator() = default;

  template<typename U>
  DebugAllocator(const DebugAllocator<U>&) { }

  T* allocate(size_t n)
  {
    size_t byte_count = n * sizeof(T);
    std::cout << "Allocating " << n << " " << typeid(T).name()
      << " (" << byte_count << " bytes)\n";
    return static_cast<T*>(::operator new(byte_count));
  }

  void deallocate(T* p, size_t n)
  {
    size_t byte_count = n * sizeof(T);
    std::cout << "Deallocating " << n << " " << typeid(T).name()
      << " (" << byte_count << " bytes)\n";
    ::operator delete(p);
  }
};

template <class T, class U>
bool operator==(const DebugAllocator<T>&, const DebugAllocator<U>&) { return true; }
template <class T, class U>
bool operator!=(const DebugAllocator<T>&, const DebugAllocator<U>&) { return false; }

int main()
{
  // Define an allocator for integers
  using IntAllocator = DebugAllocator<int>;

  // Obtain from an existing allocator an allocator for a different type
  using CharAllocator = std::allocator_traits<IntAllocator>::rebind_alloc<char>;

  /* Use a CharAllocator to allocate a string */

  CharAllocator allocator;
  char* c = allocator.allocate(6);
  c[0] = 'H', c[1] = 'e', c[2] = 'l', c[3] = 'l', c[4] = 'o', c[5] = '\0';
  std::cout << c << std::endl;
  allocator.deallocate(c, 6);
  
  /* Diagnostic std::vector allocation policy */

  const int sz = 100;
  std::vector<int, IntAllocator> vec;

  for (int i(0); i < sz; ++i)
  {
    vec.push_back(i);
  }
}
