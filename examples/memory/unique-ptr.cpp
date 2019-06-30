
#include <cassert> // assert
#include <cstdlib> // atexit
#include <iomanip> // quoted
#include <iostream> // cout
#include <memory> // unique_ptr
#include <utility> // move

static int num_resources = 0;

void atexit_handler()
{
  if (num_resources != 0)
  {
    std::cout << "Warning: some resources have leaked!\n";
  }
}

struct Resource
{
  std::string name;

  explicit Resource(const std::string& n)
    : name(n)
  {
    std::cout << "Resource " << std::quoted(name) << " constructed\n";
    ++num_resources;
  }

  ~Resource()
  {
    std::cout << "Resource " << std::quoted(name) <<  " destroyed\n";
    --num_resources;
  }

  Resource(const Resource&) = delete;
  Resource& operator=(const Resource&) = delete;
};

std::unique_ptr<Resource> acquireResource()
{
  auto r = std::make_unique<Resource>("external-resource");
  return r;
}

int main() 
{
  std::atexit(atexit_handler);

  {
    Resource* r = new Resource("manual new");
    /* ... */
    delete r; // resource must be explicitely deleted !
  }

  {
    std::unique_ptr<Resource> r{ new Resource("unique-ptr") };
    /* ... */
    // unique_ptr automatically destroys the resource
  }

  {
    std::unique_ptr<Resource> r1 = acquireResource();
    std::unique_ptr<Resource> r2;

    // r1 = r2; // does not compile, unique_ptr cannot be copied

    // std::move can be used to transfer ownership
    r2 = std::move(r1);

    assert(r1 == nullptr);
  }
}
