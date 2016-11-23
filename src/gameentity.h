#pragma once
#include <typeinfo>
#include <iostream>
#include "logger.h"

class GameEntity
{
public:
  virtual ~GameEntity()
  {
    Logger::Instance() << "Destructor " << *this;
  }

  friend std::ostream & operator << (std::ostream & os, GameEntity const & obj)
  {
    os << typeid(obj).name() << std::endl;
    return os;
  }
};
