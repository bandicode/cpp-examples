
#include <iostream> // cout
#include <memory>

struct Object
{
  int n;

  Object(int val)
    : n(val)
  {
    std::cout << "Object constructed\n";
  }

  ~Object()
  {
    std::cout << "Object destroyed\n";
  }
};

int main() 
{
  // allocated memory buffer
  std::unique_ptr<char[]> buffer{ new char[sizeof(Object)] };

  // construct Object in buffer using placement-new
  new (buffer.get()) Object(42);

  // get pointer to & use Object
  Object* obj = reinterpret_cast<Object*>(buffer.get());
  std::cout << obj->n << "\n";

  // destroy Object
  obj->~Object();

  // reuse buffer
  new (buffer.get()) Object(7);
  std::cout << obj->n << "\n";
  obj->~Object();
}
