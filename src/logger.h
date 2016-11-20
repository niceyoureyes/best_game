#pragma once
#include "Singleton.h"
#include <iostream>

class Logger : public Singleton<Logger>
{
public:
  template<typename T>
  Logger & operator << (T const & val)
  {
    std::cout << val;
    return *this;
  }
private:
  friend class Singleton<Logger>;
  Logger() = default;
};
