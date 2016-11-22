#include <iostream>
#include <memory>

class Factory
{
public:
  template<typename T, typename...Args>
  static std::unique_ptr<T> Create(Args...args)
  {
    return std::unique_ptr<T>(new T(args...));
  }
};
