
#include <cassert> // assert
#include <iomanip> // quoted
#include <iostream> // cout
#include <memory> // shared_ptr, weak_ptr

struct Resource
{
  std::string name;

  explicit Resource(const std::string& n)
    : name(n)
  {
    std::cout << "Resource " << std::quoted(name) << " constructed\n";
  }

  ~Resource()
  {
    std::cout << "Resource " << std::quoted(name) <<  " destroyed\n";
  }

  Resource(const Resource&) = delete;
  Resource& operator=(const Resource&) = delete;
};

std::shared_ptr<Resource> acquireResource()
{
  auto r = std::make_shared<Resource>("external-resource");
  return r;
}

int main() 
{
  {
    std::shared_ptr<Resource> r{ new Resource("shared-resource-1") };
    /* ... */
    // shared_ptr automatically destroys the resource
  }

  std::shared_ptr<Resource> r;

  {
    std::shared_ptr<Resource> r2{ new Resource("shared-resource-2") };
    r = r2;
    // resource "shared-resource-2" is going to outlive the scope of r2
  }

  // create a weak-reference to "shared-resource-2"
  std::weak_ptr<Resource> weak = r;

  {
    // check if "shared-resource-2" has expired
    assert(!weak.expired());

    // turns the weak-reference into a strong-reference
    std::shared_ptr<Resource> r2 = weak.lock();
    assert(r2 != nullptr);
  }

  {
    // rebind r to another resource
    // this will destroy "shared-resource-2"
    r = acquireResource();
  }

  {
    // expired ?
    assert(weak.expired());

    std::shared_ptr<Resource> r2 = weak.lock();
    assert(r2 == nullptr);
  }
}
