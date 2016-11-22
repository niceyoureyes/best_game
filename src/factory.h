#include <iostream>

class Factory
{
public:
  template<typename T, typename...Args>
  static T * Create(Args...args)
  {
    return new T(args...);
  }
};
